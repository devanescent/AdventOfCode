#include "Day13_DistressSignal.h"
#include <algorithm>

namespace AdventOfCode::Year2022::Day13
{
	bool PacketComparer(const std::unique_ptr<Packet>& lhs, const std::unique_ptr<Packet>& rhs)
	{
		return ComparePackets(*lhs, *rhs) == ComparisonResult::IsSmaller;
	}

	DistressSignal::DistressSignal() : DayT(13, "Distress Signal") { }

	std::unique_ptr<Packet> DistressSignal::CreateDividerPacket(Packet::Val val)
	{
		// Format: [[val]]
		std::unique_ptr<Packet> divPkt = std::make_unique<Packet>(nullptr);

		// Mark the outermost packet as divider packet:
		divPkt->DividerPacket = true;

		// Create the inner list:
		auto innerList = divPkt->AddPacketToList(std::make_unique<Packet>(divPkt.get()));

		// Add the single value to the inner list:
		innerList->AddPacketToList(std::make_unique<Packet>(val, innerList));

		return divPkt;
	}

	uint64_t DistressSignal::ExecutePart1(std::vector<std::unique_ptr<Packet>> packets)
	{
		uint64_t pairIndexSum = 0;
		for (int pktIx = 0, pairIx = 1; pktIx < packets.size(); pktIx += 2, pairIx += 1)
		{
			auto& leftPacket = packets[pktIx];
			auto& rightPacket = packets[pktIx + 1];

			if (PacketComparer(leftPacket, rightPacket))
				pairIndexSum += pairIx;
		}

		return pairIndexSum;
	}

	uint64_t DistressSignal::ExecutePart2(std::vector<std::unique_ptr<Packet>> packets)
	{
		// Add divider packets to list ([[2]] and [[6]]):
		packets.emplace_back(std::move(CreateDividerPacket(2)));
		packets.emplace_back(std::move(CreateDividerPacket(6)));

		std::sort(packets.begin(), packets.end(), PacketComparer);

		uint64_t decoderKey = 1;
		for (int pktIx = 1; pktIx <= packets.size(); ++pktIx)
		{
			if (packets[pktIx - 1]->DividerPacket)
				decoderKey *= pktIx;
		}

		return decoderKey;
	}
}
