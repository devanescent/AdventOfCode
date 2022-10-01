#pragma once
#include "DayT.h"
#include "BagProcessor.h"
#include <map>

namespace AdventOfCode::Year2020::Day07
{
	class HandyHaversacks : public DayT<BagProcessor>
	{
	public:
		HandyHaversacks();

	protected:
		uint64_t ExecutePart1(std::map<std::string, Bag> bags) override;
		uint64_t ExecutePart2(std::map<std::string, Bag> bags) override;

	private:
		std::map<std::string, Bag> m_bags;

		bool CheckBagContents(const Bag& bag, std::map<std::string, bool>& canContainShinyGold);
		uint64_t CountBagContents(const Bag& bag, std::map<std::string, uint64_t>& bagCounts);
	};
}

