#include "Day25_ComboBreaker.h"

namespace AdventOfCode::Year2020::Day25
{
	ComboBreaker::ComboBreaker() : DayT(25, "Combo Breaker") {}

	uint64_t Day25::ComboBreaker::ExecutePart1(std::vector<int> publicKeys)
	{
		if (publicKeys.size() >= 2)
		{
			int cardKey = publicKeys[0];
			int doorKey = publicKeys[1];

			int cardLoopSize = 0;
			int doorLoopSize = 0;

			// decrypt by brute-force:
			uint64_t result = 1;	// start value
			bool foundCardLoop = false;
			bool foundDoorLoop = false;

			do
			{
				result = Encrypt(7, 1, result);	// continue with value from previous iteration
				if (!foundCardLoop)
				{
					++cardLoopSize;
					foundCardLoop = (result == cardKey);
				}
				
				if (!foundDoorLoop)
				{
					++doorLoopSize;
					foundDoorLoop = (result == doorKey);
				}
				
			} while (!(foundDoorLoop && foundCardLoop)); // loop until both values are found

			return Encrypt(cardKey, doorLoopSize); // would also work the other way round: Encrypt(doorKey, cardLoopSize)
		}

		return 0;
	}

	uint64_t Day25::ComboBreaker::Encrypt(uint64_t subject, int loops, uint64_t startValue)
	{
		uint64_t result = startValue;

		for (int i = 0; i < loops; ++i)
			result = (result * subject) % 20201227;

		return result;
	}
}