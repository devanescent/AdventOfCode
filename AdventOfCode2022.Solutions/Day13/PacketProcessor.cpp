#include "PacketProcessor.h"

namespace AdventOfCode::Year2022::Day13
{
	std::vector<std::unique_ptr<Packet>> PacketProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::unique_ptr<Packet>> packets;

		auto lineIt = input.begin();
		while (lineIt != input.end())
		{
			// Skip empty line between packet pairs:
			if (lineIt->empty())
				++lineIt;

			packets.emplace_back(std::move(BuildPacket(*lineIt)));
			++lineIt;
		}

		return packets;
	}

	std::unique_ptr<Packet> PacketProcessor::BuildPacket(const std::string& packet)
	{
		std::unique_ptr<Packet> root = nullptr;
		Packet* currentPkt = nullptr;

		std::string currentNum;
		for (const char c : packet)
		{
			if (c == '[')
			{
				// create an empty list packet:
				if (!currentPkt)
				{
					// Outermost packet:
					root = std::make_unique<Packet>(currentPkt);
					currentPkt = root.get();
				}
				else
				{
					// List within a packet:
					currentPkt = currentPkt->AddPacketToList(std::make_unique<Packet>(currentPkt));
				}
			}
			else if (c >= '0' && c <= '9')
			{
				// Build number:
				currentNum += c;
			}
			else if (c == ',')
			{
				// Add number to current list:
				if (!currentNum.empty())
				{
					// Add number to current list:
					currentPkt->AddPacketToList(std::make_unique<Packet>(std::stoi(currentNum), currentPkt));
					currentNum.clear();
				}
			}
			else if (c == ']')
			{
				if (!currentNum.empty())
				{
					// Add number to current list:
					currentPkt->AddPacketToList(std::make_unique<Packet>(std::stoi(currentNum), currentPkt));
					currentNum.clear();
				}
				currentPkt = currentPkt->Parent;
			}
		}

		return root;
	}
}
