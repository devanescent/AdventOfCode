#pragma once
#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace AdventOfCode::Year2022::Day13
{
	enum class ComparisonResult
	{
		IsEqual,
		IsSmaller,
		IsLarger
	};

	struct Packet
	{
		using Val = int;
		using List = std::vector<std::unique_ptr<Packet>>;

		// Creates an integer packet
		Packet(Packet::Val val, Packet* parent) :
			Data(val), Parent(parent)
		{ }

		// Creates a list packet
		Packet(Packet* parent) :
			Data(Packet::List()), Parent(parent)
		{ }

		Packet* AddPacketToList(std::unique_ptr<Packet> pkt)
		{
			std::get<List>(Data).emplace_back(std::move(pkt));
			return std::get<List>(Data).back().get();
		}

		bool DividerPacket = false;
		std::variant<Val, List> Data;
		Packet* Parent;
	};

	// Separate declaration from definition, because the following methods call each other recursively:
	ComparisonResult ComparePackets(const Packet& lhs, const Packet& rhs);
	ComparisonResult ComparePacketLists(const Packet::List& lhs, const Packet::List& rhs);
}
