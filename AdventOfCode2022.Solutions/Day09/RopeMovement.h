#pragma once
#include <cmath>
#include "Point.h"

namespace AdventOfCode::Year2022::Day09
{
	enum class Direction : char
	{
		Up = 'U',
		Down = 'D',
		Left = 'L',
		Right = 'R'
	};

	class RopeMovement
	{
	public:
		RopeMovement(Direction dir, int times) :
			m_direction(dir), m_times(times)
		{ }

		int Times() const { return m_times; }

		void MoveHead(Point<int>& head) const
		{
			int dx = 0, dy = 0;

			switch (m_direction)
			{
				case Direction::Up: dy = -1; break;
				case Direction::Down: dy = 1; break;
				case Direction::Left: dx = -1; break;
				case Direction::Right: dx = 1; break;
			}

			head.X += dx;
			head.Y += dy;
		}

		// Return true if tail actually moved, false otherwise
		bool MoveTail(const Point<int>& head, Point<int>& tail) const
		{
			if (head.DistanceTo(tail, DistanceMetric::Maximum) > 1)
			{
				if (head.X == tail.X)
				{
					// Move tail up / down towards head
					tail.Y = (head.Y + tail.Y) / 2;
				}
				else if (head.Y == tail.Y)
				{
					// Move tail left / right towards head
					tail.X = (head.X + tail.X) / 2;
				}
				else
				{
					// Move diagonally:
					if (std::abs(head.X - tail.X) == 2 && std::abs(head.Y - tail.Y) == 2)
					{
						// Distance 2 diagonally: move 1 step in both directions
						tail.X = (head.X + tail.X) / 2;
						tail.Y = (head.Y + tail.Y) / 2;
					}
					else if (std::abs(head.X - tail.X) == 2)
					{
						// Distance 2 vertically:
						tail.X = (head.X + tail.X) / 2;
						tail.Y = head.Y;
					}
					else
					{
						// Distance 2 horizontally:
						tail.Y = (head.Y + tail.Y) / 2;
						tail.X = head.X;
					}
				}
				return true;
			}
			else
				return false;
		}

	private:
		Direction m_direction;
		int m_times;
	};
}
