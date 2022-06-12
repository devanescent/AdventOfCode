#pragma once
#include "DayT.h"
#include "HydroVentProcessor.h"
#include <functional>

namespace AdventOfCode::Year2021::Day05
{
	class HydrothermalVenture : public DayT<HydroVentProcessor>
	{
	public:
		HydrothermalVenture();

	protected:
		uint64_t ExecutePart1(std::vector<HydroVentLine> vents) override;
		uint64_t ExecutePart2(std::vector<HydroVentLine> vents) override;

	private:
		uint64_t GetNumberOfIntersections(const std::vector<HydroVentLine>& vents, std::function<bool(const HydroVentLine&)> pred);
	};
}