#include "Day07_TheSumOfItsParts.h"
#include <algorithm>
#include <map>
#include <set>

namespace AdventOfCode::Year2018::Day07
{
	TheSumOfItsParts::TheSumOfItsParts(int numWorkers, int workTimeOffset) : 
		DayT(7, "The Sum of Its Parts"), m_numWorkers(numWorkers), m_workTimeOffset(workTimeOffset)
	{}

	uint64_t TheSumOfItsParts::ExecutePart1(std::vector<InstructionStep> steps)
	{
		std::string result;

		std::set<InstructionStep> unavailableSteps(steps.begin(), steps.end());
		std::set<InstructionStep> availableSteps;
		
		while (!unavailableSteps.empty() || !availableSteps.empty())
		{
			// Check which steps are available now:
			auto unavailStep = unavailableSteps.begin();
			while (unavailStep != unavailableSteps.end())
			{
				if (unavailStep->CheckPreconditions(result))
				{
					availableSteps.insert(*unavailStep);
					unavailStep = unavailableSteps.erase(unavailStep);
				}
				else
					unavailStep++;
			}

			// Add the next available steps to the result:
			auto nextStep = availableSteps.begin();
			result.push_back(nextStep->ID());
			availableSteps.erase(nextStep);
		}

		return 0;
	}

	uint64_t TheSumOfItsParts::ExecutePart2(std::vector<InstructionStep> steps)
	{
		std::string result;
		uint64_t totalTime = 0;

		std::set<InstructionStep> unavailableSteps(steps.begin(), steps.end());
		std::set<InstructionStep> availableSteps;

		// Time worked on instructions (ordering of keys not neccessary):
		std::map<InstructionStep, int> workedOnSteps;

		while (!unavailableSteps.empty() || !availableSteps.empty() || !workedOnSteps.empty())
		{
			// Check which steps are available now:
			auto unavailStep = unavailableSteps.begin();
			while (unavailStep != unavailableSteps.end())
			{
				if (unavailStep->CheckPreconditions(result))
				{
					availableSteps.insert(*unavailStep);
					unavailStep = unavailableSteps.erase(unavailStep);
				}
				else
					unavailStep++;
			}

			// Add the next available steps to the worked-on set:
			auto nextStep = availableSteps.begin();
			while (nextStep != availableSteps.end() && workedOnSteps.size() < m_numWorkers)
			{
				workedOnSteps.insert(std::make_pair(*nextStep, 0));
				nextStep = availableSteps.erase(nextStep);
			}

			// Work on the steps:
			// Find element with smallest remaining work time:
			auto workTimeLeft = [&](const std::pair<const InstructionStep, int>& workItem)
			{
				// 'A' - '@' == 1, so that 'A' resolves to workTimeOffset + 1, 'B' to workTimeOffset + 2, ...
				return workItem.second >= (workItem.first.ID() - '@') + m_workTimeOffset
					? 0
					: m_workTimeOffset + (workItem.first.ID() - '@') - workItem.second;
			};

			if (!workedOnSteps.empty())
			{
				auto nextReady = std::min_element(workedOnSteps.begin(), workedOnSteps.end(),
					[&workTimeLeft](const auto& step1, const auto& step2)
					{
						int remTime1 = workTimeLeft(step1);
						int remTime2 = workTimeLeft(step2);

						// If multiple items are ready simultaneously, return alphabetically
						if (remTime1 != remTime2)
							return workTimeLeft(step1) < workTimeLeft(step2);
						else
							return step1.first.ID() < step2.first.ID();
					}
				);

				// Complete the next item and update worktime on other items:
				int workTime = workTimeLeft(*nextReady);
				for (auto& step : workedOnSteps)
					step.second += workTime;
				totalTime += workTime;

				result.push_back(nextReady->first.ID());
				workedOnSteps.erase(nextReady);
			}
		}

		return totalTime;
	}

}
