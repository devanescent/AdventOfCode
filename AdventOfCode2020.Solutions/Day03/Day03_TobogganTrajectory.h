#pragma once
#include "Day.h"

namespace AdventOfCode::Year2020::Day03
{
	class TobogganTrajectory : public Day
	{
	public:
		TobogganTrajectory(int routeX, int routeY);

		uint64_t GetResultOnPart1(std::vector<std::string> mapData) override;

	private:
		const char TREE = '#';

		int m_routeX;
		int m_routeY;
	};
}