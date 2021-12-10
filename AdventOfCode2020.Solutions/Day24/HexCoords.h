#pragma once
#include <string>

namespace AdventOfCode::Year2020::Day24
{
	class HexCoords
	{
	public:
		HexCoords(int swne, int nwse) :
			m_swne(swne), m_nwse(nwse)
		{}

		// for using as key in map
		bool operator<(const HexCoords& rhs) const
		{
			if (m_swne != rhs.m_swne)
				return m_swne < rhs.m_swne;
			else
				return m_nwse < rhs.m_nwse;
		}

		// for comparing in Assert
		bool operator==(const HexCoords& other) const
		{
			return m_swne == other.m_swne && m_nwse == other.m_nwse;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "Coords: (%d,%d)", m_swne, m_nwse);
			return std::string(buf);
		}

	private:
		int m_swne;	// SW-NE axis (positive number means NE direction, negative number means SW direction)
		int m_nwse;	// NW-SE axis (positive number means SE direction, negative number means NW direction)
	};
}