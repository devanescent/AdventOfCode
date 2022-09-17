#include "NanobotBox.h"

namespace AdventOfCode::Year2018::Day23
{
	unsigned int BoundingBox::GetDistanceTo(int x, int y, int z) const
	{
		unsigned int d = 0;

		// X distance:
		if (x < m_x1)
			d += m_x1 - x;
		else if (x > m_x2)
			d += x - m_x2;

		// Y distance:
		if (y < m_y1)
			d += m_y1 - y;
		else if (y > m_y2)
			d += y - m_y2;

		// Z distance:
		if (z < m_z1)
			d += m_z1 - z;
		else if (z > m_z2)
			d += z - m_z2;

		return d;
	}

	unsigned int BoundingBox::GetSize() const
	{
		return (m_x2 - m_x1) + (m_y2 - m_y1) + (m_z2 - m_z1);
	}

	std::vector<BoundingBox> BoundingBox::SplitX() const
	{
		std::vector<BoundingBox> splitBoxes;

		int mx = m_x1 + (m_x2 - m_x1) / 2;
		if (mx > m_x1 || mx < m_x2)
		{
			auto split = SplitY(m_x1, mx);
			splitBoxes.insert(splitBoxes.end(), split.begin(), split.end());

			split = SplitY(mx + 1, m_x2);
			splitBoxes.insert(splitBoxes.end(), split.begin(), split.end());
		}
		else
		{
			splitBoxes = SplitY(m_x1, m_x2);
		}

		return splitBoxes;
	}

	std::vector<BoundingBox> BoundingBox::SplitY(int x1, int x2) const
	{
		std::vector<BoundingBox> splitBoxes;

		int my = m_y1 + (m_y2 - m_y1) / 2;
		if (my > m_y1 || my < m_y2)
		{
			auto split = SplitZ(x1, x2, m_y1, my);
			splitBoxes.insert(splitBoxes.end(), split.begin(), split.end());

			split = SplitZ(x1, x2, my + 1, m_y2);
			splitBoxes.insert(splitBoxes.end(), split.begin(), split.end());
		}
		else
		{
			splitBoxes = SplitZ(x1, x2, m_y1, m_y2);
		}

		return splitBoxes;
	}

	std::vector<BoundingBox> BoundingBox::SplitZ(int x1, int x2, int y1, int y2) const
	{
		std::vector<BoundingBox> splitBoxes;

		int mz = m_z1 + (m_z2 - m_z1) / 2;
		if (mz > m_z1 || mz < m_z2)
		{
			splitBoxes.emplace_back(x1, x2, y1, y2, m_z1, mz);
			splitBoxes.emplace_back(x1, x2, y1, y2, mz + 1, m_z2);
		}
		else
		{
			splitBoxes.emplace_back(x1, x2, y1, y2, m_z1, m_z2);
		}

		return splitBoxes;
	}

	NanobotBox::NanobotBox(BoundingBox box, const std::vector<Nanobot>& nanobots) :
		m_box(std::move(box))
	{
		m_nanoBotsInReach = std::count_if(nanobots.begin(), nanobots.end(),
			[&](const Nanobot& n)
			{
				return m_box.GetDistanceTo(n.X(), n.Y(), n.Z()) <= n.GetSignalRadius();
			}
		);
	}

	std::vector<NanobotBox> NanobotBox::Split(const std::vector<Nanobot>& nanobots) const
	{
		std::vector<NanobotBox> nanoBoxes;
		auto boxes = m_box.Split();
		std::transform(boxes.begin(), boxes.end(), std::back_inserter(nanoBoxes),
			[nanobots](const BoundingBox& box)
			{
				return NanobotBox(box, nanobots);
			}
		);
		return nanoBoxes;
	}

	bool NanobotBox::operator<(const NanobotBox& other) const
	{
		if (m_nanoBotsInReach != other.m_nanoBotsInReach)
			return m_nanoBotsInReach < other.m_nanoBotsInReach;
		else
		{
			// Order by distance to zero
			unsigned int this_dist = m_box.GetDistanceTo(0, 0, 0);
			unsigned int other_dist = other.m_box.GetDistanceTo(0, 0, 0);
			if (this_dist != other_dist)
				return this_dist > other_dist; // higher priority, if closer to origin
			else
			{
				// Lastly, order by size:
				return m_box.GetSize() > other.m_box.GetSize(); // higher priority, if smaller
			}
		}
	}
}
