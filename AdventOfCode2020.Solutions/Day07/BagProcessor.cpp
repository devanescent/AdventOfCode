#include "BagProcessor.h"
#include <algorithm>
#include <map>
#include <regex>

namespace AdventOfCode::Year2020::Day07
{
	std::vector<Bag*> BagProcessor::Process(std::vector<std::string> input)
	{
		std::map<std::string, Bag*> bagsByName;

		for (const std::string& line : input)
		{
			// Helper: Finds bag or inserts it, if not exists
			auto FindOrInsert = [&bagsByName](std::string bag)
			{
				auto it = bagsByName.find(bag);
				if (it == bagsByName.end())
					it = bagsByName.insert(bagsByName.begin(), std::make_pair(bag, new Bag(bag)));

				return it;
			};

			// Container:
			std::string containerBagName = GetContainerBag(line);
			auto container = FindOrInsert(containerBagName);

			// Contents: reference to their container(s)
			for (const std::string contentBagName : GetContainedBags(line))
			{
				auto content = FindOrInsert(contentBagName);
				content->second->AddContainer(container->second);
			}
		}

		// transform values from map in vector:
		std::vector<Bag*> bags;
		bags.reserve(input.size());
		std::transform(bagsByName.begin(), bagsByName.end(), std::back_inserter(bags), 
			[](const std::pair<std::string, Bag*>& b) { return b.second; });

		return bags;
	}

	std::string BagProcessor::GetContainerBag(const std::string& bagRule) const
	{
		// RegEx: beginning of the line: words and / or spaces, followed by the term ' bags contain' (positive lookahead)
		// gets the name from the bag mentioned at the beginning
		std::regex containerPattern = std::regex("^(?:[a-z]| )+(?= bags contain)");

		std::smatch matches;
		if (std::regex_search(bagRule, matches, containerPattern))
			return matches[0].str();
		else
			return "";
	}

	std::vector<std::string> BagProcessor::GetContainedBags(const std::string& bagRule) const
	{
		// RegEx: number with words and / or spaces, followed by the term 'bag(s)' (positive lookahead)
		// gets all bag names listed as content
		std::regex containerPattern = std::regex("[0-9]+ ((?:[a-z]| )+)(?= bags?)");

		std::vector<std::string> bagContents;
		std::smatch matches;
		if (std::regex_search(bagRule, matches, containerPattern))
		{
			for (auto& m : matches)
				bagContents.push_back(m.str());
		}

		return bagContents;
	}
}

