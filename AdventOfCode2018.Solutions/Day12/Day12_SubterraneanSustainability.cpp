#include "Day12_SubterraneanSustainability.h"
#include <algorithm>
#include <functional>
#include <numeric>

namespace AdventOfCode::Year2018::Day12
{
	// Helper: Adds empty pots at the front / back of the list of pots
	// for easier matching against the spreading rules:
	void AddPaddingToPots(std::deque<PottedPlant>& pots)
	{
		auto firstPotWithPlant = std::find_if(pots.begin(), pots.end(), std::mem_fn(&PottedPlant::HasPlant));
		for (auto i = std::distance(pots.begin(), firstPotWithPlant); i < 4; ++i)
			pots.emplace_front(pots.front().PotIndex() - 1, false);

		auto lastPotWithPlant = std::find_if(pots.rbegin(), pots.rend(), std::mem_fn(&PottedPlant::HasPlant));
		for (auto i = std::distance(pots.rbegin(), lastPotWithPlant); i < 4; ++i)
			pots.emplace_back(pots.back().PotIndex() + 1, false);
	}

	uint64_t ProcessGenerations(std::deque<PottedPlant>& pots, std::map<std::string, bool> rules, uint64_t numOfGenerations)
	{
		// Initial padding:
		AddPaddingToPots(pots);

		for (auto gen = 1ull; gen <= numOfGenerations; ++gen)
		{
			std::deque<PottedPlant> nextGeneration(pots);

			for (auto pot = pots.begin() + 2, nextGenPot = nextGeneration.begin() + 2; pot != pots.end() - 2; ++pot, ++nextGenPot)
			{
				// Build pattern for this pot depending on its neighbours:
				std::string potPattern;
				std::transform(pot - 2, pot + 3, std::back_inserter(potPattern),
					[](const PottedPlant& pot) { return pot.HasPlant() ? '#' : '.'; }
				);

				// Update the plant for the next generation:
				auto potInNextGen = rules.find(potPattern);
				nextGenPot->SetPlant(potInNextGen != rules.end() && potInNextGen->second);
			}

			// Set next generation as current set of plants:
			pots = nextGeneration;

			// Apply padding, if neccessary
			AddPaddingToPots(pots);
		}

		// Sum indices of pots containing plants:
		return std::accumulate(pots.begin(), pots.end(), 0ull,
			[](uint64_t sum, const PottedPlant& pot)
			{
				return sum + (pot.HasPlant() ? pot.PotIndex() : 0);
			}
		);

	}

	SubterraneanSustainability::SubterraneanSustainability() : DayTC(12, "Subterranean Sustainability")
	{ }

	uint64_t SubterraneanSustainability::ExecutePart1(std::deque<PottedPlant> pots, std::map<std::string, bool> rules)
	{
		return ProcessGenerations(pots, rules, 20);
	}
}
