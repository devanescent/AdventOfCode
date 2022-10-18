#include "Day12_RainRisk.h"


namespace AdventOfCode::Year2020::Day12
{
	RainRisk::RainRisk() : DayT(12, "Rain Risk") {}

	uint64_t RainRisk::ExecutePart1(std::vector<NavInstruction> navInstrs)
	{
		NavigationContext navCtx(NavDirection::E);

		for (auto& navInstr : navInstrs)
			navInstr.Execute(navCtx);

		return navCtx.GetDistanceFromOrigin();
	}

	uint64_t RainRisk::ExecutePart2(std::vector<NavInstruction> navInstrs)
	{
		NavigationWaypointContext navCtx(-1, 10);

		for (auto& navInstr : navInstrs)
			navInstr.Execute(navCtx);

		return navCtx.GetDistanceFromOrigin();
	}
}