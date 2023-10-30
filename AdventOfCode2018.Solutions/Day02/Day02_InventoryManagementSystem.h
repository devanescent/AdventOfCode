#pragma once
#include "Day.h"

namespace AdventOfCode::Year2018::Day02
{
	// ---------------------------------------------------------------------------
	// Day02: Inventory Management System 
	// ---------------------------------------------------------------------------
	class InventoryManagementSystem : public Day<>
	{
	public:
		InventoryManagementSystem();

	protected:
		uint64_t ExecutePart1(const std::vector<std::string> input) override;
		uint64_t ExecutePart2(const std::vector<std::string> input) override;
	};
}