#pragma once

namespace AdventOfCode::Year2017::Day24
{
	class MagneticComponent
	{
	public:
		int ID;
		int Port1, Port2;

		int GetStrength() const { return Port1 + Port2; }

		auto operator<=>(const MagneticComponent& other) const = default;
	};

	struct BridgeStrength
	{
		uint64_t Strength = 0;
		uint64_t Length = 0;
	};
}
