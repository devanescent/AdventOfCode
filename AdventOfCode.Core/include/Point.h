#pragma once
#include <cmath>
#include <functional>

namespace AdventOfCode
{
	enum class DistanceMetric
	{
		Manhattan, // Distance is sum of distances of all coordinates
		Maximum	   // Distance is maximum value of distances of all coordinates
	};

	template<typename T>
	struct Point
	{
		T X;
		T Y;

		Point() : X(0), Y(0) {}
		Point(T x, T y) : X(x), Y(y) {}

		Point WithX(T x) const { return Point{ x, Y }; }
		Point WithY(T y) const { return Point{ X, y }; }

		Point MoveXBy(T dx) const { return Point{ X + dx, Y }; }
		Point MoveYBy(T dy) const { return Point{ X, Y + dy }; }
		Point MoveBy(T dx, T dy) const { return Point{ X + dx, Y + dy }; }

		T DistanceTo(const Point& other, DistanceMetric metric = DistanceMetric::Manhattan) const
		{
			T dx = X > other.X ? X - other.X : other.X - X;
			T dy = Y > other.Y ? Y - other.Y : other.Y - Y;

			switch (metric)
			{
				case DistanceMetric::Manhattan:
					return dx + dy;
				case DistanceMetric::Maximum:
					return std::max(dx, dy);
				default:
					return T();
			}
		}

		std::vector<Point<T>> GetSurroundingPoints(bool includeDiagonals) const
		{
			std::vector<Point<T>> points;
			points.reserve(8);

			points.emplace_back(X, Y - 1);
			points.emplace_back(X, Y + 1);
			points.emplace_back(X - 1, Y);
			points.emplace_back(X + 1, Y);

			if (includeDiagonals)
			{
				points.emplace_back(X - 1, Y - 1);
				points.emplace_back(X + 1, Y + 1);
				points.emplace_back(X - 1, Y + 1);
				points.emplace_back(X + 1, Y - 1);
			}

			return points;
		}

		bool CheckBounds(T width, T height) const
		{
			return X >= 0 && X < width && Y >= 0 && Y < height;
		}

		bool IsXBetween(T xmin, T xmax) const
		{
			return X >= xmin && X <= xmax;
		}

		bool IsYBetween(T ymin, T ymax) const
		{
			return Y >= ymin && Y <= ymax;
		}

		// Make points sortable, e.g. for using in a map
		bool operator<(const Point& other) const
		{
			if (X != other.X)
				return X < other.X;
			else
				return Y < other.Y;
		}

		bool operator==(const Point& other) const
		{
			return X == other.X && Y == other.Y;
		}
	};
}

// Specialization of hash function to use Point in e.g. unordered_set
template<typename T>
struct std::hash<AdventOfCode::Point<T>>
{
	std::size_t operator()(AdventOfCode::Point<T> const& p) const noexcept
	{
		return p.X ^ p.Y;
	}
};