#pragma once

namespace AdventOfCode::Year2020::Day13
{
	class ShuttleLine
	{
	public:
		ShuttleLine(int lineNo) :
			m_lineNo(lineNo)
		{ }

		int GetLineNo() const { return m_lineNo; }

		int GetWaitTime(int timestamp) const
		{
			if (timestamp % m_lineNo == 0)
			{
				// Departure possible now : no wait time
				return 0;
			}
			else
			{
				// find next multiple:
				int nextDeparture = ((timestamp / m_lineNo) + 1) * m_lineNo;
				return nextDeparture - timestamp;
			}
		}

		bool operator==(const ShuttleLine& other) const
		{
			return m_lineNo == other.m_lineNo;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "Line %d", m_lineNo);
			return std::string(buf);
		}

	private:
		int m_lineNo;
	};
}