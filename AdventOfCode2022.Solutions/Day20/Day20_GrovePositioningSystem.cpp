#include "Day20_GrovePositioningSystem.h"
#include <algorithm>
#include <list>

namespace AdventOfCode::Year2022::Day20
{
	GrovePositioningSystem::GrovePositioningSystem() : DayT(20, "Grove Positioning System") { }

	auto MoveForward = [](const std::list<int64_t>& mixedElements, std::list<int64_t>::const_iterator it, size_t steps)
	{
		auto newPos = it;
		for (auto i = 0; i < steps; ++i)
		{
			// Check for wrap-around:
			if (newPos == mixedElements.end())
			{
				newPos = mixedElements.begin();
				++newPos;
			}
			else
			{
				++newPos;
				if (newPos == mixedElements.end())
					newPos = mixedElements.begin();
			}
		}
		return newPos;
	};

	auto MoveBackward = [](const std::list<int64_t>& mixedElements, std::list<int64_t>::const_iterator it, size_t steps)
	{
		auto newPos = it;
		for (auto i = 0; i < steps; ++i)
		{
			// Check for wrap-around:
			if (newPos == mixedElements.begin())
			{
				newPos = mixedElements.end();
				--newPos;
			}
			else
			{
				--newPos;
				if (newPos == mixedElements.begin())
					newPos = mixedElements.end();
			}
		}
		return newPos;
	};

	void Mixing(std::vector<std::list<int64_t>::iterator>& initialOrder, std::list<int64_t>& mixedElements)
	{
		// Move each element:
		for (auto& listIt : initialOrder)
		{
			// Value to be moved:
			int64_t value = *listIt;

			// Remove from list to start moving:
			std::list<int64_t>::const_iterator newPos = mixedElements.erase(listIt);

			if (value > 0)
			{
				// Move forward:
				size_t shiftForward = value % mixedElements.size();
				if (shiftForward < mixedElements.size() / 2)
					newPos = MoveForward(mixedElements, newPos, shiftForward);
				else
				{
					size_t shiftBackward = mixedElements.size() - shiftForward;
					newPos = MoveBackward(mixedElements, newPos, shiftBackward);
				}
			}
			else
			{
				// Move backward:
				size_t shiftBackward = std::abs(value) % mixedElements.size();
				if (shiftBackward < mixedElements.size() / 2)
					newPos = MoveBackward(mixedElements, newPos, shiftBackward);
				else
				{
					size_t shiftForward = mixedElements.size() - shiftBackward;
					newPos = MoveForward(mixedElements, newPos, shiftForward);
				}
			}

			// Update iterator in order after re-inserting:
			listIt = mixedElements.insert(newPos, value);
		}
	}

	uint64_t GetGroveCoordinates(const std::list<int64_t>& mixedElements)
	{
		// Find sum of the 1000th, 2000th and 3000th element after the element 0:
		auto it = std::find(mixedElements.begin(), mixedElements.end(), 0);
		int64_t sum = 0;

		for (int i = 0; i < 3; ++i)
		{
			it = MoveForward(mixedElements, it, 1000);
			sum += *it;
		}

		return static_cast<uint64_t>(sum);
	}

	uint64_t GrovePositioningSystem::ExecutePart1(std::vector<int> nums)
	{
		// Create list of all values for better inserting:
		std::list<int64_t> mixedElements(nums.begin(), nums.end());

		// Preserve original order of values:
		std::vector<std::list<int64_t>::iterator> origOrder;
		for (auto listIt = mixedElements.begin(); listIt != mixedElements.end(); ++listIt)
			origOrder.push_back(listIt);

		// Execute mixing:
		Mixing(origOrder, mixedElements);

		// Grove coordinates:
		return GetGroveCoordinates(mixedElements);
	}

	uint64_t GrovePositioningSystem::ExecutePart2(std::vector<int> nums)
	{
		// Create list of all values for better inserting:
		std::list<int64_t> mixedElements;

		// Apply the decryption key to the values:
		std::transform(nums.begin(), nums.end(), std::inserter(mixedElements, mixedElements.end()),
			[](int num) { return static_cast<int64_t>(num) * 811'589'153ll; }
		);

		// Preserve original order of values:
		std::vector<std::list<int64_t>::iterator> origOrder;
		for (auto listIt = mixedElements.begin(); listIt != mixedElements.end(); ++listIt)
			origOrder.push_back(listIt);

		// Execute mixing ten times:
		for (int i = 0; i < 10; ++i)
			Mixing(origOrder, mixedElements);

		// Grove coordinates:
		return GetGroveCoordinates(mixedElements);
	}
}
