#include "Day16_PermutationPromenade.h"
#include <numeric>

namespace AdventOfCode::Year2017::Day16
{
	PermutationPromenade::PermutationPromenade() : DayT(16, "Permutation Promenade") { }

	std::string PermutationPromenade::ExecutePart1(std::vector<std::unique_ptr<DanceMove>> dance)
	{
		std::vector<char> programs(m_prgmCount);
		std::iota(programs.begin(), programs.end(), 'a');

		for (const auto& danceMove : dance)
			danceMove->Execute(programs);

		return std::string(programs.begin(), programs.end());
	}

	std::string PermutationPromenade::ExecutePart2(std::vector<std::unique_ptr<DanceMove>> dance)
	{
		std::vector<char> programs(m_prgmCount);
		std::iota(programs.begin(), programs.end(), 'a');

		// Keep record of previous orders to detect a cycle:
		std::vector< std::vector<char>> prevOrders;

		while (prevOrders.empty() || prevOrders[0] != programs)
		{
			prevOrders.push_back(programs);

			for (const auto& danceMove : dance)
				danceMove->Execute(programs);
		}

		auto order = prevOrders[1'000'000'000 % prevOrders.size()];
		return std::string(order.begin(), order.end());
	}
}
