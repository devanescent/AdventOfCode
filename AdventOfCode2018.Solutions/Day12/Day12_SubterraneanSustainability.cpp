#include "Day12_SubterraneanSustainability.h"
#include <algorithm>

namespace AdventOfCode::Year2018::Day12
{
	// Helper:
	// Pad pot list with empty pots for easier matching of rules 
	// so there are at least 5 empty pots at each ends
	// 
	// For comparisons in part 2 remove padding before first / after last pot
	void AddOrRemovePaddingPots(PotRow& pots, int64_t& startingIndex, bool addPadding)
	{
		auto hasPlant = [](char pot) { return pot == '#'; };

		// Assume there is always a pot with a plant in it present:
		auto emptyPotsAtStart = pots.find('#');
		if (addPadding && emptyPotsAtStart < 5)
		{
			std::string frontPadding(5 - emptyPotsAtStart, '.');
			pots.insert(0, frontPadding);
			startingIndex -= frontPadding.length();
		}
		else if (!addPadding && emptyPotsAtStart > 0)
		{
			pots.erase(0, emptyPotsAtStart);
			startingIndex += emptyPotsAtStart;
		}

		auto emptyPotsAtEnd = (pots.size() - 1) - pots.rfind('#');
		if (addPadding && emptyPotsAtEnd < 5)
		{
			std::string backPadding(5 - emptyPotsAtEnd, '.');
			pots.append(backPadding);
		}
		else if (!addPadding && emptyPotsAtEnd > 0)
		{
			pots.erase(pots.end() - emptyPotsAtEnd, pots.end());
		}
	}

	void ProcessGeneration(PotRow& pots, int64_t& startingIndex, PlantRules rules)
	{
		AddOrRemovePaddingPots(pots, startingIndex, true);
		PotRow nextGeneration(pots);

		// View pots in groups of 5
		for (auto potIt = pots.begin() + 2, nextGenPotIt = nextGeneration.begin() + 2; potIt != pots.end() - 2; ++potIt, ++nextGenPotIt)
		{
			std::string_view potGroup(potIt - 2, potIt + 3);

			// Update the plant for the next generation:
			auto matchingPlantRule = rules.find(potGroup);
			if (matchingPlantRule != rules.end())
				*nextGenPotIt = matchingPlantRule->second ? '#' : '.';
			else
				// for test case that includes only rules that produce plants:
				*nextGenPotIt = '.';
		}

		// Set next generation as current set of plants:
		pots = nextGeneration;
	}

	SubterraneanSustainability::SubterraneanSustainability() : DayTC(12, "Subterranean Sustainability")
	{ }

	uint64_t SubterraneanSustainability::ExecutePart1(PotRow pots, PlantRules rules)
	{
		int64_t startingIndex = 0LL;

		// Simulate 20 generations:
		for (auto gen = 0; gen < 20; ++gen)
			ProcessGeneration(pots, startingIndex, rules);

		// Sum indices of pots containing plants:
		auto plantIndexSum = 0ULL;
		for (int pIx = 0; pIx < pots.length(); ++pIx)
		{
			if (pots[pIx] == '#')
				plantIndexSum += pIx + startingIndex;
		}

		return plantIndexSum;
	}

	uint64_t SubterraneanSustainability::ExecutePart2(PotRow pots, PlantRules rules)
	{
		int64_t startingIndex = 0LL;

		// Remember previous generation to check if pattern has stabilized:
		// (strip padding from row for correct comparisons)
		PotRow prevGen;
		bool stable = false;
		auto gensUntilStable = 0;

		do
		{
			++gensUntilStable;
			ProcessGeneration(pots, startingIndex, rules);
			AddOrRemovePaddingPots(pots, startingIndex, false);

			if (prevGen != pots)
				prevGen = pots;
			else
				stable = true;

		} while (!stable);

		// Get pattern movement (change in starting index):
		auto prevStart = startingIndex;
		ProcessGeneration(pots, startingIndex, rules);
		AddOrRemovePaddingPots(pots, startingIndex, false);
		auto indexDiff = startingIndex - prevStart;

		// Calculate starting index of the pattern after 50000000000 generations
		// (minus generations already processed until stabilization and the one for getting the movement)
		startingIndex = startingIndex + (50000000000 - (gensUntilStable + 1)) * indexDiff;

		// Sum indices of pots containing plants:
		auto plantIndexSum = 0ULL;
		for (int pIx = 0; pIx < pots.length(); ++pIx)
		{
			if (pots[pIx] == '#')
				plantIndexSum += pIx + startingIndex;
		}

		return plantIndexSum;
	}
}
