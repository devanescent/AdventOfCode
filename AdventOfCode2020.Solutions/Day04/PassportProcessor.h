#pragma once
#include "InputProcessor.h"
#include "Passport.h"

namespace AdventOfCode::Year2020::Day04
{
	class PassportProcessor : public InputProcessorBase<Passport>
	{
	public:
		std::vector<Passport> Process(std::vector<std::string> input) override;

	private:
		Passport ParsePassport(const std::string& passportData);
	};
}

