#pragma once
#include "InputProcessor.h"
#include "Bag.h"

namespace AdventOfCode::Year2020::Day07
{
	class BagProcessor : public InputProcessorBase<Bag*>
	{
	public:
		std::vector<Bag*> Process(std::vector<std::string> input) override;

	private:
		std::string GetContainerBag(const std::string& bagRule) const;
		std::vector<std::string> GetContainedBags(const std::string& bagRule) const;
	};
}


