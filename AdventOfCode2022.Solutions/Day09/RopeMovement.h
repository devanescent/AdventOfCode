#pragma once
#include <cmath>

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
		RopeMovement(Direction dir, int distance) :
			m_direction(dir), m_distance(distance)
		{ }

		int GetDistance() const { return m_distance; }

		void MoveHead(std::pair<int, int>& head) const
		{
			int dx = 0, dy = 0;

			switch (m_direction)
			{
				case Direction::Up: dy = -1; break;
				case Direction::Down: dy = 1; break;
				case Direction::Left: dx = -1; break;
				case Direction::Right: dx = 1; break;
			}

			head.first += dx;
			head.second += dy;
		}

		void MoveTail(const std::pair<int, int>& head, std::pair<int, int>& tail) const
		{
			if (GetDistance(head, tail) > 1)
			{
				if (head.first == tail.first)
				{
					// Move tail up / down towards head
					tail.second = (head.second + tail.second) / 2;
				}
				else if (head.second == tail.second)
				{
					// Move tail left / right towards head
					tail.first = (head.first + tail.first) / 2;
				}
				else
				{
					// Move diagonally:
					if (std::abs(head.first - tail.first) == 2 && std::abs(head.second - tail.second) == 2)
					{
						// Distance 2 diagonally: move 1 step in both directions
						tail.first = (head.first + tail.first) / 2;
						tail.second = (head.second + tail.second) / 2;
					}
					else if (std::abs(head.first - tail.first) == 2)
					{
						// Distance 2 vertically:
						tail.first = (head.first + tail.first) / 2;
						tail.second = head.second;
					}
					else
					{
						// Distance 2 horizontally:
						tail.second = (head.second + tail.second) / 2;
						tail.first = head.first;
					}
				}
			}
		}

	private:
		Direction m_direction;
		int m_distance;

		int GetDistance(const std::pair<int, int>& head, const std::pair<int, int>& tail) const
		{
			int dx = std::abs(head.first - tail.first);
			int dy = std::abs(head.second - tail.second);

			// Use sqrt to "reduce" diagonal distance to 1:
			return static_cast<int>(std::sqrt(dx * dx + dy * dy));
		}
	};
}
