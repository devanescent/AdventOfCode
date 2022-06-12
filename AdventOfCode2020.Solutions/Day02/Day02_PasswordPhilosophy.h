#pragma once
#include "DayT.h"
#include "PasswordPolicy.h"
#include "PasswortPolicyProcessor.h"

namespace AdventOfCode::Year2020::Day02
{
	class PasswordPhilosophy : public DayT<PasswortPolicyProcessor>
	{
	public:
		PasswordPhilosophy();

	protected:
		uint64_t ExecutePart1(std::vector<PasswordPolicy> passwords) override;
	};
}