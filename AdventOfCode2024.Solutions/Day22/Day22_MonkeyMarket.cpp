#include "Day22_MonkeyMarket.h"
#include <map>
#include <set>
#include <tuple>

namespace AdventOfCode::Year2024::Day22
{
	MonkeyMarket::MonkeyMarket() : DayT(22, "Monkey Market") { }

	uint64_t NextSecretNumber(uint64_t secret)
	{
		auto mulBy64 = secret * 64;
		secret = (secret ^ mulBy64) % 16777216; // Mix and prune

		auto devBy32 = secret / 32;
		secret = (secret ^ devBy32) % 16777216; // Mix and prune

		auto mulBy2048 = secret * 2048;
		secret = (secret ^ mulBy2048) % 16777216; // Mix and prune

		return secret;
	}

	uint64_t MonkeyMarket::ExecutePart1(std::vector<int> secretNumbers)
	{
		uint64_t secretNumberSum = 0;

		for (const int& initialSecretNumber : secretNumbers)
		{
			// Calculate 2000 secret numbers:
			uint64_t currentSecret = initialSecretNumber;
			for (int i = 0; i < 2000; ++i)
				currentSecret = NextSecretNumber(currentSecret);

			// Add up each buyer's 2000th secret number:
			secretNumberSum += currentSecret;
		}

		return secretNumberSum;
	}

	using PriceDiffs = std::tuple<int, int, int, int>;

	uint64_t MonkeyMarket::ExecutePart2(std::vector<int> secretNumbers)
	{
		std::map<PriceDiffs, uint64_t> totalEarnedBananas;

		for (const int& initialSecretNumber : secretNumbers)
		{
			// Price diff sequences in each buyer's secret numbers:
			// (each sequence can only be used the first time it's encountered)
			std::set<PriceDiffs> previousPriceDiffs;
			PriceDiffs diffs;

			// Calculate 2000 secret numbers and the price differences:
			uint64_t currentSecret = initialSecretNumber;
			for (int i = 0; i < 2000; ++i)
			{
				auto lastPrice = currentSecret % 10;
				currentSecret = NextSecretNumber(currentSecret);

				auto currentPrice = currentSecret % 10;

				diffs = PriceDiffs(std::get<1>(diffs), std::get<2>(diffs), std::get<3>(diffs), currentPrice - lastPrice);
				if (i >= 3)
				{
					if (!previousPriceDiffs.contains(diffs))
					{
						previousPriceDiffs.insert(diffs);

						// Add bananas earned to total collection:
						totalEarnedBananas[diffs] += currentPrice;
					}
				}
			}
		}

		return std::max_element(totalEarnedBananas.begin(), totalEarnedBananas.end(),
			[](const auto& a, const auto& b) { return a.second < b.second; }
		)->second;
	}
}
