#include "Utils.h"

namespace AdventOfCode
{
	std::optional<IteratorPair> FindPairForGivenSum(const std::vector<int>& nums, int sum)
	{
		for (auto it1 = nums.begin(); it1 != nums.end(); ++it1)
		{
			for (auto it2 = std::next(nums.begin()); it2 != nums.end(); ++it2)
			{
				if (*it1 + *it2 == sum) return std::make_pair(it1, it2);
			}
		}
		return {};
	}
}
