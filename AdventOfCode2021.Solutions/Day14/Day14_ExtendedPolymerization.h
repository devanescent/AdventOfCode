#pragma once
#include "DayTC.h"
#include "PolymerProcessor.h"

namespace AdventOfCode::Year2021::Day14
{
	class ExtendedPolymerization : public DayTC<PolymerRule, std::string, PolymerProcessor>
	{
	public:
		ExtendedPolymerization();

	protected:
		uint64_t ExecutePart1(std::vector<PolymerRule> rules, std::string polymerTemplate) override;
		uint64_t ExecutePart2(std::vector<PolymerRule> rules, std::string polymerTemplate) override;

	private:
		uint64_t ApplyPolymerization(const std::string& polymerTemplate, std::vector<PolymerRule>& rules, int count);
	};
}