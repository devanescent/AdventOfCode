#pragma once
#include "InputProcessor.h"
#include "SnailfishNum.h"

namespace AdventOfCode::Year2021::Day18
{
	class SnailfishNumberProcessor : public InputProcessorBase<std::unique_ptr<SnailfishNum>>
	{
	public:
		std::vector<std::unique_ptr<SnailfishNum>> Process(std::vector<std::string> input) override;

	private:
		std::unique_ptr<SnailfishNum> MakeSnailFishNum(const std::string& number, int& ix, SnailfishNum* parent, SnailfishNum::ChildPos posInParent);
	};
}
