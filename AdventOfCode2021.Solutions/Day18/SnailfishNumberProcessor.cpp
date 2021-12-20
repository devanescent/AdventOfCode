#include "SnailfishNumberProcessor.h"
#include <algorithm>

namespace AdventOfCode::Year2021::Day18
{
	std::vector<std::unique_ptr<SnailfishNum>> SnailfishNumberProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::unique_ptr<SnailfishNum>> nums;

		for (const std::string& number : input)
		{
			int ix = 1;
			nums.emplace_back(MakeSnailFishNum(number, ix, nullptr, SnailfishNum::ChildPos::Undefined));
		}

		return nums;
	}

	std::unique_ptr<SnailfishNum> SnailfishNumberProcessor::MakeSnailFishNum(const std::string & number, int & ix, SnailfishNum * parent, SnailfishNum::ChildPos posInParent)
	{
		// new pair:
		auto num = std::make_unique<SnailfishNum>();
		if (parent)
		{
			num->Parent = parent;
			num->PosInParent = posInParent;
			num->Depth = parent->Depth + 1;
		}

		// Left element:
		if (number[ix] == '[')
		{
			++ix; // opening '['
			num->Left = MakeSnailFishNum(number, ix, num.get(), SnailfishNum::ChildPos::LeftChild);
			++ix; // closing ']'
		}
		else
		{
			size_t numLen;
			num->Left = std::stoi(number.substr(ix), &numLen);
			ix += static_cast<int>(numLen);
		}

		++ix;	// comma

		// Right element:
		if (number[ix] == '[')
		{
			++ix; // opening '['
			num->Right = MakeSnailFishNum(number, ix, num.get(), SnailfishNum::ChildPos::RightChild);
			++ix; // closing ']'
		}
		else
		{
			size_t numLen;
			num->Right = std::stoi(number.substr(ix), &numLen);
			ix += static_cast<int>(numLen);
		}

		return num;
	}
}