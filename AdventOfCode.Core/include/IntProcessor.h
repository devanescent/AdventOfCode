#pragma once
#include "InputProcessor.h"

namespace AdventOfCode
{
	enum class IntProcessingMode
	{
		ValuePerLine,					// one value per line
		ValuesAsCommaSeparatedLine,		// all values as one comma-separated line
		ValuesAsSpaceSeparatedLine,		// all values as one space-separated line
		ValuesAsDigits					// each digit is a value on its own
	};

	template <IntProcessingMode ProcessingMode>
	class IntProcessor : public InputProcessorBase<int>
	{
	public:
		std::vector<int> Process(std::vector<std::string> input) override;
	};

	class IntArrayProcessor : public InputProcessorBase<std::vector<int>>
	{
	public:
		std::vector<std::vector<int>> Process(std::vector<std::string> input) override;
	};

	template<> std::vector<int> IntProcessor<IntProcessingMode::ValuePerLine>::Process(std::vector<std::string> input);
	template<> std::vector<int> IntProcessor<IntProcessingMode::ValuesAsCommaSeparatedLine>::Process(std::vector<std::string> input);
	template<> std::vector<int> IntProcessor<IntProcessingMode::ValuesAsSpaceSeparatedLine>::Process(std::vector<std::string> input);
	template<> std::vector<int> IntProcessor<IntProcessingMode::ValuesAsDigits>::Process(std::vector<std::string> input);
}