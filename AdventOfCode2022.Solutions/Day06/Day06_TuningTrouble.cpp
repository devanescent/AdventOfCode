#include "Day06_TuningTrouble.h"
#include <set>

namespace AdventOfCode::Year2022::Day06
{
	TuningTrouble::TuningTrouble() : Day(06, "Tuning Trouble") { }

	uint64_t FindPacketMarker(const std::string& dataStream, int numberOfUniqueChars)
	{
		// Find start-of-packet-marker: first segment of required length without repeating characters:
		auto packetMarkerStart = dataStream.begin();
		auto packetMarkerEnd = dataStream.begin() + numberOfUniqueChars;

		while (packetMarkerEnd != dataStream.end())
		{
			// Create set to "remove" duplicate characters:
			std::set<char> startOfPacket(packetMarkerStart, packetMarkerEnd);

			if (startOfPacket.size() == numberOfUniqueChars)
				return packetMarkerEnd - dataStream.begin();
			else
			{
				++packetMarkerStart;
				++packetMarkerEnd;
			}
		}

		return 0ull;
	}

	uint64_t TuningTrouble::GetResultOnPart1(std::vector<std::string> input)
	{
		return FindPacketMarker(input[0], 4);
	}

	uint64_t TuningTrouble::GetResultOnPart2(std::vector<std::string> input)
	{
		return FindPacketMarker(input[0], 14);
	}
}
