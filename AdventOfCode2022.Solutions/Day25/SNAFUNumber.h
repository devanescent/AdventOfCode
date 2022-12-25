#pragma once

namespace AdventOfCode::Year2022::Day25
{
	class SNAFUNumber
	{
	public:
		SNAFUNumber(int64_t val) : m_value(val) {}
		int64_t Value() const { return m_value; }

	private:
		int64_t m_value;
	};
}
