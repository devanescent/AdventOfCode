#pragma once
#include <cmath>
#include <vector>

namespace AdventOfCode::Year2021::Day19
{
	struct Vector3
	{
		int X;
		int Y;
		int Z;

		Vector3(int x, int y, int z) : X(x), Y(y), Z(z) {}
		auto operator<=>(const Vector3& other) const = default;

		int GetAbsoluteDifference(const Vector3& other) const
		{
			int dx = std::abs(X - other.X);
			int dy = std::abs(Y - other.Y);
			int dz = std::abs(Z - other.Z);
			return dx + dy + dz;
		}
	};

	struct Beacon
	{
		int X;
		int Y;
		int Z;

		Beacon(int x, int y, int z) : X(x), Y(y), Z(z) {}
		auto operator<=>(const Beacon& other) const = default;
		Vector3 DistanceTo(const Beacon& other) const
		{
			return Vector3(X - other.X, Y - other.Y, Z - other.Z);
		}

		Beacon MoveBy(const Vector3& v) const
		{
			return Beacon(X + v.X, Y + v.Y, Z + v.Z);
		}
	};

	class Scanner
	{
	public:
		int ScannerNumber;
		std::vector<Beacon> ScannedBeacons;

		Scanner(int scannerNo) : ScannerNumber(scannerNo) {}
	};
}

// Specialization of hash function to use Vector3 in e.g. unordered_map
template<>
struct std::hash<AdventOfCode::Year2021::Day19::Vector3>
{
	std::size_t operator()(AdventOfCode::Year2021::Day19::Vector3 const& v) const noexcept
	{
		return v.X ^ (v.Y * 17) ^ (v.Z * 31);
	}
};