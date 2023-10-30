#include "Day11_ChronalCharge.h"
#include <algorithm>

namespace AdventOfCode::Year2018::Day11
{
	template<typename T>
	class Array2D
	{
	private:
		size_t m_xSize;
		size_t m_ySize;
		std::vector<T> m_array;

		// Proxy for accessing grid coordinates via "Array2D[x][y]"
		class Array2DCol
		{
		public:
			Array2DCol(typename std::vector<T>::iterator col) : m_col(col) {}

			T& operator[](size_t y)
			{
				return *(m_col + y);
			}

		private:
			typename std::vector<T>::iterator m_col;
		};

	public:
		Array2D(size_t xSize, size_t ySize, T initialValue) :
			m_xSize(xSize), m_ySize(ySize), m_array(xSize* ySize, initialValue)
		{}

		Array2DCol operator[](size_t x)
		{
			return Array2DCol(m_array.begin() + (x * m_ySize));
		}
	};


	ChronalCharge::ChronalCharge() : Day(11, "Chronal Charge")
	{}

	std::string ChronalCharge::ExecutePart1(const std::vector<std::string> input)
	{
		int gridId = atoi(input[0].c_str());

		int maxTotalPower = 0;
		std::pair<int, int> maxPowerLocation;

		// Fill array with values:
		Array2D<int> grid(300, 300, 0);
		for (int x = 0; x < 300; ++x)
		{
			for (int y = 0; y < 300; ++y)
			{
				// Calculate power level for this cell:
				int powerLvl = ((((x + 10) * y + gridId) * (x + 10) / 100) % 10) - 5;
				
				// Build summed-area table:
				grid[x][y] = powerLvl
					+ (x > 0 ? grid[x - 1][y] : 0)
					+ (y > 0 ? grid[x][y - 1] : 0)
					- (x > 0 && y > 0 ? grid[x - 1][y - 1] : 0);

				// Keep track of maximum, after at least a 3x3 area has been calculated:
				if (x >= 2 && y >= 2)
				{
					int totalPower = grid[x][y]
						- (x > 2 ? grid[x - 3][y] : 0)
						- (y > 2 ? grid[x][y - 3] : 0)
						+ (x > 2 && y > 2 ? grid[x - 3][y - 3] : 0);

					if (totalPower > maxTotalPower)
					{
						maxTotalPower = totalPower;
						maxPowerLocation = std::make_pair(x - 2, y - 2);
					}
				}

			}
		}

		return std::to_string(maxPowerLocation.first) + "," + std::to_string(maxPowerLocation.second);
	}

	std::string ChronalCharge::ExecutePart2(const std::vector<std::string> input)
	{
		int gridId = atoi(input[0].c_str());

		int maxTotalPower = 0;
		std::pair<int, int> maxPowerLocation;
		int sqaureSize = 0;

		// Fill array with values:
		Array2D<int> grid(300, 300, 0);
		for (int x = 0; x < 300; ++x)
		{
			for (int y = 0; y < 300; ++y)
			{
				// Calculate power level for this cell:
				int powerLvl = ((((x + 10) * y + gridId) * (x + 10) / 100) % 10) - 5;

				// Build summed-area table:
				grid[x][y] = powerLvl
					+ (x > 0 ? grid[x - 1][y] : 0)
					+ (y > 0 ? grid[x][y - 1] : 0)
					- (x > 0 && y > 0 ? grid[x - 1][y - 1] : 0);

				// Keep track of maximum for possible sqaure sizes at this point:
				for (int s = 1; s <= std::min(x + 1, y + 1); s++)
				{
					int totalPower = grid[x][y]
						- (x >= s ? grid[x - s][y] : 0)
						- (y >= s ? grid[x][y - s] : 0)
						+ (x >= s && y >= s ? grid[x - s][y - s] : 0);

					if (totalPower > maxTotalPower)
					{
						maxTotalPower = totalPower;
						maxPowerLocation = std::make_pair(x - s + 1, y - s + 1);
						sqaureSize = s;
					}
				}

			}
		}

		return std::to_string(maxPowerLocation.first) + "," + std::to_string(maxPowerLocation.second) + "," + std::to_string(sqaureSize);
	}
}
