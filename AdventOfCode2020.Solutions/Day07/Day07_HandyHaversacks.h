#pragma once
#include "DayT.h"
#include "Bag.h"
#include "BagProcessor.h"

namespace AdventOfCode::Year2020::Day07
{
	class HandyHaversacks : public DayT<Bag*, BagProcessor>
	{
	public:
		HandyHaversacks(std::string bagName);

	protected:
		uint64_t ExecutePart1(std::vector<Bag*> bags) override;

	private:
		std::string m_bagName;
	};
}

