#pragma once

namespace AdventOfCode::Year2022::Day01
{
	class CarriedCalories
	{
	private:
		int m_totalCalories = 0;

	public:
		void AddCalories(int calories)
		{
			m_totalCalories += calories;
		}

		int GetTotalCalories() const
		{
			return m_totalCalories;
		}
	};
}
