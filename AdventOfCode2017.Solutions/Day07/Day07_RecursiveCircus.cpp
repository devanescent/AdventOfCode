#include "Day07_RecursiveCircus.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2017::Day07
{
	RecursiveCircus::RecursiveCircus() : DayT(7, "Recursive Circus") { }

	uint64_t RecursiveCircus::ExecutePart1(std::vector<TowerProgram> prgms)
	{
		auto basePrgmName = GetBasePrgmName(prgms);
		return 0;
	}

	uint64_t RecursiveCircus::ExecutePart2(std::vector<TowerProgram> prgms)
	{
		// Create lookup for programs by name:
		std::map<std::string, TowerProgram*> prgmLookup;

		for (auto& prgm : prgms)
			prgmLookup[prgm.Name] = &prgm;

		// Assign references:
		for (auto& prgm : prgms)
		{
			for (const std::string& name : prgm.BalancedPrgmNames)
				prgm.BalancedPrgms.push_back(prgmLookup[name]);
		}

		auto basePrgm = prgmLookup[GetBasePrgmName(prgms)];

		int correctedWeight;
		basePrgm->CheckBalance(correctedWeight);
		return correctedWeight;
	}

	std::string RecursiveCircus::GetBasePrgmName(std::vector<TowerProgram>& prgms)
	{
		// Trace back tower to its root from an arbitrary program
		std::string basePrgmName = prgms[0].Name;
		auto basePrgm = prgms.end();

		do
		{
			basePrgm = std::find_if(prgms.begin(), prgms.end(),
				[&basePrgmName](const TowerProgram& p)
				{
					return std::find(p.BalancedPrgmNames.begin(), p.BalancedPrgmNames.end(), basePrgmName) != p.BalancedPrgmNames.end();
				});

			if (basePrgm != prgms.end())
				basePrgmName = basePrgm->Name;

		} while (basePrgm != prgms.end());

		return basePrgmName;
	}
}
