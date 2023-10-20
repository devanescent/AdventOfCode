#pragma once
#include "DayT.h"
#include "DanceMoveProcessor.h"

namespace AdventOfCode::Year2017::Day16
{
	// ---------------------------------------------------------------------------
	// Day16: Permutation Promenade
	// ---------------------------------------------------------------------------
	class PermutationPromenade : public DayT<DanceMoveProcessor>
	{
	public:
		PermutationPromenade();
		void SetPrgmCount(size_t count) { m_prgmCount = count; }

	protected:
		uint64_t ExecutePart1(std::vector<std::unique_ptr<DanceMove>> dance) override;
		uint64_t ExecutePart2(std::vector<std::unique_ptr<DanceMove>> dance) override;

	private:
		size_t m_prgmCount = 16;
	};
}
