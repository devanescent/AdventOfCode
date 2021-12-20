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
			std::unique_ptr<SnailfishNum> newTotal = std::make_unique<SnailfishNum>();

			newTotal->Left = std::move(total);
			std::get<std::unique_ptr<SnailfishNum>>(newTotal->Left)->IncreaseDepth();
			std::get<std::unique_ptr<SnailfishNum>>(newTotal->Left)->Parent = newTotal.get();
			std::get<std::unique_ptr<SnailfishNum>>(newTotal->Left)->PosInParent = SnailfishNum::ChildPos::LeftChild;

			// Each element gets moved from the input vector, so it can only be used once:
			newTotal->Right = std::move(snailfishNums[n]);
			std::get<std::unique_ptr<SnailfishNum>>(newTotal->Right)->IncreaseDepth();
			std::get<std::unique_ptr<SnailfishNum>>(newTotal->Right)->Parent = newTotal.get();
			std::get<std::unique_ptr<SnailfishNum>>(newTotal->Right)->PosInParent = SnailfishNum::ChildPos::RightChild;

			newTotal->Reduce();
			total = std::move(newTotal);
		}

		return total->GetMagnitude();
	}
}
