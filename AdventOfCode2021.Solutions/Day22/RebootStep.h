#pragma once
#include "Range.h"
#include <vector>

namespace AdventOfCode::Year2021::Day22
{
	struct Cuboid
	{
		Range<int64_t> XRange;
		Range<int64_t> YRange;
		Range<int64_t> ZRange;

		auto operator<=>(const Cuboid& other) const = default;

		uint64_t GetCubeCount() const
		{
			return XRange.Length() * YRange.Length() * ZRange.Length();
		}

		bool OverlapsWith(const Cuboid& other) const
		{
			return XRange.OverlapsWith(other.XRange)
				&& YRange.OverlapsWith(other.YRange)
				&& ZRange.OverlapsWith(other.ZRange);
		}

		// Split into smaller cuboids that fill up the area without the passed in cuboid:
		bool Split(const Cuboid& other, std::vector<Cuboid>& out_splitWithout)
		{
			if (!OverlapsWith(other))
				return false;

			// Split along x axis:
			if (XRange.Start < other.XRange.Start)
			{
				out_splitWithout.emplace_back(Cuboid{
					{ XRange.Start, other.XRange.Start - 1 },
					{ YRange.Start, YRange.End },
					{ ZRange.Start, ZRange.End }
				});
				XRange.Start = other.XRange.Start;
			}
			if (XRange.End > other.XRange.End)
			{
				out_splitWithout.emplace_back(Cuboid{
					{ other.XRange.End + 1, XRange.End },
					{ YRange.Start, YRange.End },
					{ ZRange.Start, ZRange.End }
				});
				XRange.End = other.XRange.End;
			}

			// Split along y axis
			if (YRange.Start < other.YRange.Start)
			{
				out_splitWithout.emplace_back(Cuboid{
					{ XRange.Start, XRange.End },
					{ YRange.Start, other.YRange.Start - 1 },
					{ ZRange.Start, ZRange.End }
				});
				YRange.Start = other.YRange.Start;
			}
			if (YRange.End > other.YRange.End)
			{
				out_splitWithout.emplace_back(Cuboid{
					{ XRange.Start, XRange.End },
					{ other.YRange.End + 1, YRange.End },
					{ ZRange.Start, ZRange.End }
				});
				YRange.End = other.YRange.End;
			}

			// Split along z axis
			if (ZRange.Start < other.ZRange.Start)
			{
				out_splitWithout.emplace_back(Cuboid{
					{ XRange.Start, XRange.End },
					{ YRange.Start, YRange.End },
					{ ZRange.Start, other.ZRange.Start - 1 }
				});
				ZRange.Start = other.ZRange.Start;
			}
			if (ZRange.End > other.ZRange.End)
			{
				out_splitWithout.emplace_back(Cuboid{
					{ XRange.Start, XRange.End },
					{ YRange.Start, YRange.End },
					{ other.ZRange.End + 1, ZRange.End }
				});
				ZRange.End = other.ZRange.End;
			}

			return true;
		}
	};

	enum class RebootState
	{
		on,
		off
	};

	struct RebootStep
	{
		RebootState NewState;
		Cuboid Region;

		// Created during processing of overlapping reboot steps:
		std::vector<Cuboid> Splits;

		bool IsPartOfInitProcedure() const
		{
			Range<int64_t> initRange(-50, 50);

			return initRange.Contains(Region.XRange)
				&& initRange.Contains(Region.YRange)
				&& initRange.Contains(Region.ZRange);
		}
		
		bool operator==(const RebootStep& other) const
		{
			return NewState == other.NewState && Region == other.Region;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%s X=%lld..%lld, Y=%lld..%lld, Z=%lld..%lld", 
				NewState == RebootState::on ? "on" : "off",
				Region.XRange.Start, Region.XRange.End,
				Region.YRange.Start, Region.YRange.End,
				Region.ZRange.Start, Region.ZRange.End);
			return std::string(buf);
		}
	};
}