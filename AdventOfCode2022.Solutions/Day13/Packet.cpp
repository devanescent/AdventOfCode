#include "Packet.h"

namespace AdventOfCode::Year2022::Day13
{
	ComparisonResult ComparePackets(const Packet& lhs, const Packet& rhs)
	{
		// Both packets hold single values:
		if (std::holds_alternative<Packet::Val>(lhs.Data) && std::holds_alternative<Packet::Val>(rhs.Data))
		{
			int lhsVal = std::get<Packet::Val>(lhs.Data);
			int rhsVal = std::get<Packet::Val>(rhs.Data);

			return (lhsVal == rhsVal)
				? ComparisonResult::IsEqual
				: (lhsVal < rhsVal)
				? ComparisonResult::IsSmaller
				: ComparisonResult::IsLarger;
		}
		// ----------------------------------------------------------------------------------
		// First packet holds value, other packet holds list:
		else if (std::holds_alternative<Packet::Val>(lhs.Data) && std::holds_alternative<Packet::List>(rhs.Data))
		{
			// Convert single value to list:
			Packet::List lhsList;
			lhsList.emplace_back(std::move(std::make_unique<Packet>(std::get<Packet::Val>(lhs.Data), nullptr)));
			return ComparePacketLists(lhsList, std::get<Packet::List>(rhs.Data));
		}
		// ----------------------------------------------------------------------------------
		// First packet holds list, other packet holds value:
		else if (std::holds_alternative<Packet::List>(lhs.Data) && std::holds_alternative<Packet::Val>(rhs.Data))
		{
			// Convert single value to list:
			Packet::List rhsList;
			rhsList.emplace_back(std::move(std::make_unique<Packet>(std::get<Packet::Val>(rhs.Data), nullptr)));
			return ComparePacketLists(std::get<Packet::List>(lhs.Data), rhsList);
		}
		// ----------------------------------------------------------------------------------
		// Both packets hold lists:
		else
		{
			return ComparePacketLists(std::get<Packet::List>(lhs.Data), std::get<Packet::List>(rhs.Data));
		}
	}

	ComparisonResult ComparePacketLists(const Packet::List& lhs, const Packet::List& rhs)
	{
		auto lhsIt = lhs.begin();
		auto rhsIt = rhs.begin();

		while (lhsIt != lhs.end() && rhsIt != rhs.end())
		{
			auto res = ComparePackets(**lhsIt, **rhsIt);
			if (res != ComparisonResult::IsEqual)
				return res;

			++lhsIt;
			++rhsIt;
		}

		if (rhsIt != rhs.end()) // lhs list ran out of items
			return ComparisonResult::IsSmaller;
		else if (lhsIt != lhs.end()) // rhs list ran out of items
			return ComparisonResult::IsLarger;
		else
			return ComparisonResult::IsEqual; // both lists ran out of items
	}
}
