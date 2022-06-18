#pragma once

namespace AdventOfCode::Year2018::Day13
{
	enum class Direction
	{
		// Ordered in clockwise (right-turn) order
		Up,
		Right,
		Down,
		Left
	};

	enum class ChangeDirection
	{
		TurnLeft,				// turns left at first intersection
		ContinueStraight,		// continues straight at second intersection
		TurnRight				// turns right at third intersection
	};

	template <typename TEnum>
	TEnum NextEnumVal(TEnum val, int numEnumValues) { return static_cast<TEnum>((static_cast<int>(val) + 1) % numEnumValues); }

	template <typename TEnum>
	TEnum PrevEnumVal(TEnum val, int numEnumValues) { return static_cast<TEnum>((static_cast<int>(val) + numEnumValues - 1) % numEnumValues); }

	class Minecart
	{
	public:
		Minecart(int x, int y, Direction initialMoveDir) : 
			m_position(x, y), m_moveDir(initialMoveDir),
			m_nextIntersectionDir(ChangeDirection::TurnLeft) 
		{}

		const std::pair<int, int>& GetPosition() const { return m_position; }
		const Direction GetForwardDirection() const { return m_moveDir; }

		void MoveForward()
		{
			m_position.first += m_moveDir == Direction::Right ? 1 : m_moveDir == Direction::Left ? -1 : 0;
			m_position.second += m_moveDir == Direction::Down ? 1 : m_moveDir == Direction::Up ? -1 : 0;
		}

		void TurnRight()
		{
			m_position.first += m_moveDir == Direction::Up ? 1 : m_moveDir == Direction::Down ? -1 : 0;
			m_position.second += m_moveDir == Direction::Right ? 1 : m_moveDir == Direction::Left ? -1 : 0;

			m_moveDir = NextEnumVal(m_moveDir, 4);
		}

		void TurnLeft()
		{
			m_position.first += m_moveDir == Direction::Down ? 1 : m_moveDir == Direction::Up ? -1 : 0;
			m_position.second += m_moveDir == Direction::Left ? 1 : m_moveDir == Direction::Right ? -1 : 0;

			m_moveDir = PrevEnumVal(m_moveDir, 4);
		}

		void PassIntersection()
		{
			switch (m_nextIntersectionDir)
			{
				case ChangeDirection::TurnLeft: TurnLeft(); break;
				case ChangeDirection::ContinueStraight: MoveForward(); break;
				case ChangeDirection::TurnRight: TurnRight(); break;
			}

			m_nextIntersectionDir = NextEnumVal(m_nextIntersectionDir, 3);
		}

		bool operator<(const Minecart& other) const
		{
			// Order by "rows" (Y) first, then by columns (left to right)
			if (m_position.second != other.m_position.second)
				return m_position.second < other.m_position.second;
			else
				return m_position.first < other.m_position.first;
		}

		bool operator==(const Minecart& other) const
		{
			return GetPosition() == other.GetPosition();
		}

	private:
		std::pair<int, int> m_position;

		Direction m_moveDir;
		ChangeDirection m_nextIntersectionDir;
	};

	enum class TrackType
	{
		Horizontal,
		Vertical,
		RightCurve,
		LeftCurve,
		Intersection
	};
}