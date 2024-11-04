#pragma once
#include "DayT.h"
#include "ScannerProcessor.h"

namespace AdventOfCode::Year2021::Day19
{
	// ---------------------------------------------------------------------------
	// Day19: Beacon Scanner
	// ---------------------------------------------------------------------------
	class BeaconScanner : public DayT<ScannerProcessor>
	{
	public:
		BeaconScanner();

	protected:
		uint64_t ExecutePart1(std::vector<Scanner> scanners) override;
		uint64_t ExecutePart2(std::vector<Scanner> scanners) override;
	};
}
