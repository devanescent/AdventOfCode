#pragma once
#include "Point.h"

namespace AdventOfCode::Year2024::Day14
{
	class Robot
	{
	public:
		Point<int> Position;
		Point<int> Velocity;

		void ConvertNegativeVelocity(int areaWidth, int areaHeight)
		{
			if (Velocity.X < 0)
				Velocity.X = areaWidth + Velocity.X;

			if (Velocity.Y < 0)
				Velocity.Y = areaHeight + Velocity.Y;
		}

		void UpdatePostion(int areaWidth, int areaHeight)
		{
			Position.X = (Position.X + Velocity.X) % areaWidth;
			Position.Y = (Position.Y + Velocity.Y) % areaHeight;
		}
	};
}
