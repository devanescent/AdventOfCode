#include "Day16_PacketDecoder.h"
#include <bitset>
#include <numeric>
#include <functional>
#include <algorithm>

namespace AdventOfCode::Year2021::Day16
{
	PacketDecoder::PacketDecoder() : Day(16, "Packet Decoder") {}

	enum class PacketTypeID
	{
		Sum = 0,
		Product = 1,
		Minimum = 2,
		Maximum = 3,
		Literal = 4,
		GreaterThan = 5,
		LessThan = 6,
		Equal = 7
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
	// Part 2:
	// ---------------------------------------------------------------------------
	uint64_t PacketDecoder::GetResultOnPart2(const std::vector<std::string> input)
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
		return DecodePackets(binaryPacket, dataIx, versions);
	}

	// ---------------------------------------------------------------------------
	// DecodePackets
	// Processes packet (and recursivly, subpackets), returns value of packet
	// Adds all version numbers to passed vector
	// ---------------------------------------------------------------------------
	uint64_t PacketDecoder::DecodePackets(const std::string& packet, int& dataIx, std::vector<int>& versions)
	{
		int version = DecodeBinaryPacketPart(packet, dataIx, 3);
		versions.push_back(version);

		PacketTypeID packetTypeID = static_cast<PacketTypeID>(DecodeBinaryPacketPart(packet, dataIx, 3));

		// Literal:
		if (packetTypeID == PacketTypeID::Literal)
		{
			return ProcessLiteralPacket(packet, dataIx);
		}
		// Operator
		else
		{
			std::vector<uint64_t> values;

			LengthTypeID lengthTypeId = static_cast<LengthTypeID>(DecodeBinaryPacketPart(packet, dataIx, 1));

			if (lengthTypeId == LengthTypeID::SubPacketLength)
			{
				int subPacketLength = DecodeBinaryPacketPart(packet, dataIx, 15);
				int subPacketEnd = dataIx + subPacketLength;

				// Process subpackets:
				while (dataIx < subPacketEnd)
					values.push_back(DecodePackets(packet, dataIx, versions));
			}
			else if (lengthTypeId == LengthTypeID::SubPacketNum)
			{
				int subPacketCount = DecodeBinaryPacketPart(packet, dataIx, 11);
				
				// Process subpackets:
				for (int n = 0; n < subPacketCount; ++n)
					values.push_back(DecodePackets(packet, dataIx, versions));
			}

			// Process values:
			switch (packetTypeID)
			{
				case AdventOfCode::Year2021::Day16::PacketTypeID::Sum:
				return std::accumulate(values.begin(), values.end(), 0ull, std::plus<>());

				case AdventOfCode::Year2021::Day16::PacketTypeID::Product:
				return std::accumulate(values.begin(), values.end(), 1ull, std::multiplies<>());

				case AdventOfCode::Year2021::Day16::PacketTypeID::Minimum:
				return std::accumulate(values.begin(), values.end(), UINT64_MAX, [](const auto& a, const auto& b) { return std::min(a, b); });

				case AdventOfCode::Year2021::Day16::PacketTypeID::Maximum:
				return std::accumulate(values.begin(), values.end(), 0ull, [](const auto& a, const auto& b) { return std::max(a, b); });

				case AdventOfCode::Year2021::Day16::PacketTypeID::GreaterThan:
				return static_cast<uint64_t>(values[0] > values[1]);

				case AdventOfCode::Year2021::Day16::PacketTypeID::LessThan:
				return static_cast<uint64_t>(values[0] < values[1]);

				case AdventOfCode::Year2021::Day16::PacketTypeID::Equal:
				return static_cast<uint64_t>(values[0] == values[1]);
			}

			return 42ull;
		}
	}

	// ---------------------------------------------------------------------------
	// ProcessLiteralPacket
	// Gets a number value from a literal packet
	// ---------------------------------------------------------------------------
	uint64_t PacketDecoder::ProcessLiteralPacket(const std::string& packet, int& dataIx)
	{
		bool hasNextPacket;
		uint64_t litVal = 0;

		do
		{
			// Check if last packet:
			hasNextPacket = packet[dataIx] == '1';
			dataIx += 1;

			// Make room for next bits:
			litVal = litVal << 4;

			// Add bits:
			litVal |= DecodeBinaryPacketPart(packet, dataIx, 4);
		} while (hasNextPacket);

		return litVal;
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
