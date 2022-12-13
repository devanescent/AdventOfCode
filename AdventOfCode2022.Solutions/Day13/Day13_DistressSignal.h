#pragma once
#include "DayT.h"
#include "PacketProcessor.h"

namespace AdventOfCode::Year2022::Day13
{
	// ---------------------------------------------------------------------------
	// Day13: Distress Signal
	// ---------------------------------------------------------------------------
	class DistressSignal : public DayT<PacketProcessor>
	{
	public:
		DistressSignal();

	protected:
		uint64_t ExecutePart1(std::vector<std::unique_ptr<Packet>> packets) override;
		uint64_t ExecutePart2(std::vector<std::unique_ptr<Packet>> packets) override;

	private:
		std::unique_ptr<Packet> CreateDividerPacket(Packet::Val val);
	};
}
