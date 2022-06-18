#pragma once
#include "DayTC.h"
#include "TrenchImageProcessor.h"

namespace AdventOfCode::Year2021::Day20
{
	class TrenchMap : public DayTC<TrenchImageProcessor>
	{
	public:
		TrenchMap();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> inputImage, std::string enhancementAlgorithm) override;
		uint64_t ExecutePart2(std::vector<std::string> inputImage, std::string enhancementAlgorithm) override;

	private:
		std::vector<std::string> EnhanceImage(const std::vector<std::string>& image, const std::string& enhancementAlgorithm, bool infinityLit);
		std::uint64_t ApplyEnhancementAlgorithm(const std::vector<std::string>& inputImage, const std::string& enhancementAlgorithm, int count);
	};
}