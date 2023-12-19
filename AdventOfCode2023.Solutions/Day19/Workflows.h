#pragma once
#include <string>
#include <vector>
#include "MachinePart.h"

namespace AdventOfCode::Year2023::Day19
{
	enum class ComparisonOp
	{
		Less,
		Greater
	};

	class WorkflowRule
	{
	public:
		char Category;
		ComparisonOp ComparisonOp;
		int Limit;

		bool IsFallback;	// Last rule
		std::string Result; // Can be another rule or 'A' for accepted or 'R' for rejected
	};


	class Workflow
	{
	public:
		std::string Name;
		std::vector<WorkflowRule> Rules;

		std::string ProcessPart(const MachinePart& part) const
		{
			for (const WorkflowRule& rule : Rules)
			{
				if (rule.IsFallback)
					return rule.Result;

				int compVal = 0;
				switch (rule.Category)
				{
					case 'x': compVal = part.X; break;
					case 'm': compVal = part.M; break;
					case 'a': compVal = part.A; break;
					case 's': compVal = part.S; break;
				}

				bool matchesRule = false;
				if (rule.ComparisonOp == ComparisonOp::Less)
					matchesRule = compVal < rule.Limit;
				else
					matchesRule = compVal > rule.Limit;

				if (matchesRule)
					return rule.Result;
			}
		}

		std::vector<std::pair<std::string, MachinePartRange>> ProcessPartRange(MachinePartRange partRange) const
		{
			std::vector<std::pair<std::string, MachinePartRange>> newPartRanges;

			for (const WorkflowRule& rule : Rules)
			{
				if (rule.IsFallback)
					newPartRanges.emplace_back(std::make_pair(rule.Result, partRange));
				else
				{
					Range<int>& compRange = partRange.GetRange(rule.Category);

					// Compare full range against limit
					if (rule.ComparisonOp == ComparisonOp::Less)
					{
						if (compRange.End < rule.Limit)
						{
							// Full range is less than the limit and satisfies the rule:
							newPartRanges.emplace_back(std::make_pair(rule.Result, partRange));
						}
						else
						{
							// Split range into matched and unmatched part:
							Range<int> unmatchedRange{ rule.Limit, compRange.End };

							compRange.End = rule.Limit - 1;
							newPartRanges.emplace_back(std::make_pair(rule.Result, partRange));

							// Continue with remaining (unmatched) range:
							compRange = unmatchedRange;
						}
					}
					else
					{
						if (compRange.Start > rule.Limit)
						{
							// Full range is greater than the limit and satisfies the rule:
							newPartRanges.emplace_back(std::make_pair(rule.Result, partRange));
						}
						else
						{
							// Split range into matched and unmatched part:
							Range<int> unmatchedRange{ compRange.Start, rule.Limit };

							compRange.Start = rule.Limit + 1;
							newPartRanges.emplace_back(std::make_pair(rule.Result, partRange));

							// Continue with remaining (unmatched) range:
							compRange = unmatchedRange;
						}
					}
				}
			}

			return newPartRanges;
		}
	};
}
