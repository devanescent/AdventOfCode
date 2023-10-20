#include "FirewallProcessor.h"
#include <algorithm>
#include <sstream>

namespace AdventOfCode::Year2017::Day13
{
	std::vector<FirewallLayer> FirewallProcessor::Process(std::vector<std::string> input)
	{
		std::vector<FirewallLayer> fwLayers;
		fwLayers.reserve(input.size());
		
		std::transform(input.begin(), input.end(), std::back_inserter(fwLayers),
			[](const std::string& line)
			{
				FirewallLayer fwLayer;

				std::istringstream iss(line);
				char colon;
				iss >> fwLayer.Depth >> colon >> fwLayer.Range;

				return fwLayer;
			});

		return fwLayers;
	}
}
