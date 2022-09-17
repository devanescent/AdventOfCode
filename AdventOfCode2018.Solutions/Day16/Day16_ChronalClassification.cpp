#include "Day16_ChronalClassification.h"
#include <algorithm>
#include <map>
#include <set>

namespace AdventOfCode::Year2018::Day16
{
	ChronalClassification::ChronalClassification() : DayT(16, "Chronal Classification") {}

	uint64_t ChronalClassification::ExecutePart1(std::vector<ComputationSample> samples)
	{
		return std::count_if(samples.begin(), samples.end(), [](const auto& sample) { return sample.GetValidOpCodes().size() >= 3; });
	}
}