#pragma once
#include "InputProcessorWithContext.h"
#include <string>
#include <utility>

namespace AdventOfCode::Year2021::Day14
{
	using PolymerPair = std::pair<char, char>;

	struct PolymerRule
	{
		PolymerRule(char left, char right, char mid) : PolyPair(left, right), InsertedElement(mid) {}

		PolymerPair PolyPair;
		char InsertedElement;

		bool operator==(const PolymerRule& other) const
		{
			return PolyPair == other.PolyPair && InsertedElement == other.InsertedElement;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%c%c -> %c", PolyPair.first, PolyPair.second, InsertedElement);
			return std::string(buf);
		}
	};

	class PolymerProcessor : public InputProcessorWithContextBase<PolymerRule, std::string>
	{
	public:
		virtual std::pair<std::vector<PolymerRule>, std::string> Process(std::vector<std::string> input) override;
	};

}