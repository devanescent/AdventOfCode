#pragma once
#include <vector>

namespace AdventOfCode::Year2020::Day08
{
	class ExecutionContext
	{
	public:
		void ChangeAccumulator(int val)
		{
			m_accumulator += val;
		}

		int GetAccumulator() { return m_accumulator; }

		void SetInstructionAsExecuted(int instrIndex)
		{
			m_executedInstructions.push_back(instrIndex);
		}

		bool HasBeenExecuted(int instrIndex)
		{
			return std::find(m_executedInstructions.begin(), m_executedInstructions.end(), instrIndex) != m_executedInstructions.end();
		}


	private:
		int m_accumulator = 0;
		std::vector<int> m_executedInstructions;
	};
}
