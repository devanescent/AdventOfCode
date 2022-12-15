#include "SensorProcessor.h"
#include <regex>

namespace AdventOfCode::Year2022::Day15
{
	std::vector<Sensor> SensorProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Sensor> sensors;

		std::regex sensorPattern = std::regex("Sensor at x=([0-9-]+), y=([0-9-]+)");
		std::regex beaconPattern = std::regex("beacon is at x=([0-9-]+), y=([0-9-]+)");
		std::smatch matches;

		for (const std::string& line : input)
		{
			std::regex_search(line, matches, sensorPattern);
			Point sensorPos(std::stoi(matches[1].str()), std::stoi(matches[2].str()));

			std::regex_search(line, matches, beaconPattern);
			Point beaconPos(std::stoi(matches[1].str()), std::stoi(matches[2].str()));

			sensors.emplace_back(sensorPos, beaconPos);
		}

		return sensors;
	}
}
