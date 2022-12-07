#pragma once
#include "DayT.h"
#include "FilesystemProcessor.h"

namespace AdventOfCode::Year2022::Day07
{
	// ---------------------------------------------------------------------------
	// Day07: No Space Left On Device
	// ---------------------------------------------------------------------------
	class NoSpaceLeftOnDevice : public DayT<FilesystemProcessor>
	{
	public:
		NoSpaceLeftOnDevice();

	protected:
		uint64_t ExecutePart1(std::vector<Directory> input) override;
		uint64_t ExecutePart2(std::vector<Directory> input) override;
	};
}
