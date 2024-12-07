#include "Day07_BridgeRepair.h"
#include <numeric>

namespace AdventOfCode::Year2024::Day07
{
	BridgeRepair::BridgeRepair() : DayT(7, "Bridge Repair") { }

	enum class Operation
	{
		Add,
		Mul,
		Cat
	};

	void EvalNextNumber(Calibration& c, uint64_t result, Operation nextOp, int nextNumIx, bool useCat)
	{
		// Stop evaluation as soon as the calibration was found to be valid:
		if (c.IsValid)
			return;

		if (nextNumIx < c.EquationValues.size())
		{
			switch (nextOp)
			{
				case Operation::Add: result += c.EquationValues[nextNumIx]; break;
				case Operation::Mul: result *= c.EquationValues[nextNumIx]; break;
				case Operation::Cat:
					std::string resultStr = std::to_string(result) + std::to_string(c.EquationValues[nextNumIx]);
					result = std::stoull(resultStr);
					break;
			}
			
			// Try all options for the next number:
			EvalNextNumber(c, result, Operation::Add, nextNumIx + 1, useCat);
			EvalNextNumber(c, result, Operation::Mul, nextNumIx + 1, useCat);
			if (useCat) EvalNextNumber(c, result, Operation::Cat, nextNumIx + 1, true);
		}
		else
		{
			// All numbers have been processed, check test value:
			if (c.TestValue == result)
				c.IsValid = true;
		}
	}

	uint64_t BridgeRepair::ExecutePart1(std::vector<Calibration> calibrations)
	{
		for (auto& c : calibrations)
		{
			// Try adding / multiplying numbers in each possible combination:
			EvalNextNumber(c, 0, Operation::Add, 0, false);
			EvalNextNumber(c, 0, Operation::Mul, 0, false);
		}

		// Sum up test values from valid calibrations:
		return std::accumulate(calibrations.begin(), calibrations.end(), 0ull,
			[](uint64_t totalCalibResult, const Calibration& c)
			{
				return totalCalibResult + (c.IsValid ? c.TestValue : 0);
			});
	}

	uint64_t BridgeRepair::ExecutePart2(std::vector<Calibration> calibrations)
	{
		for (auto& c : calibrations)
		{
			// Try adding / multiplying / concatening numbers in each possible combination:
			EvalNextNumber(c, 0, Operation::Add, 0, true);
			EvalNextNumber(c, 0, Operation::Mul, 0, true);
			EvalNextNumber(c, 0, Operation::Cat, 0, true);
		}

		// Sum up test values from valid calibrations:
		return std::accumulate(calibrations.begin(), calibrations.end(), 0ull,
			[](uint64_t totalCalibResult, const Calibration& c)
			{
				return totalCalibResult + (c.IsValid ? c.TestValue : 0);
			});
	}
}
