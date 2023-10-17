#include "Day04_HighEntropyPassphrases.h"
#include <algorithm>
#include <set>

namespace AdventOfCode::Year2017::Day04
{
	HighEntropyPassphrases::HighEntropyPassphrases() : DayT(4, "High-Entropy Passphrases") { }

	uint64_t HighEntropyPassphrases::ExecutePart1(std::vector<std::vector<std::string>> passphrases)
	{
		return std::count_if(passphrases.begin(), passphrases.end(),
			[](const std::vector<std::string>& passphrase)
			{
				// If passphrase is valid (i.e. contains no duplicates), 
				// its set will have the same size as the original list:
				std::set<std::string> passwordSet(passphrase.begin(), passphrase.end());
				return passwordSet.size() == passphrase.size();
			});
	}

	uint64_t HighEntropyPassphrases::ExecutePart2(std::vector<std::vector<std::string>> passphrases)
	{
		return uint64_t();
	}
}
