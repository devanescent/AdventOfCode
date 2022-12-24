#pragma once
#include "Point.h"

namespace AdventOfCode::Year2022::Day24
{
	enum class Direction
	{
		Up,
		Down,
		Left,
		Right
	};

	class Blizzard
	{
	private:
		Direction m_dir;
		Point<int> m_startPos;

	public:
		static int XMax;
		static int YMax;

		Blizzard(Direction dir, Point<int> start) :
			m_dir(dir), m_startPos(start)
		{}

		Point<int> GetPosAtTime(int minute) const
		{
			Point<int> next(0,0);
			switch (m_dir)
			{
				// Wrap around in range 1..Max
				case Direction::Up:
					minute %= YMax;
					next = m_startPos.WithY((m_startPos.Y - minute + YMax - 1) % YMax + 1);
					break;
				case Direction::Down:
					next = m_startPos.WithY((m_startPos.Y + minute - 1) % YMax + 1);
					break;
				case Direction::Left:
					minute %= XMax;
					next = m_startPos.WithX((m_startPos.X - minute + XMax - 1) % XMax + 1);
					break;
				case Direction::Right:
					next = m_startPos.WithX((m_startPos.X + minute - 1) % XMax + 1);
					break;
			}

			return next;
		}
	};
}
