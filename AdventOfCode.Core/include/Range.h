#pragma once
#include <utility>

namespace AdventOfCode
{
    template<typename T>
    struct Range
    {
        T Start;
        T End;

        Range(T start = 0, T end = 0) : Start(start), End(end)
        {
            if (Start > End) std::swap(Start, End);
        }

        T Length() const
        {
            return End - Start + 1;
        }

        bool OverlapsWith(const Range& other) const
        {
            return other.Start >= Start && other.Start <= End ||
                other.End >= Start && other.End <= End;
        }

        bool Contains(const Range& other) const
        {
            return Start <= other.Start && End >= other.End;
        }

        T DistanceTo(const Range& other) const
        {
            if (OverlapsWith(other))
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
            return Range(std::min(Start, other.Start), std::max(End, other.End));
        }

        // Make points sortable, e.g. for using in a map
        bool operator<(const Range<T>& other) const
        {
            if (Start != other.Start)
                return Start < other.Start;
            else
                return End < other.End;
        }

        bool operator==(const Range<T>& other) const
        {
            return Start == other.Start && End == other.End;
        }
    };
}