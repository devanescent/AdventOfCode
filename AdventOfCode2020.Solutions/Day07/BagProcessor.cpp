#include "BagProcessor.h"
#include <algorithm>
#include <map>
#include <regex>

namespace AdventOfCode::Year2020::Day07
{
	std::map<std::string, Bag> BagProcessor::Process(std::vector<std::string> input)
	{
		std::map<std::string, Bag> bags;

		// RegEx: beginning of the line: words and / or spaces, followed by the term ' bags contain'
		// -> gets the name from the bag mentioned at the beginning
		std::regex containerPattern = std::regex("^((?:[a-z]| )+) bags contain ");

		// RegEx: number with words and / or spaces, followed by the term 'bag(s)'
		// -> gets all bag names listed as content
		std::regex containedPattern = std::regex("([0-9]+) ((?:[a-z]| )+) bags?");

		for (std::string& line : input)
		{
			std::smatch matches;
			if (std::regex_search(line, matches, containerPattern))
			{
				// Container bag:
				std::string bagName = matches[1].str();
				Bag bag(bagName);
				line = matches.suffix();

				// Contents:
				while (std::regex_search(line, matches, containedPattern))
				{
					if (matches[2].str() != "no other")
						bag.AddBagToContent(matches[2].str(), atoi(matches[1].str().c_str()));
					
					line = matches.suffix();
				}

				bags.emplace(bagName, bag);
			}
		}

		return bags;
	}
}

