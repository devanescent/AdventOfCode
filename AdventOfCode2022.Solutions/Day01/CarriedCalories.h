#pragma once
#include <vector>
#include <numeric>

namespace AdventOfCode::Year2022::Day01
{
	class CarriedCalories
	{
	private:
		std::vector<int> m_calories;

	public:
		void AddCalories(int calories)
		{
			m_calories.emplace_back(calories);
		}

		int GetTotalCalories() const
		{
			return std::accumulate(m_calories.begin(), m_calories.end(), 0);
		}
	};
}
