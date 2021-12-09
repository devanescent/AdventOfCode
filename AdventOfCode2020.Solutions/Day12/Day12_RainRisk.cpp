#include "Day12_RainRisk.h"


namespace AdventOfCode::Year2020::Day12
{
	RainRisk::RainRisk(NavDirection startingDirection) : DayT(12, "Rain Risk")
	{}

	uint64_t RainRisk::ExecutePart1(std::vector<NavInstruction> navInstrs)
	{
		if (navInstrs.empty())
			return 0;

		NavigationContext navCtx(NavDirection::E);

		for (auto& navInstr : navInstrs)
			navInstr.Execute(navCtx);

		return navCtx.GetDistanceFromOrigin();
	}
}