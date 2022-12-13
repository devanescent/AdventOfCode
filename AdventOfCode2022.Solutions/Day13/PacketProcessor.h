#pragma once
#include "InputProcessor.h"
#include "Packet.h"

namespace AdventOfCode::Year2022::Day13
{
	class PacketProcessor : public InputProcessorBase<std::unique_ptr<Packet>>
	{
	public:
		std::vector<std::unique_ptr<Packet>> Process(std::vector<std::string> input) override;

	private:
		std::unique_ptr<Packet> BuildPacket(const std::string& packet);
	};
}
