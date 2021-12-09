#include "HeatMapProcessor.h"
#include <algorithm>

namespace AdventOfCode::Year2021::Day09
{
	std::vector<std::vector<HeatMapNode>> HeatMapProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::vector<HeatMapNode>> heatMap;
		heatMap.reserve(input.size());

		for (const std::string row : input)
		{
			std::vector<HeatMapNode> heatMapRow;
			heatMapRow.reserve(row.length());

			// Convert to pairs:
			std::transform(row.begin(), row.end(), std::back_inserter(heatMapRow),
				[](char c) { return HeatMapNode(c - '0'); }
			);

			heatMap.push_back(heatMapRow);
		}

		return heatMap;
	}
}