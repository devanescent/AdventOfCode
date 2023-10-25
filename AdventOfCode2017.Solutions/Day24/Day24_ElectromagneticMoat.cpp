#include "Day24_ElectromagneticMoat.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2017::Day24
{
	ElectromagneticMoat::ElectromagneticMoat() : DayT(24, "Electromagnetic Moat") { }

	bool TryAddComponent(const std::vector<MagneticComponent>& components, std::vector<MagneticComponent>& bridge, int currentEndPort, BridgeStrength& result, bool preferLongestBridge)
	{
		auto nextComp = components.begin();

		while ((nextComp = std::find_if(nextComp, components.end(),
			[&bridge, currentEndPort](const MagneticComponent& c)
			{
				if (std::find(bridge.begin(), bridge.end(), c) == bridge.end())
				{
					// Component has not been used already:
					return c.Port1 == currentEndPort || c.Port2 == currentEndPort;
				}
				else
					return false;
			})) != components.end())
		{
			bridge.push_back(*nextComp);
			if (!TryAddComponent(components, bridge, (nextComp->Port1 == currentEndPort ? nextComp->Port2 : nextComp->Port1), result, preferLongestBridge))
			{
				// no more connections possible: check bridge strength
				auto strength = std::accumulate(bridge.begin(), bridge.end(), 0ull,
					[](uint64_t totalStrength, const MagneticComponent& c)
					{
						return totalStrength + c.GetStrength();
					});

				if (!preferLongestBridge)
				{
					// only compare strengths regardless of bridge length:
					result.Strength = std::max(result.Strength, strength);
				}
				else
				{
					// If longer bridges are prefered, compare lengths also:
					if (bridge.size() == result.Length)
					{
						result.Strength = std::max(result.Strength, strength);
					}
					else if (bridge.size() > result.Length)
					{
						result.Strength = strength;
						result.Length = bridge.size();
					}
				}
			}

			bridge.pop_back();
			++nextComp;
		}

		return false;
	}

	uint64_t ElectromagneticMoat::ExecutePart1(std::vector<MagneticComponent> components)
	{
		BridgeStrength result;
		std::vector<MagneticComponent> bridge;

		TryAddComponent(components, bridge, 0, result, false);

		return result.Strength;
	}

	uint64_t ElectromagneticMoat::ExecutePart2(std::vector<MagneticComponent> components)
	{
		BridgeStrength result;
		std::vector<MagneticComponent> bridge;

		TryAddComponent(components, bridge, 0, result, true);

		return result.Strength;
	}
}
