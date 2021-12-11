#include "Day11_DumboOctopus.h"

namespace AdventOfCode::Year2021::Day11
{
	DumboOctopus::DumboOctopus() : DayT(11, "Dumbo Octopus") {}

	uint64_t DumboOctopus::ExecutePart1(std::vector<std::vector<int>> octopuses)
	{
		uint64_t totalFlashes = 0;
		for (int n = 0; n < 100; ++n)
		{
			// Update energy levels:
			for (int y = 0; y < octopuses.size(); ++y)
			{
				for (int x = 0; x < octopuses[y].size(); ++x)
				{
					int& octo = octopuses[y][x];
					if (octo < 10)
					{
						// Increase energy level
						++octo;

						// Is flashing?
						if (octo == 10)
							Flash(octopuses, x, y);
					}
				}
			}

			// Set energy to 0 if octopus flashed:
			int flashesThisTurn = 0;
			for (int y = 0; y < octopuses.size(); ++y)
			{
				for (int x = 0; x < octopuses[y].size(); ++x)
				{
					int& octo = octopuses[y][x];
					if (octo == 10)
					{
						octo = 0;
						++flashesThisTurn;
					}
				}
			}

			totalFlashes += flashesThisTurn;
		}

		return totalFlashes;
	}

	uint64_t DumboOctopus::ExecutePart2(std::vector<std::vector<int>> octopuses)
	{
		int flashesThisTurn = 0;
		uint64_t turn = 0;

		while (flashesThisTurn < 100)
		{
			++turn;
			flashesThisTurn = 0;

			// Update energy levels:
			for (int y = 0; y < octopuses.size(); ++y)
			{
				for (int x = 0; x < octopuses[y].size(); ++x)
				{
					int& octo = octopuses[y][x];
					if (octo < 10)
					{
						// Increase energy level
						++octo;

						// Is flashing?
						if (octo == 10)
							Flash(octopuses, x, y);
					}
				}
			}


			// Set energy to 0 if octopus flashed:
			for (int y = 0; y < octopuses.size(); ++y)
			{
				for (int x = 0; x < octopuses[y].size(); ++x)
				{
					int& octo = octopuses[y][x];
					if (octo == 10)
					{
						octo = 0;
						++flashesThisTurn;
					}
				}
			}
		}

		return turn;
	}

	// Lets an octopus flash
	void DumboOctopus::Flash(std::vector<std::vector<int>>& octopuses, int octoX, int octoY)
	{
		for (int y = octoY - 1; y <= octoY + 1; ++y)
		{
			for (int x = octoX - 1; x <= octoX + 1; ++x)
			{
				// Check bounds and not self:
				if (y >= 0 && x >= 0 && y < octopuses.size() && x < octopuses[y].size() && (x != octoX || y != octoY))
				{
					int& adjacentOcto = octopuses[y][x];
					if (adjacentOcto < 10)
					{
						++adjacentOcto;

						// Is flashing?
						if (adjacentOcto == 10)
							Flash(octopuses, x, y);
					}
				}
			}
		}

	}
}


