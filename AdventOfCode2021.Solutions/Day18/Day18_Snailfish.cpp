#include "Day18_Snailfish.h"
#include <numeric>
#include <algorithm>

namespace AdventOfCode::Year2021::Day18
{
	Snailfish::Snailfish() : DayT(18, "Snailfish") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t Snailfish::ExecutePart1(std::vector<std::unique_ptr<SnailfishNum>> snailfishNums)
	{
		/*std::accumulate(snailfishNums.begin() + 1, snailfishNums.end(), snailfishNums[0],
			[](auto& snailFish )*/

		std::unique_ptr<SnailfishNum> total = std::move(snailfishNums[0]);
		for (int n = 1; n < snailfishNums.size(); ++n)
		{
			total = AddSnailfishNums(std::move(total), std::move(snailfishNums[n]));
		}

		return total->GetMagnitude();
	}

	// ---------------------------------------------------------------------------
	// Part 2:
	// ---------------------------------------------------------------------------
	uint64_t Snailfish::GetResultOnPart2(const std::vector<std::string> input)
	{
		uint64_t maxMagnitude = 0;
		
		for (int d = 1; d < input.size(); ++d)
		{
			// During computation, each element gets moved from the input vector, so it can only be used once:
			std::vector<std::unique_ptr<SnailfishNum>> snailfishNums = m_proc.Process(input);
			std::vector<std::unique_ptr<SnailfishNum>> snailfishNumsCopy = m_proc.Process(input);

			// For each element from the first vector, use the element from the second vector with distance d:
			// By varying the distance d, each element gets eventually combined with every other element
			for (int n = 0; n < input.size(); ++n)
			{
				auto addedNums = AddSnailfishNums(std::move(snailfishNums[n]), std::move(snailfishNumsCopy[(n + d) % (input.size())]));
				maxMagnitude = std::max(maxMagnitude, addedNums->GetMagnitude());
			}
		}

		return maxMagnitude;
	}

	// ---------------------------------------------------------------------------
	// AddSnailfishNums
	// ---------------------------------------------------------------------------
	std::unique_ptr<SnailfishNum> Snailfish::AddSnailfishNums(std::unique_ptr<SnailfishNum> num1, std::unique_ptr<SnailfishNum> num2)
	{
		std::unique_ptr<SnailfishNum> numNum = std::make_unique<SnailfishNum>();

		numNum->Left = std::move(num1);
		std::get<std::unique_ptr<SnailfishNum>>(numNum->Left)->IncreaseDepth();
		std::get<std::unique_ptr<SnailfishNum>>(numNum->Left)->Parent = numNum.get();
		std::get<std::unique_ptr<SnailfishNum>>(numNum->Left)->PosInParent = SnailfishNum::ChildPos::LeftChild;

		// Each element gets moved from the input vector, so it can only be used once:
		numNum->Right = std::move(num2);
		std::get<std::unique_ptr<SnailfishNum>>(numNum->Right)->IncreaseDepth();
		std::get<std::unique_ptr<SnailfishNum>>(numNum->Right)->Parent = numNum.get();
		std::get<std::unique_ptr<SnailfishNum>>(numNum->Right)->PosInParent = SnailfishNum::ChildPos::RightChild;

		numNum->Reduce();
		return numNum;
	}
}
