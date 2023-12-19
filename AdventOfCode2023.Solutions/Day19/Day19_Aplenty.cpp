#include "Day19_Aplenty.h"
#include <map>
#include <numeric>
#include <queue>

namespace AdventOfCode::Year2023::Day19
{
	Aplenty::Aplenty() : DayTC(19, "Aplenty") { }

	uint64_t Aplenty::ExecutePart1(std::vector<MachinePart> machineParts, std::vector<Workflow> workflows)
	{
		uint64_t acceptedRatingSum = 0;

		// Organize workflows by name:
		std::map<std::string, const Workflow*> workflowsByName;
		for (const auto& workflow : workflows)
			workflowsByName[workflow.Name] = &workflow;

		for (const MachinePart& part : machineParts)
		{
			// All parts begin with the workflow "in":
			std::string nextWorkflow = "in";

			// Process until the part is either accepted or rejected:
			while (nextWorkflow != "R" && nextWorkflow != "A")
				nextWorkflow = workflowsByName[nextWorkflow]->ProcessPart(part);

			// Sum up ratings of all accepted parts:
			if (nextWorkflow == "A")
				acceptedRatingSum += part.GetTotalRating();
		}

		return acceptedRatingSum;
	}

	uint64_t Aplenty::ExecutePart2(std::vector<MachinePart> machineParts, std::vector<Workflow> workflows)
	{
		// Organize workflows by name:
		std::map<std::string, const Workflow*> workflowsByName;
		for (const auto& workflow : workflows)
			workflowsByName[workflow.Name] = &workflow;

		// Process ranges of machine part values:
		std::vector<MachinePartRange> acceptedRanges;

		std::queue<std::pair<std::string, MachinePartRange>> q;
		q.emplace(std::make_pair("in", MachinePartRange{}));

		while (!q.empty())
		{
			const auto [name, partRange] = q.front();
			q.pop();

			// Process range of part ratings by splitting into subranges based on the workflow's rules:
			for (auto&& newRange : workflowsByName[name]->ProcessPartRange(partRange))
			{
				if (newRange.first == "A")
					acceptedRanges.emplace_back(newRange.second);
				else if (newRange.first != "R")
					q.emplace(newRange);
			}
		}

		return std::accumulate(acceptedRanges.begin(), acceptedRanges.end(), 0ull,
			[](uint64_t combinations, const MachinePartRange& partRange)
			{
				return combinations + partRange.GetRatingCombinations();
			});
	}
}
