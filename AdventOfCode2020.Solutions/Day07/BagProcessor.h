#pragma once
#include "InputProcessor.h"
#include "Bag.h"
#include <map>

namespace AdventOfCode::Year2020::Day07
{
	class BagProcessor : public InputProcessorBase<Bag, std::map<std::string, Bag>>
	{
	public:
		std::map<std::string, Bag> Process(std::vector<std::string> input) override;
	};
}


