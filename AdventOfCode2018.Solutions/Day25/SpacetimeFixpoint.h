#pragma once
#include <algorithm>
#include <cmath>
#include <vector>

namespace AdventOfCode::Year2018::Day25
{
	class SpacetimeFixpoint
	{
	private:
		int m_x, m_y, m_z, m_t;

	public:
		SpacetimeFixpoint(int x, int y, int z, int t) :
			m_x(x), m_y(y), m_z(z), m_t(t)
		{ }

		unsigned int GetDistanceTo(const SpacetimeFixpoint& other) const
		{
			return std::abs(m_x - other.m_x) + std::abs(m_y - other.m_y) + std::abs(m_z - other.m_z) + std::abs(m_t - other.m_t);
		}

		bool operator==(const SpacetimeFixpoint& other) const
		{
			return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z && m_t == other.m_t;
		}
	};

	class Constellation
	{
	private:
		std::vector<SpacetimeFixpoint> m_constellation;

	public:
		Constellation(SpacetimeFixpoint fp)
		{
			m_constellation.emplace_back(fp);
		}

		bool operator==(const Constellation& other) const
		{
			return m_constellation == other.m_constellation;
		}

		bool TryAddPoint(const SpacetimeFixpoint& fp) const
		{
			return std::any_of(m_constellation.begin(), m_constellation.end(),
				[fp](const SpacetimeFixpoint& constPoint) { return constPoint.GetDistanceTo(fp) <= 3; });
		}

		void AddPoint(const SpacetimeFixpoint& fp)
		{
			m_constellation.push_back(fp);
		}

		void Join(const Constellation& c)
		{
			m_constellation.insert(m_constellation.end(), c.m_constellation.begin(), c.m_constellation.end());
		}
	};
}