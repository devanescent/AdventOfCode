#include "Day02_PasswordPhilosophy.h"
#include <algorithm>

namespace AdventOfCode::Year2020::Day02
{
	PasswordPhilosophy::PasswordPhilosophy() : DayT(2, "Password Philosophy") {}

	uint64_t PasswordPhilosophy::ExecutePart1(std::vector<PasswordPolicy> passwords)
	{
		return std::count_if(passwords.begin(), passwords.end(), [](PasswordPolicy pp) {return pp.IsValid(); });
	}

	uint64_t PasswordPhilosophy::ExecutePart2(std::vector<PasswordPolicy> passwords)
	{
		return std::count_if(passwords.begin(), passwords.end(), [](PasswordPolicy pp) {return pp.IsOfficiallyValid(); });
	}
}

