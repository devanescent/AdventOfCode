#pragma once
#include <string>

namespace AdventOfCode::Year2018::Day03
{
	class RectangleClaim
	{
	public:
		RectangleClaim(int id, int left, int top, int width, int height) :
			m_id(id), m_left(left), m_top(top), m_width(width), m_height(height)
		{}

		bool operator==(const RectangleClaim& other) const
		{
			return m_id == other.m_id &&
				m_left == other.m_left &&
				m_top == other.m_top &&
				m_width == other.m_width &&
				m_height == other.m_height;
		}

		int ID() const { return m_id; }
		int X1() const { return m_left; }
		int X2() const { return m_left + m_width; }
		int Y1() const { return m_top; }
		int Y2() const { return m_top + m_height; }

		// Comparators:
		static bool CompareByX1(const RectangleClaim& rc1, const RectangleClaim& rc2)
		{
			return rc1.m_left < rc2.m_left;
		}

		static bool CompareByX2(const RectangleClaim& rc1, const RectangleClaim& rc2)
		{
			return (rc1.m_left + rc1.m_width) < (rc2.m_left + rc2.m_width);
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "#%d @ %d,%d: %dx%d", m_id, m_left, m_top, m_width, m_height);
			return std::string(buf);
		}

		bool Overlapping = false;

	private:
		int m_id;
		int m_left;
		int m_top;
		int m_width;
		int m_height;
	};
}
