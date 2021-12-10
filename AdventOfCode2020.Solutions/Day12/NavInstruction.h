#pragma once
#include <cmath>

namespace AdventOfCode::Year2020::Day12
{ 
	// --------------------------------------------------------------------------- 
	enum class NavDirection
	{
		N,
		E,
		S,
		W,
		L,
		R,
		F
	};

	// ---------------------------------------------------------------------------
	class NavigationContext
	{

	public:
		NavigationContext(NavDirection initialOrientation) :
			m_northSouthPosition(0), m_eastWestPosition(0), m_orientation(initialOrientation)
		{}

		int GetDistanceFromOrigin() { return std::abs(m_northSouthPosition) + std::abs(m_eastWestPosition); }
		
		void MoveNorth(int val) { m_northSouthPosition -= val; }
		void MoveEast(int val) { m_eastWestPosition += val; }
		void MoveSouth(int val) { m_northSouthPosition += val; }
		void MoveWest(int val) { m_eastWestPosition -= val; }
		void TurnLeft() { m_orientation = static_cast<NavDirection>((static_cast<int>(m_orientation) + 3) % 4); }
		void TurnRight() { m_orientation = static_cast<NavDirection>((static_cast<int>(m_orientation) + 1) % 4); }
		void MoveForward(int val)
		{
			switch (m_orientation)
			{
				case NavDirection::N: MoveNorth(val); break;
				case NavDirection::E: MoveEast(val);  break;
				case NavDirection::S: MoveSouth(val); break;
				case NavDirection::W: MoveWest(val);  break;
			}
		}

	private:
		NavDirection	m_orientation;				// only N, E, S, W
		int				m_northSouthPosition;
		int				m_eastWestPosition;
	};

	// ---------------------------------------------------------------------------
	class NavInstruction
	{

	public:
		NavInstruction(NavDirection dir, int val) :
			m_direction(dir), m_value(val)
		{}

		void Execute(NavigationContext& ctx)
		{
			switch (m_direction)
			{
				case NavDirection::N: ctx.MoveNorth(m_value);	break;
				case NavDirection::E: ctx.MoveEast(m_value);	break;
				case NavDirection::S: ctx.MoveSouth(m_value);	break;
				case NavDirection::W: ctx.MoveWest(m_value);	break;
				case NavDirection::L:
				for (int k = 0; k < m_value / 90; ++k)
					ctx.TurnLeft();	
				break;
				case NavDirection::R:
				for (int k = 0; k < m_value / 90; ++k)
					ctx.TurnRight();
				break;
				case NavDirection::F: ctx.MoveForward(m_value);	break;
			}
		}

		bool operator==(const NavInstruction& other) const
		{
			return m_direction == other.m_direction && m_value == other.m_value;
		}

		std::string ToString() const
		{
			char buf[256] = {0};
			switch (m_direction)
			{
				case NavDirection::N: snprintf(buf, sizeof(buf), "N%d", m_value); break;
				case NavDirection::E: snprintf(buf, sizeof(buf), "E%d", m_value); break;
				case NavDirection::S: snprintf(buf, sizeof(buf), "S%d", m_value); break;
				case NavDirection::W: snprintf(buf, sizeof(buf), "W%d", m_value); break;
				case NavDirection::L: snprintf(buf, sizeof(buf), "L%d", m_value); break;
				case NavDirection::R: snprintf(buf, sizeof(buf), "R%d", m_value); break;
				case NavDirection::F: snprintf(buf, sizeof(buf), "F%d", m_value); break;
			}
			return std::string(buf);
		}

	private:
		NavDirection	m_direction;
		int				m_value;
	};
}
