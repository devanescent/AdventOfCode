#include "Day15_BeaconExclusionZone.h"
#include "Range.h"
#include <algorithm>
#include <numeric>
#include <set>

namespace AdventOfCode::Year2022::Day15
{
	using Segment = Range<int64_t>;

	BeaconExclusionZone::BeaconExclusionZone(int64_t row) : DayT(15, "Beacon Exclusion Zone"), m_row(row) { }

	// Get all segments of a single row where there cannot be a beacon:
	std::vector<Segment> GetNonBeaconSegments(const std::vector<Sensor>& sensors, int64_t row)
	{
		std::vector<Segment> segments;

		for (const Sensor& s : sensors)
		{
			// Distance to the row to be considered:
			auto dy = row - s.Pos.Y;

			// Get intersection between row and signal radius:
			if (s.SignalRadius() >= std::abs(dy))
			{
				auto dx = s.SignalRadius() - std::abs(dy);
				auto start = s.Pos.MoveXBy(-dx).X;
				auto end = s.Pos.MoveXBy(dx).X;

				segments.emplace_back(start, end);
			}
		}

		std::sort(segments.begin(), segments.end());
		return segments;
	}

	void MergeOverlappingSegments(std::vector<Segment>& segments)
	{
		// Keep merging as long as possible
		bool wasMerged = false;
		do
		{
			std::vector<Segment> mergedSegments;
			wasMerged = false;

			// Start with the first segment and try merge it together with the following segments:
			Range currentSegment = segments.front();
			for (auto nextSegment = segments.begin() + 1; nextSegment != segments.end(); ++nextSegment)
			{
				// Merge overlapping segments or segments directly next to each other:
				if (currentSegment.OverlapsWith(*nextSegment) || currentSegment.DistanceTo(*nextSegment) == 1)
				{
					currentSegment = currentSegment.MergeWith(*nextSegment);
					wasMerged = true;
				}
				else
				{
					// Otherwise, try merging the next segment:
					mergedSegments.emplace_back(currentSegment);
					currentSegment = *nextSegment;
				}
			}

			mergedSegments.emplace_back(currentSegment);

			// Replace original collection and try again:
			segments = std::move(mergedSegments);

		} 
		// No merge possible or only one segment left
		while (wasMerged && segments.size() > 1);
	}


	uint64_t BeaconExclusionZone::ExecutePart1(std::vector<Sensor> sensors)
	{
		// Create and merge segments where there can be no beacon:
		std::vector<Segment> nonBeaconSegments = GetNonBeaconSegments(sensors, m_row);
		MergeOverlappingSegments(nonBeaconSegments);

		// Sum up length of all these segments:
		auto positionsWithoutBeacons = std::accumulate(nonBeaconSegments.begin(), nonBeaconSegments.end(), 0ull,
			[](uint64_t segmentTotalLen, const Segment& segment)
			{ return segmentTotalLen + segment.Length(); }
		);

		// Get all unique beacons from the sensors:
		std::set<Point<int64_t>> beacons;
		std::transform(sensors.begin(), sensors.end(), std::inserter(beacons, beacons.end()),
			[](const Sensor& s) { return s.ClosestBeacon; }
		);

		// Reduce number of possible positions by one for each beacon that exists in this line:
		auto beaconNumInRow = std::count_if(beacons.begin(), beacons.end(),
			[this](const Point<int64_t>& beacon)
			{ return beacon.Y == m_row; }
		);

		return positionsWithoutBeacons - beaconNumInRow;
	}

	uint64_t BeaconExclusionZone::ExecutePart2(std::vector<Sensor> sensors)
	{
		uint64_t tuningFrequency = 0;
		for (auto y = 0; y <= 4'000'000; ++y)
		{
			// Create and merge segments where there can be no beacon:
			std::vector<Segment> nonBeaconSegments = GetNonBeaconSegments(sensors, y);
			MergeOverlappingSegments(nonBeaconSegments);

			// If a line contains two non-merged segments, this indicates the only possible location of the distress signal:
			if (nonBeaconSegments.size() > 1)
			{
				// Calculate tuning frequency:
				auto x = nonBeaconSegments[0].End + 1; // point between the two segments
				tuningFrequency = 4000000ull * x + y;
				break;
			}
		}

		return tuningFrequency;
	}
}
