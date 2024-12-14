#pragma once
#include "DayT.h"
#include "RobotProcessor.h"

namespace AdventOfCode::Year2024::Day14
{
	// ---------------------------------------------------------------------------
	// Day14: Restroom Redoubt
	// ---------------------------------------------------------------------------
	class RestroomRedoubt : public DayT<RobotProcessor>
	{
	public:
		RestroomRedoubt();
		void SetArea(int width, int height)
		{
			_areaWidth = width;
			_areaHeight = height;
		}

	protected:
		uint64_t ExecutePart1(std::vector<Robot> robots) override;
		uint64_t ExecutePart2(std::vector<Robot> robots) override;

	private:
		int _areaWidth = 101;
		int _areaHeight = 103;
	};
}
