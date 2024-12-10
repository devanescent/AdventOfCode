#include "Day08_ResonantCollinearity.h"
#include <Point.h>
#include <map>
#include <numeric>
#include <set>

namespace AdventOfCode::Year2024::Day08
{
	ResonantCollinearity::ResonantCollinearity() : DayT(8, "Resonant Collinearity") { }

	uint64_t ResonantCollinearity::ExecutePart1(GridMap map)
	{
		// Collect all antennas grouped by frequency:
		std::map<char, std::vector<Point<int>>> antennasByFreq;
		map.Transform([&antennasByFreq](int x, int y, char freq)
			{
				if (freq != '.')
					antennasByFreq[freq].emplace_back(x, y);
			});

		// Find all antinodes of each frequency
		std::set<Point<int>> antinodes;
		for (auto const& [freq, antennas] : antennasByFreq)
		{
			// Each pair of antennas produces two antinodes (one on each side):
			for (int i = 0; i < antennas.size() - 1; ++i)
			{
				for (int j = i + 1; j < antennas.size(); ++j)
				{
					Point<int> diff = antennas[i].DirectionTo(antennas[j]);
					auto antinode1 = antennas[j] + diff;
					if (map.Contains(antinode1))
						antinodes.emplace(antinode1);

					auto antinode2 = antennas[i] + (-diff);
					if (map.Contains(antinode2))
						antinodes.emplace(antinode2);
				}
			}
		}

		return antinodes.size();
	}

	uint64_t ResonantCollinearity::ExecutePart2(GridMap map)
	{
		// Collect all antennas grouped by frequency:
		std::map<char, std::vector<Point<int>>> antennasByFreq;
		map.Transform([&antennasByFreq](int x, int y, char freq)
			{
				if (freq != '.')
					antennasByFreq[freq].emplace_back(x, y);
			});

		// Find all antinodes of each frequency
		std::set<Point<int>> antinodes;
		for (const auto& [freq, antennas] : antennasByFreq)
		{
			// Each pair of antennas produces antinodes at each position on the grid in line with them:
			for (int i = 0; i < antennas.size() - 1; ++i)
			{
				for (int j = i + 1; j < antennas.size(); ++j)
				{
					Point<int> diff = antennas[i].DirectionTo(antennas[j]);
					
					// Reduce diff vector in length as much as possible:
					auto d = std::gcd(diff.X, diff.Y);
					diff.X /= d;
					diff.Y /= d;

					// Both antennas also become antinodes themselves, then search for further antinodes on the outsides:
					auto antinode = antennas[j];
					while (map.Contains(antinode))
					{
						antinodes.emplace(antinode);
						antinode = antinode + diff;
					}

					antinode = antennas[i];
					while (map.Contains(antinode))
					{
						antinodes.emplace(antinode);
						antinode = antinode + (-diff);
					}
				}
			}
		}

		return antinodes.size();
	}
}
