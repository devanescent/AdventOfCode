#pragma once
#include <algorithm>
#include <set>

namespace AdventOfCode::Year2018::Day07
{
	class AssemblyStep {
	public:
		AssemblyStep(char id) : m_id(id)
		{}

		bool operator<(const AssemblyStep& other) const
		{
			return m_id < other.m_id;
		}

		char ID() const { return m_id; }

		void AddPrecondition(char stepId)
		{
			m_preConditions.insert(stepId);
		}

		bool CheckPreconditions(const std::string& fulfilledConds) const
		{
			return std::all_of(m_preConditions.begin(), m_preConditions.end(), 
				[&fulfilledConds](char c) { return fulfilledConds.find(c) != std::string::npos; }
			);
		}

	private:
		char m_id;
		std::set<char> m_preConditions;
	};
}