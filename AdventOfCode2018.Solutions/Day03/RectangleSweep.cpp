#include "RectangleSweep.h"
#include <algorithm>
#include <list>

namespace AdventOfCode::Year2018::Day03
{
	uint64_t SweepLines(std::vector<LineSegment>& lineSegments)
	{
		std::sort(lineSegments.begin(), lineSegments.end(), LineSegment::CompareByStart);

		uint64_t total = 0;

		// Current slice:
		int sliceBegin = lineSegments.front().Start;

		// Line segemnts that are contained in the current slice:
		std::list<LineSegment> lineSegsInSlice;
		auto nextSeg = lineSegments.begin();

		while (nextSeg != lineSegments.end() || !lineSegsInSlice.empty())
		{
			// Add line segments which are in the current slice:
			while (nextSeg != lineSegments.end() && sliceBegin == nextSeg->Start)
			{
				// Insert ordered by end point
				lineSegsInSlice.insert(std::lower_bound(lineSegsInSlice.begin(), lineSegsInSlice.end(), *nextSeg, LineSegment::CompareByEnd), *nextSeg);
				nextSeg++;
			}

			// Remove line segments which are no longer in the current slice:
			while (!lineSegsInSlice.empty() && sliceBegin == lineSegsInSlice.begin()->End)
				lineSegsInSlice.erase(lineSegsInSlice.begin());

			// Slice end is the minimum between the first end inside the current window
			// AND the beginning of the next possible rectangle (if there is one):
			int sliceEnd = 0;
			if (lineSegsInSlice.empty())
			{
				// Current slice contains no claims:
				if (nextSeg != lineSegments.end())
					sliceEnd = nextSeg->Start;
			}
			else
			{
				if (nextSeg != lineSegments.end())
					sliceEnd = std::min(lineSegsInSlice.begin()->End, nextSeg->Start);
				else
					sliceEnd = lineSegsInSlice.begin()->End;
			}

			int sliceLen = sliceEnd - sliceBegin;
			if (lineSegsInSlice.size() > 1) // only counts if at least two segments overlap
			{
				// Mark all segments in this slice as overlapping:
				// -> mark in passed-in list, as 'lineSegsInSlice' is only temporary
				for (auto& ls : lineSegsInSlice)
				{
					int claimID = ls.ID;
					auto lineSeg = std::find_if(lineSegments.begin(), lineSegments.end(),
						[claimID](const LineSegment& l) { return l.ID == claimID; });
					lineSeg->Overlapping = true;
				}

				total += sliceLen;
			}

			sliceBegin = sliceEnd;
		}

		return total;
	}

	uint64_t SweepClaims(std::vector<RectangleClaim>& claims)
	{
		// Sort claims:
		std::sort(claims.begin(), claims.end(), RectangleClaim::CompareByX1);

		// Use sweep algorithm:
		//
		// +---------------------+
		// |1                    |
		// |                     |
		// |             +-------+----------------+
		// |             |3      |                |
		// |             |       |                |
		// +-------------+-------+                |
		//               |                        |
		//         +-----+---------------+        |
		//         |2    |               |        |
		//         |     +---------------+--------+
		//         |                     |
		//         +---------------------+
		//
		//         ^     ^
		//         |-----|
		//          Slice,
		//          with the current window containing claims 1 and 2

		uint64_t total = 0;

		// Current slice:
		int sliceBegin = claims.front().X1();

		// Claims that are contained in the current slice:
		std::list<RectangleClaim> claimsInSlice;
		auto nextClaim = claims.begin();

		while (nextClaim != claims.end() || !claimsInSlice.empty())
		{
			// Add claims which are in the current slice:
			while (nextClaim != claims.end() && sliceBegin == nextClaim->X1())
			{
				// Insert ordered by X2
				claimsInSlice.insert(std::lower_bound(claimsInSlice.begin(), claimsInSlice.end(), *nextClaim, RectangleClaim::CompareByX2), *nextClaim);
				nextClaim++;
			}

			// Remove claims which are no longer in the current slice:
			while (!claimsInSlice.empty() && sliceBegin == claimsInSlice.begin()->X2())
				claimsInSlice.erase(claimsInSlice.begin());

			// Slice end is the minimum between the first end inside the current window
			// AND the beginning of the next possible rectangle (if there is one):
			int sliceEnd = 0;
			if (claimsInSlice.empty())
			{
				// Current slice contains no claims:
				if (nextClaim != claims.end())
					sliceEnd = nextClaim->X1();
			}
			else
			{
				if (nextClaim != claims.end())
					sliceEnd = std::min(claimsInSlice.begin()->X2(), nextClaim->X1());
				else
					sliceEnd = claimsInSlice.begin()->X2();
			}

			int sliceLen = sliceEnd - sliceBegin;
			if (sliceLen > 0 && !claimsInSlice.empty())
			{
				std::vector<LineSegment> lineSegments;
				std::transform(claimsInSlice.begin(), claimsInSlice.end(), std::back_inserter(lineSegments),
					[](RectangleClaim& rc) { return LineSegment(rc.ID(), rc.Y1(), rc.Y2()); }
				);

				total += sliceLen * SweepLines(lineSegments);

				// For all overlapping line segments, also mark the corresponding claim as overlapping:
				// -> must search complete list, as 'claimsInSlice' is only temporary
				for (auto& ls : lineSegments)
				{
					if (!ls.Overlapping)
						continue;

					int claimID = ls.ID;
					auto claim = std::find_if(claims.begin(), claims.end(), 
						[claimID](const RectangleClaim& c) { return c.ID() == claimID; });
					claim->Overlapping = true;
				}
			}

			sliceBegin = sliceEnd;
		}

		return total;
	}
}