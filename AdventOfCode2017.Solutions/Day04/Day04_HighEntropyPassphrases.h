#pragma once
#include "DayT.h"
#include "PassphraseProcessor.h"

namespace AdventOfCode::Year2017::Day04
{
	// ---------------------------------------------------------------------------
	// Day04: High-Entropy Passphrases
	// ---------------------------------------------------------------------------
	class HighEntropyPassphrases : public DayT<PassphraseProcessor>
	{
	public:
		HighEntropyPassphrases();

	protected:
		uint64_t ExecutePart1(std::vector<std::vector<std::string>> input) override;
		uint64_t ExecutePart2(std::vector<std::vector<std::string>> input) override;
	};
}
