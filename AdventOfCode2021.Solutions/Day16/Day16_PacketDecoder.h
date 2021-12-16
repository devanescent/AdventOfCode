#pragma once
#include "Day.h"

namespace AdventOfCode::Year2021::Day16
{
	class PacketDecoder : public Day
	{
	public:
		PacketDecoder();

		uint64_t GetResultOnPart1(const std::vector<std::string> input) override;
		uint64_t GetResultOnPart2(const std::vector<std::string> input) override;

	private:
		uint64_t DecodePackets(const std::string& packet, int& dataIx, std::vector<int>& versions);
		uint64_t ProcessLiteralPacket(const std::string& packet, int& dataIx);

		int DecodeBinaryPacketPart(const std::string& packet, int& dataStart, int dataLen);
	};
}