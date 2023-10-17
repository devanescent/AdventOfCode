#pragma once
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

namespace AdventOfCode::Year2017::Day07
{
	class TowerProgram
	{
	public:
		// From input:
		std::string Name;
		int Weight;
		std::vector<std::string> BalancedPrgmNames;
		
		// Calculated:
		std::vector<TowerProgram*> BalancedPrgms;
		int TotalWeight = -1;

		bool CheckBalance(int& correctedWeight)
		{
			// Tower without sub-structures is balanced:
			if (BalancedPrgms.empty())
				return true;

			// If any sub tower is unbalanced, just return:
			if (!std::all_of(BalancedPrgms.begin(), BalancedPrgms.end(), [&correctedWeight](auto& p) { return p->CheckBalance(correctedWeight); }))
				return false;

			// Otherwise, check if self balanced:
			std::vector<int> weights;
			std::transform(BalancedPrgms.begin(), BalancedPrgms.end(), std::back_inserter(weights), [](TowerProgram* p) { return p->GetWeight(); });

			// All weights equal:
			if (std::all_of(weights.begin(), weights.end(), [&weights](const auto& w) { return w == weights[0]; }))
				return true;
			else
			{
				// Find wrong weight:
				int wrongWeightIx = -1;
				int weightDiff = 0;

				for (int i = 0; i < weights.size(); ++i)
				{
					for (int j = 0; j < weights.size(); ++j)
					{
						if (i != j)
						{
							if (weights[i] == weights[j])
							{
								wrongWeightIx = -1;
								break;
							}
							else
							{
								wrongWeightIx = i;
								weightDiff = weights[j] - weights[i];
							}
						}
					}

					if (wrongWeightIx != -1)
					{
						correctedWeight = BalancedPrgms[wrongWeightIx]->Weight + weightDiff;
						break;
					}
				}

				return false;
			}
		}

	private:
		int GetWeight()
		{
			if (TotalWeight == -1)
				TotalWeight = Weight + std::accumulate(
					BalancedPrgms.begin(), 
					BalancedPrgms.end(), 
					0, 
					[](int totalWeight, const auto pPrgm) { return totalWeight + pPrgm->GetWeight(); });

			return TotalWeight;
		}
	};
}
