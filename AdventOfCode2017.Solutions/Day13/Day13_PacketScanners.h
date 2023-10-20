#pragma once
#include "DayT.h"
#include "FirewallProcessor.h"

namespace AdventOfCode::Year2017::Day13
{
	// ---------------------------------------------------------------------------
	// Day13: Packet Scanners
	// ---------------------------------------------------------------------------
	class PacketScanners : public DayT<FirewallProcessor>
	{
	public:
		PacketScanners();

	protected:
		uint64_t ExecutePart1(std::vector<FirewallLayer> fwLayers) override;
		uint64_t ExecutePart2(std::vector<FirewallLayer> fwLayers) override;
	};
}
