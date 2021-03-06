#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day02
{
	// ---------------------------------------------------------------------------
	// Day02: Inventory Management System 
	// ---------------------------------------------------------------------------
	class InventoryManagementSystem : public Day
	{
	public:
		InventoryManagementSystem();

		uint64_t GetResultOnPart1(const std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(const std::vector<std::string> input) override;
	};
}