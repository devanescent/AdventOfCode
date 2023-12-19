#pragma once
#include "Range.h"

namespace AdventOfCode::Year2023::Day19
{
	// Single machine part with the given ratings:
	class MachinePart
	{
	public:
		int X;
		int M;
		int A;
		int S;

		int GetTotalRating() const
		{
			return X + M + A + S;
		}
	};

	// Collection of machine parts with ratings within the given ranges:
	class MachinePartRange
	{
	public:
		Range<int> X{ 1,4000 };
		Range<int> M{ 1,4000 };
		Range<int> A{ 1,4000 };
		Range<int> S{ 1,4000 };

		Range<int>& GetRange(char category)
		{
			switch (category)
			{
				case 'x': return X;
				case 'm': return M;
				case 'a': return A;
				case 's':
				default : return S;
			}
		}

		uint64_t GetRatingCombinations() const
		{
			return static_cast<uint64_t>(X.Length()) * M.Length() * A.Length() * S.Length();
		}
	};
}
