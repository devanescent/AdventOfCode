#include "Day19_BeaconScanner.h"
#include <algorithm>
#include <functional>
#include <map>
#include <numeric>

namespace AdventOfCode::Year2021::Day19
{
	BeaconScanner::BeaconScanner() : DayT(19, "Beacon Scanner") { }

	// Returns all beacons with coordinates and a list of scanner positions,
	// both relatively oriented to the first scanner
	std::pair<std::vector<Beacon>, std::vector<Vector3>> GetBeaconMap(std::vector<Scanner>& scanners)
	{
		// Possible rotations (x24):
		std::vector<std::function<Beacon(const Beacon&)>> rotations;
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.X, b.Y, b.Z); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.X, -b.Z, b.Y); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.X, b.Z, -b.Y); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.X, -b.Y, -b.Z); });

		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.X, b.Z, b.Y); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.X, -b.Y, b.Z); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.X, b.Y, -b.Z); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.X, -b.Z, -b.Y); });

		rotations.emplace_back([](const Beacon& b) { return Beacon(b.Y, b.Z, b.X); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.Y, -b.X, b.Z); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.Y, b.X, -b.Z); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.Y, -b.Z, -b.X); });

		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.Y, b.X, b.Z); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.Y, -b.Z, b.X); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.Y, b.Z, -b.X); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.Y, -b.X, -b.Z); });

		rotations.emplace_back([](const Beacon& b) { return Beacon(b.Z, b.X, b.Y); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.Z, -b.Y, b.X); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.Z, b.Y, -b.X); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(b.Z, -b.X, -b.Y); });

		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.Z, b.Y, b.X); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.Z, b.X, -b.Y); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.Z, -b.X, b.Y); });
		rotations.emplace_back([](const Beacon& b) { return Beacon(-b.Z, -b.Y, -b.X); });

		// Combine all beacons into common list, all beacons will be aligned to the first scanner's coordinates / rotation
		std::vector<Beacon> allBeacons;

		// Also keep track of scanner positions:
		std::vector<Vector3> scannerPositions;

		int totalBeaconCount = std::accumulate(scanners.begin(), scanners.end(), 0,
			[](int totalCount, const Scanner& scanner)
			{
				return totalCount + scanner.ScannedBeacons.size();
			});
		allBeacons.reserve(totalBeaconCount);

		// Copy first scanner into combined list:
		auto& firstScanner = scanners.front();
		std::copy(firstScanner.ScannedBeacons.begin(), firstScanner.ScannedBeacons.end(), std::back_inserter(allBeacons));
		scannerPositions.emplace_back(0, 0, 0);
		scanners.erase(scanners.begin());

		// Find overlap to another scanner:
		while (!scanners.empty())
		{
			bool foundMatch = false;
			for (auto scIt = scanners.begin(); scIt != scanners.end(); ++scIt)
			{
				// For each scanner, calculate all possible vectors between two beacons in all possible orientations:
				for (const auto& rotateFunc : rotations)
				{
					std::unordered_map<Vector3, int> diffs;
					for (const Beacon& a : allBeacons)
					{
						for (const Beacon& b : scIt->ScannedBeacons)
						{
							++diffs[a.DistanceTo(rotateFunc(b))];
						}
					}

					// If both scanners overlap, there will be at least 12 matches between them
					auto matchDiffIt = std::find_if(diffs.begin(), diffs.end(),
						[](const auto& diffEntry) { return diffEntry.second >= 12; });

					if (matchDiffIt != diffs.end())
					{
						auto matchVec = matchDiffIt->first;

						// Remember scanner location (relative to first scanner):
						scannerPositions.push_back(matchVec);

						// Transform beacons according to the rotation and append to common list:
						std::transform(scIt->ScannedBeacons.begin(), scIt->ScannedBeacons.end(), std::back_inserter(allBeacons),
							[&rotateFunc, &matchVec](const Beacon& b) { return rotateFunc(b).MoveBy(matchVec); });

						foundMatch = true;
						break;
					}
				}

				if (foundMatch)
				{
					// Remove matched scanner and restart search:
					scanners.erase(scIt);
					break;
				}
			}
		}

		std::sort(allBeacons.begin(), allBeacons.end());
		allBeacons.erase(std::unique(allBeacons.begin(), allBeacons.end()), allBeacons.end());
		return std::make_pair(allBeacons, scannerPositions);
	}

	uint64_t BeaconScanner::ExecutePart1(std::vector<Scanner> scanners)
	{
		// Get number of beacons:
		auto [beaconMap, _] = GetBeaconMap(scanners);
		return beaconMap.size();
	}

	uint64_t BeaconScanner::ExecutePart2(std::vector<Scanner> scanners)
	{
		// Get scanner positions:
		auto [_, scannerPositions] = GetBeaconMap(scanners);
		std::vector<int> distances;

		int scannerCount = scannerPositions.size();
		distances.reserve(scannerCount * scannerCount);

		for (int i = 0; i < scannerCount - 1; ++i)
		{
			for (int j = i + 1; j < scannerCount; ++j)
			{
				distances.emplace_back(scannerPositions[i].GetAbsoluteDifference(scannerPositions[j]));
			}
		}

		return *std::max_element(distances.begin(), distances.end());
	}
}
