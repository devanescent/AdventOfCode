#pragma once
#include "InputProcessor.h"

namespace AdventOfCode
{
	enum class IntProcessingMode
	{
		ValuePerLine,			// one value per line / string
		ValuesAsSingleLine,		// all values as one comma-separated string
		ValuesAsDigits			// each digit is a value on its own
	};

	template <IntProcessingMode ProcessingMode>
	class IntProcessor : public InputProcessorBase<int>
	{
	public:
		std::vector<int> Process(std::vector<std::string> input) override;
	};


	template<> std::vector<int> IntProcessor<IntProcessingMode::ValuePerLine>::Process(std::vector<std::string> input);
	template<> std::vector<int> IntProcessor<IntProcessingMode::ValuesAsSingleLine>::Process(std::vector<std::string> input);
	template<> std::vector<int> IntProcessor<IntProcessingMode::ValuesAsDigits>::Process(std::vector<std::string> input);
}