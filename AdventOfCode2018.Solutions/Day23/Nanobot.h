#pragma once
#include <cmath>
#include <format>

namespace AdventOfCode::Year2018::Day23
{
	class Nanobot
	{
	private:
		int m_x;
		int m_y;
		int m_z;

		unsigned int m_signalRadius;

	public:
		Nanobot(int x, int y, int z, unsigned int sigR) :
			m_x(x), m_y(y), m_z(z), m_signalRadius(sigR)
		{}

		int X() const { return m_x; }
		int Y() const { return m_y; }
		int Z() const { return m_z; }

		unsigned int GetSignalRadius() const { return m_signalRadius; }

		unsigned int GetDistanceTo(const Nanobot& other) const
		{
			return std::abs(m_x - other.m_x) + std::abs(m_y - other.m_y) + std::abs(m_z - other.m_z);
		}

		bool operator==(const Nanobot& other) const = default;

		std::string ToString() const
		{
			return std::format("X: {}, Y: {}, Z: {}, R: {}", m_x, m_y, m_z, m_signalRadius);
		}
	};
}