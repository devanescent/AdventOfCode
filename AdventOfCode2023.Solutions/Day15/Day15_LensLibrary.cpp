#include "Day15_LensLibrary.h"
#include <map>
#include <numeric>

namespace AdventOfCode::Year2023::Day15
{
	LensLibrary::LensLibrary() : DayT(15, "Lens Library") { }

	int CalcHASH(const std::string& str)
	{
		int HASH = 0;
		for (char c : str)
		{
			HASH += static_cast<int>(c);
			HASH *= 17;
			HASH %= 256;
		}
		return HASH;
	}

	uint64_t LensLibrary::ExecutePart1(std::vector<std::string> initSteps)
	{
		return std::accumulate(initSteps.begin(), initSteps.end(), 0ull,
			[](uint64_t sum, const std::string& initStep)
			{
				return sum + CalcHASH(initStep);
			});
	}

	uint64_t LensLibrary::ExecutePart2(std::vector<std::string> initSteps)
	{
		struct Lens
		{
			std::string Label;
			int FocalLength;
		};

		// Lists lenses in boxes
		std::map<int, std::vector<Lens>> boxes;

		for (const std::string& initStep : initSteps)
		{
			auto dashIndex = initStep.find('-');
			if (dashIndex != std::string::npos)
			{
				// Remove lens with this label from its box:
				std::string label = initStep.substr(0, dashIndex);
				int boxNo = CalcHASH(label);
				std::erase_if(boxes[boxNo], [&label](const auto& lens) { return lens.Label == label; });
			}
			else
			{
				auto equalIndex = initStep.find('=');
				std::string label = initStep.substr(0, equalIndex);
				int focalLength = std::stoi(initStep.substr(equalIndex + 1));

				int boxNo = CalcHASH(label);
				auto& lenses = boxes[boxNo];

				// Check if lens with this label already exists:
				auto lensIt = std::find_if(lenses.begin(), lenses.end(), [&label](const Lens& lens) {return lens.Label == label; });
				if (lensIt != lenses.end())
				{
					// Replace lens:
					lensIt->FocalLength = focalLength;
				}
				else
				{
					// Otherwise, add lens:
					lenses.emplace_back(label, focalLength);
				}
			}
		}

		// Total focusing power:
		return std::accumulate(boxes.begin(), boxes.end(), 0ull,
			[](uint64_t total, const auto& box)
			{
				// For each lens in box: Multiply (box no + 1), lens slot (1..N), focal length:
				for (int i = 1; i <= box.second.size(); ++i)
					total += (box.first + 1) * i * (box.second[i - 1].FocalLength);

				return total;
			});	
	}
}
