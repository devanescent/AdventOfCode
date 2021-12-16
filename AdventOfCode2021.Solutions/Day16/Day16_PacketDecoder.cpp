#include "Day16_PacketDecoder.h"
#include <bitset>
#include <numeric>

namespace AdventOfCode::Year2021::Day16
{
	PacketDecoder::PacketDecoder() : Day(16, "Packet Decoder") {}

	enum class PacketTypeID
	{
		Literal = 4
		/*otherwise Operator*/
	};

	enum class LengthTypeID
	{
		SubPacketLength,	// 15-bit length 
		SubPacketNum		// 11-bit length
	};

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t PacketDecoder::GetResultOnPart1(const std::vector<std::string> input)
	{
		// Convert Hex representation to binary representation
		const std::string& packet(input[0]);
		std::string binaryPacket;

		for (const char hexchar : packet)
		{
			int val = (hexchar >= 'A') ? (hexchar - 'A' + 10) : (hexchar - '0');
			std::bitset<4> binVal(val);
			binaryPacket += binVal.to_string();
		}

		// Decode packet:
		std::vector<int> versions;
		int dataIx = 0;
		DecodePackets(binaryPacket, dataIx, versions);

		// Add all version numbers:
		return std::accumulate(versions.begin(), versions.end(), 0ull, [](uint64_t versionSum, int version) { return versionSum + version; });
	}

	// ---------------------------------------------------------------------------
	// DecodePackets
	// Processes packet (and recursivly, subpackets), returns the data index of
	// the next packet
	// Adds all version numbers to passed vector
	// ---------------------------------------------------------------------------
	void PacketDecoder::DecodePackets(const std::string& packet, int& dataIx, std::vector<int>& versions)
	{
		int version = DecodeBinaryPacketPart(packet, dataIx, 3);
		versions.push_back(version);

		PacketTypeID packetTypeID = static_cast<PacketTypeID>(DecodeBinaryPacketPart(packet, dataIx, 3));

		// Literal:
		if (packetTypeID == PacketTypeID::Literal)
		{
			bool hasNextPacket;
			do
			{
				hasNextPacket = packet[dataIx] == '1';
				dataIx += 1;

				int num = DecodeBinaryPacketPart(packet, dataIx, 4);
			} while (hasNextPacket);
		}
		// Operator
		else
		{
			LengthTypeID lengthTypeId = static_cast<LengthTypeID>(DecodeBinaryPacketPart(packet, dataIx, 1));

			if (lengthTypeId == LengthTypeID::SubPacketLength)
			{
				int subPacketLength = DecodeBinaryPacketPart(packet, dataIx, 15);
				int subPacketEnd = dataIx + subPacketLength;

				// Process subpackets:
				while (dataIx < subPacketEnd)
					DecodePackets(packet, dataIx, versions);
			}
			else if (lengthTypeId == LengthTypeID::SubPacketNum)
			{
				int subPacketCount = DecodeBinaryPacketPart(packet, dataIx, 11);
				
				// Process subpackets:
				for (int n = 0; n < subPacketCount; ++n)
					DecodePackets(packet, dataIx, versions);
			}
		}
	}

	// ---------------------------------------------------------------------------
	// DecodePacketPart:
	// Returns result from processed part and advances data index behind processed part
	// ---------------------------------------------------------------------------
	int PacketDecoder::DecodeBinaryPacketPart(const std::string& packet, int& dataStart, int dataLen)
	{
		int result = std::stoi(packet.substr(dataStart, dataLen), nullptr, 2);
		dataStart += dataLen;
		return result;
	}
}
