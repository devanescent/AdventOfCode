#pragma once

namespace AdventOfCode::Year2017::Day20
{
	class Vector3
	{
	public:
		int X, Y, Z;

		Vector3(int x, int y, int z) : X(x), Y(y), Z(z) {}
		Vector3() : Vector3(0,0,0) {}

		Vector3& operator+(const Vector3& other)
		{
			X += other.X;
			Y += other.Y;
			Z += other.Z;
			return *this;
		}
		
		auto operator<=>(const Vector3& other) const = default;

		int GetLength() const
		{
			// Manhattan distance:
			return std::abs(X) + std::abs(Y) + std::abs(Z);
		}
	};

	class Particle
	{
	public:
		int Order;
		Vector3 Position;
		Vector3 Velocity;
		Vector3 Acceleration;
	};
}
