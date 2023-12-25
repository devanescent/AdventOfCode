#pragma once
#include <string>
#include <vector>
#include <functional>

namespace AdventOfCode::Year2023::Day25
{
	class Wiring
	{
	public:
		std::string Comp1;
		std::string Comp2;

		bool operator==(const Wiring& other) const
		{
			// Order of connected components does not matter:
			return Comp1 == other.Comp1 && Comp2 == other.Comp2 ||
				   Comp1 == other.Comp2 && Comp2 == other.Comp1;
		}
	};
}
