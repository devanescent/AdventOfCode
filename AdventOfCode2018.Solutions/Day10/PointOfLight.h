#pragma once
#include <cmath>

namespace AdventOfCode::Year2018::Day10
{
	class PointOfLight
	{
	public:
		PointOfLight(int x, int y, int dx, int dy) :
			m_x(x), m_y(y), m_dx(dx), m_dy(dy)
		{}

		void UpdatePosition()
		{
			m_x += m_dx;
			m_y += m_dy;
		}

		int GetDistanceTo(const PointOfLight& other) const
		{
			return std::abs(m_x - other.m_x) + std::abs(m_y - other.m_y);
		}

		int X() const { return m_x; }
		int Y() const { return m_y; }

	private:
		int m_x;
		int m_y;
		int m_dx;
		int m_dy;
	};
}