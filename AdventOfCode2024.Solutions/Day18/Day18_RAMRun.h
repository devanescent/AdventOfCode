#pragma once
#include "DayT.h"
#include "ByteProcessor.h"

namespace AdventOfCode::Year2024::Day18
{
	// ---------------------------------------------------------------------------
	// Day18: RAM Run
	// ---------------------------------------------------------------------------
	class RAMRun : public DayT<ByteProcessor, uint64_t, std::string>
	{
	public:
		RAMRun();
		void SetMemorySize(int size) { _memorySize = size; }
		void SetSimulationCount(int count) { _simulationCount = count; }

	protected:
		uint64_t ExecutePart1(std::vector<Point<int>> bytes) override;
		std::string ExecutePart2(std::vector<Point<int>> bytes) override;

	private:
		int _memorySize = 70;
		int _simulationCount = 1024;
	};
}
