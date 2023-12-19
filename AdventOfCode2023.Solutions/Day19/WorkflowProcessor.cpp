#include "WorkflowProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2023::Day19
{
	std::pair<std::vector<MachinePart>, std::vector<Workflow>> WorkflowProcessor::Process(std::vector<std::string> input)
	{
		std::vector<MachinePart> machineParts;
		std::vector<Workflow> workflows;

		std::vector<char> compOps{ '<', '>' };

		bool isWorkflow = true;

		for (const std::string& line : input)
		{
			if (line.empty())
			{
				isWorkflow = false;
				continue;
			}

			if (isWorkflow)
			{
				// Parse workflow:
				Workflow wf;

				auto rulesStart = line.find('{');
				wf.Name = line.substr(0, rulesStart);

				std::stringstream iss(line.substr(rulesStart + 1, line.length() - rulesStart - 2));
				
				std::string ruleStr;
				while (std::getline(iss, ruleStr, ','))
				{
					WorkflowRule rule;

					if (ruleStr == "A" || ruleStr == "R" || ruleStr.find_first_of("<>") == std::string::npos)
					{
						rule.IsFallback = true;
						rule.Result = ruleStr;
					}
					else
					{
						rule.IsFallback = false;
						rule.Category = ruleStr[0];
						rule.ComparisonOp = ruleStr[1] == '<' ? ComparisonOp::Less : ComparisonOp::Greater;
						rule.Limit = std::stoi(ruleStr.substr(2));
						rule.Result = ruleStr.substr(ruleStr.find(':') + 1);
					}

					wf.Rules.emplace_back(rule);
				}

				workflows.emplace_back(wf);
			}
			else
			{
				// Parse machine part:
				MachinePart part;
				
				part.X = std::stoi(line.substr(line.find("x=") + 2));
				part.M = std::stoi(line.substr(line.find("m=") + 2));
				part.A = std::stoi(line.substr(line.find("a=") + 2));
				part.S = std::stoi(line.substr(line.find("s=") + 2));

				machineParts.emplace_back(part);
			}

		}

		return std::make_pair(machineParts, workflows);
	}
}
