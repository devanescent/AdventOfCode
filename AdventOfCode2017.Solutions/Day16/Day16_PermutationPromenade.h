#pragma once
#include "DayT.h"
#include "DanceMoveProcessor.h"

namespace AdventOfCode::Year2017::Day16
{
	// ---------------------------------------------------------------------------
	// Day16: Permutation Promenade
	// ---------------------------------------------------------------------------
	class PermutationPromenade : public DayT<DanceMoveProcessor, std::string>
	{
	public:
		PermutationPromenade();
		void SetPrgmCount(size_t count) { m_prgmCount = count; }

	protected:
		std::string ExecutePart1(std::vector<std::unique_ptr<DanceMove>> dance) override;
		std::string ExecutePart2(std::vector<std::unique_ptr<DanceMove>> dance) override;

	private:
		size_t m_prgmCount = 16;
	};
}
