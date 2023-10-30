#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day18
{
	// ---------------------------------------------------------------------------
	// Day18: Settlers Of The North Pole
	// ---------------------------------------------------------------------------
	class SettlersOfTheNorthPole : public Day<>
	{
	public:
		SettlersOfTheNorthPole();

	protected:
		uint64_t ExecutePart1(std::vector<std::string> ground) override;
		uint64_t ExecutePart2(std::vector<std::string> ground) override;

	private:
		enum class AcreType : char
		{
			OpenGround = '.',
			Trees = '|',
			Lumberyard = '#'
		};
		
		std::vector<std::string> TransformGround(const std::vector<std::string>& ground);
		int GetNumberOfAdjacentAcresByType(const std::vector<std::string>& ground, size_t x, size_t y, AcreType acreType);
		uint64_t GetResourceValue(const std::vector<std::string>& ground);
	};
}