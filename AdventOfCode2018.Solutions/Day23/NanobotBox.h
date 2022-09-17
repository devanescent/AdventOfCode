#pragma once
#include "Nanobot.h"
#include <vector>

namespace AdventOfCode::Year2018::Day23
{
	class BoundingBox
	{
	public:
		BoundingBox(int x1, int x2, int y1, int y2, int z1, int z2) :
			m_x1(x1), m_x2(x2), m_y1(y1), m_y2(y2), m_z1(z1), m_z2(z2)
		{}

		// Returns closest distance to a point
		unsigned int GetDistanceTo(int x, int y, int z) const;

		// Simple metric to compare sizes of boxes:
		unsigned int GetSize() const;

		// Splits the box in upto 8 smaller boxes:
		std::vector<BoundingBox> Split() const { return SplitX(); }

	private:
		int m_x1, m_x2;
		int m_y1, m_y2;
		int m_z1, m_z2;

		// Splits the box in X / Y / Z direction:
		std::vector<BoundingBox> SplitX() const;
		std::vector<BoundingBox> SplitY(int x1, int x2) const;
		std::vector<BoundingBox> SplitZ(int x1, int x2, int y1, int y2) const;
	};


	// Wrapper for bounding box, which also counts how many nanobot's signal radius intersects with the box
	class NanobotBox
	{
	private:
		BoundingBox m_box;
		unsigned int m_nanoBotsInReach = 0;

	public:
		NanobotBox(BoundingBox box, const std::vector<Nanobot>& nanobots);

		bool IsSingleCoordinate() const { return m_box.GetSize() == 0; }
		unsigned int GetDistanceFromOrigin() const { return m_box.GetDistanceTo(0, 0, 0); }
		std::vector<NanobotBox> Split(const std::vector<Nanobot>& nanobots) const;

		// For ordering in a priority queue:
		bool operator<(const NanobotBox& other) const;
	};
}