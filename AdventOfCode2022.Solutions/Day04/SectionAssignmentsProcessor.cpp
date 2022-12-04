#include "SectionAssignmentsProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2022::Day04
{
	std::vector<SectionAssignments> SectionAssignmentsProcessor::Process(std::vector<std::string> input)
	{
		// Fill vector with required number of assignments:
		std::vector<SectionAssignments> assignmentPairs(input.size(), SectionAssignments());

		// Set values from input data:
		for (int i = 0; i < input.size(); ++i)
		{
			SectionAssignments& sectionAssignments = assignmentPairs[i];

			std::stringstream iss(input[i]);
			char ignore; // extract hyphen and comma

			iss >> sectionAssignments.Range1From >> ignore >> sectionAssignments.Range1To
				>> ignore
				>> sectionAssignments.Range2From >> ignore >> sectionAssignments.Range2To;
		}

		return assignmentPairs;
	}
}
