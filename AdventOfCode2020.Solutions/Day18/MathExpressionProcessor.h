#pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2020::Day18
{
	class MathExpressionProcessor : public InputProcessorBase<std::string>
	{
	public:
		std::vector<std::string> Process(std::vector<std::string> input) override;

	private:
		// Converts a mathematical expression from infix to postfix notation
		std::string Convert(const std::string& expression);
	};

}

