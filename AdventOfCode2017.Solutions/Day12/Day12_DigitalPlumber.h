#pragma once
#include "DayT.h"
#include "PipeProcessor.h"
#include <map>

namespace AdventOfCode::Year2017::Day12
{
	// ---------------------------------------------------------------------------
	// Day12: Digital Plumber
	// ---------------------------------------------------------------------------
	class DigitalPlumber : public DayT<PipeProcessor>
	{
	public:
		DigitalPlumber();

	protected:
		uint64_t ExecutePart1(std::vector<Pipe> pipes) override;
		uint64_t ExecutePart2(std::vector<Pipe> pipes) override;

	private:
		uint64_t FindGroup(int programId, std::map<int, const Pipe*>& pipeMap);
	};
}
