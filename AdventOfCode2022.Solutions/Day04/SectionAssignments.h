#pragma once

namespace AdventOfCode::Year2022::Day04
{
	class SectionAssignments
	{
	public:
		int Range1From, Range1To;
		int Range2From, Range2To;

		// Checks if one of the assigned id ranges in fully contained in the other:
		bool IsOneAssignmentFullyContained() const
		{
			return
				Range1From >= Range2From && Range1To <= Range2To ||
				Range2From >= Range1From && Range2To <= Range1To;
		}

		// Checks if there is any overlap between the two assigned id ranges:
		bool AssignmentsOverlap() const
		{
			return IsOneAssignmentFullyContained() ||
				Range1From >= Range2From && Range1From <= Range2To ||
				Range1To >= Range2From && Range1To <= Range2To;
		}
	};
}
