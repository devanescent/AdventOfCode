#include "PassphraseProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2017::Day04
{
	std::vector<std::vector<std::string>> PassphraseProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::vector<std::string>> passphrases;

		for (const auto& line : input)
		{
			std::vector<std::string> passphrase;

			std::istringstream iss(line);
			std::string word;
			while (iss >> word)
				passphrase.push_back(word);

			passphrases.emplace_back(passphrase);
		}

		return passphrases;
	}
}
