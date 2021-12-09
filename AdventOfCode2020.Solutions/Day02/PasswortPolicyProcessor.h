#pragma once
#include "InputProcessor.h"
#include "PasswordPolicy.h"

namespace AdventOfCode::Year2020::Day02
{
	class PasswortPolicyProcessor : public InputProcessorBase<PasswordPolicy>
	{
	public:
		std::vector<PasswordPolicy> Process(std::vector<std::string> input) override;
	};
}