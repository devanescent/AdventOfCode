#pragma once
#include "DayT.h"
#include "EnhancementRulesProcessor.h"
#include "Point.h"
#include <functional>

namespace AdventOfCode::Year2017::Day21
{
	// ---------------------------------------------------------------------------
	// Day21: Fractal Art
	// ---------------------------------------------------------------------------
	class FractalArt : public DayT<EnhancementRulesProcessor>
	{
	public:
		FractalArt();
		void SetIterations(int iterations) { m_iterations = iterations; }

	protected:
		uint64_t ExecutePart1(std::vector<EnhancementRule> rules) override;
		uint64_t ExecutePart2(std::vector<EnhancementRule> rules) override;

	private:
		std::vector<std::string> ProcessSubGrids(const std::vector<EnhancementRule>& rules, const std::vector<std::string>& grid, int subGridSize);

		std::vector<std::function<bool(const Point<int>&, const Point<int>&)>> m_sortFuncs;
		int m_iterations = 5;
	};
}
