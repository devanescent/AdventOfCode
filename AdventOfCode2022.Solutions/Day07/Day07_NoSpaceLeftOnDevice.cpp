#include "Day07_NoSpaceLeftOnDevice.h"
#include <algorithm>
#include <numeric>

namespace AdventOfCode::Year2022::Day07
{
	NoSpaceLeftOnDevice::NoSpaceLeftOnDevice() : DayT(7, "No Space Left On Device") { }

	uint64_t NoSpaceLeftOnDevice::ExecutePart1(std::vector<Directory> input)
	{
		Directory& root = input[0];
		auto allDirs = root.GetAllDirs();

		return std::accumulate(allDirs.begin(), allDirs.end(), 0ull,
			[](uint64_t totalSize, const Directory* dir)
			{
				// Only sum up dirs with a maximum size of 100000:
				uint64_t dirSize = dir->GetSize();
				if (dirSize <= 100000)
					return totalSize + dirSize;
				else
					return totalSize;
			}
		);
	}

	uint64_t NoSpaceLeftOnDevice::ExecutePart2(std::vector<Directory> input)
	{
		// Calculated required size for update:
		const uint64_t diskSize = 70'000'000;
		const uint64_t requiredSize = 30'000'000;

		Directory& root = input[0];
		uint64_t freeSize = diskSize - root.GetSize();
		uint64_t sizeToDelete = requiredSize - freeSize;
		
		// Get all dirs and sort by size:
		auto allDirs = root.GetAllDirs();
		std::sort(allDirs.begin(), allDirs.end(),
			[](const Directory* dir1, const Directory* dir2)
			{
				return dir1->GetSize() < dir2->GetSize();
			}
		);

		// Find smallest dir that is of size 'sizeToDelete' or larger:
		auto dir = *std::lower_bound(allDirs.begin(), allDirs.end(), sizeToDelete,
			[](const Directory* dir, uint64_t sizeToDelete)
			{
				return dir->GetSize() < sizeToDelete;
			}
		);

		return dir->GetSize();
	}
}
