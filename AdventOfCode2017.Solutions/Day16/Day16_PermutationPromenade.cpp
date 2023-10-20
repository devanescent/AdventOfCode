#include "Day16_PermutationPromenade.h"
#include <numeric>

namespace AdventOfCode::Year2017::Day16
{
	PermutationPromenade::PermutationPromenade() : DayT(16, "Permutation Promenade") { }

	uint64_t PermutationPromenade::ExecutePart1(std::vector<std::unique_ptr<DanceMove>> dance)
	{
		std::vector<char> programs(m_prgmCount);
		std::iota(programs.begin(), programs.end(), 'a');

		for (const auto& danceMove : dance)
			danceMove->Execute(programs);

		return 0ull;
	}

	uint64_t PermutationPromenade::ExecutePart2(std::vector<std::unique_ptr<DanceMove>> dance)
	{
		return uint64_t();
	}
}
