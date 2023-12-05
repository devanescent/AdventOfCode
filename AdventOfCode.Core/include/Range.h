#pragma once
#include <utility>

namespace AdventOfCode
{
	template<typename T>
	struct Range
	{
		T Start;
		T End;
		bool IsEmpty = false;

		Range(T start = 0, T end = 0) : Start(start), End(end), IsEmpty(false)
		{
			if (Start > End) std::swap(Start, End);
		}

		T Length() const
		{
			return IsEmpty ? 0 : End - Start + 1;
		}

		bool OverlapsWith(const Range& other) const
		{
			if (IsEmpty || other.IsEmpty)
				return false;
			else
				return Start >= other.Start && Start <= other.End ||
						 other.Start >= Start && other.Start <= End;
		}

		bool ContainsValue(T value) const
		{
			if (IsEmpty)
				return false;
			else
				return Start <= value && End >= value;
		}

		bool Contains(const Range& other) const
		{
			if (IsEmpty)
				return false;
			else
				return Start <= other.Start && End >= other.End;
		}

		T DistanceTo(const Range& other) const
		{
			if (IsEmpty || other.IsEmpty || OverlapsWith(other))
				return 0;
			else if (End < other.Start)
				return other.Start - End;
			else
				return Start - other.End;
		}

		// Combines overlapping ranges into single range
		// If ranges do not overlap, gap between them is ignored
		Range MergeWith(const Range& other) const
		{
			if (IsEmpty && other.IsEmpty)
				return Range::Empty();
			else if (IsEmpty)
				return other;
			else if (other.IsEmpty)
				return *this;
			else
				return Range(std::min(Start, other.Start), std::max(End, other.End));
		}

		Range Intersect(const Range& other) const
		{
			if (IsEmpty || other.IsEmpty || !OverlapsWith(other))
				return Range::Empty();
			else
				return Range(std::max(Start, other.Start), std::min(End, other.End));
		}

		Range Shift(T diff) const
		{
			return Range(Start + diff, End + diff);
		}

		// Make points sortable, e.g. for using in a map
		bool operator<(const Range<T>& other) const
		{
			if (IsEmpty && other.IsEmpty)
				return false;
			else if (Start != other.Start)
				return Start < other.Start;
			else
				return End < other.End;
		}

		bool operator==(const Range<T>& other) const
		{
			return (IsEmpty && other.IsEmpty) || (Start == other.Start && End == other.End);
		}

		static Range Empty()
		{
			Range emptyRange;
			emptyRange.IsEmpty = true;
			return emptyRange;
		}
	};
}