#pragma once
#include "DayT.h"
#include "ConnectionProcessor.h"

namespace AdventOfCode::Year2024::Day23
{
	// ---------------------------------------------------------------------------
	// Day23: LAN Party
	// ---------------------------------------------------------------------------
	class LANParty : public DayT<ConnectionProcessor, uint64_t, std::string>
	{
	public:
		LANParty();

	protected:
		uint64_t ExecutePart1(std::vector<Connection> connections) override;
		std::string ExecutePart2(std::vector<Connection> connections) override;
	};
}
