#pragma once
#include "DayT.h"
#include "CaveConnectionProcessor.h"
#include <map>

namespace AdventOfCode::Year2021::Day12
{
	using CaveMap = std::map<std::string, std::vector<std::string>>;


	class PassagePathing : public DayT<CaveConnection, CaveConnectionProcessor>
	{
	public:
		PassagePathing();

	protected:
		uint64_t ExecutePart1(std::vector<CaveConnection> connections) override;
		uint64_t ExecutePart2(std::vector<CaveConnection> connections) override;

	private:
		uint64_t VisitCaves(const CaveMap& map, const std::string currentCave, std::vector<std::string>& pathSoFar, bool canRevisitSmallCave);
	};
}