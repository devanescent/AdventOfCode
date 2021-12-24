#pragma once
#include "InputProcessor.h"

namespace AdventOfCode::Year2021::Day22
{
	class RebootStep
	{
	public:
		bool NewState;
		int FromX, ToX;
		int FromY, ToY;
		int FromZ, ToZ;

		bool operator==(const RebootStep& other) const
		{
			return NewState == other.NewState
				&& FromX == other.FromX && ToX == other.ToX
				&& FromY == other.FromY && ToY == other.ToY
				&& FromZ == other.FromZ && ToZ == other.ToZ;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%s X=%d..%d, Y=%d..%d, Z=%d..%d", 
				NewState ? "on" : "off", FromX, ToX, FromY, ToY, FromZ, ToZ);
			return std::string(buf);
		}
	};

	class RebootStepProcessor : public InputProcessorBase<RebootStep>
	{
	public:
		std::vector<RebootStep> Process(std::vector<std::string> input) override;
	};
}