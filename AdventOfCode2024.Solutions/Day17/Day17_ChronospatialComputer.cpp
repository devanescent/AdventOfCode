#include "Day17_ChronospatialComputer.h"
#include <map>
#include <iostream>

namespace AdventOfCode::Year2024::Day17
{
	ChronospatialComputer::ChronospatialComputer() : DayTC(17, "Chronospatial Computer") { }

	std::string ChronospatialComputer::ExecuteProgram(Registers reg) const
	{
		std::string output;

		int instrIndex = 0;
		while (instrIndex < _program.size())
		{
			OpCode op = static_cast<OpCode>(_program[instrIndex]);
			uint64_t operand = _program[instrIndex + 1];

			switch (op)
			{
				case OpCode::adv:
					reg.A = reg.A / std::pow(2ull, reg.GetComboOperand(operand));
					instrIndex += 2;
					break;
				case OpCode::bxl:
					reg.B = reg.B ^ operand;
					instrIndex += 2;
					break;
				case OpCode::bst:
					reg.B = reg.GetComboOperand(operand) % 8;
					instrIndex += 2;
					break;
				case OpCode::jnz:
					if (reg.A != 0)
						instrIndex = operand;
					else
						instrIndex += 2;
					break;
				case OpCode::bxc:
					reg.B = reg.B ^ reg.C;
					instrIndex += 2;
					break;
				case OpCode::out:
					if (!output.empty())
						output += ',';
					output += std::to_string(reg.GetComboOperand(operand) % 8);
					instrIndex += 2;
					break;
				case OpCode::bdv:
					reg.B = reg.A / std::pow(2ull, reg.GetComboOperand(operand));
					instrIndex += 2;
					break;
				case OpCode::cdv:
					reg.C = reg.A / std::pow(2ull, reg.GetComboOperand(operand));
					instrIndex += 2;
					break;
			}
		}

		return output;
	}

	bool ChronospatialComputer::AddNextDigit(const std::string& originalProgram, Registers reg, uint64_t currentResult, uint64_t& finalResult) const
	{
		// Each group of 3 bits (together with up to 7 bits in front of them) determine a single digit
		// The input value in register A is shortened by 3 bits every iteration until it's zero

		// Start from the last value (which is just build from the 3 most-significant bits of the input value)
		// and build up each digit by trying each possible 3-bit value:

		// Note: For the first 3-bit group, 0 is not a valid value
		// (because the loop of the program terminates if the value in register a is zero)
		for (int i = currentResult == 0 ? 1 : 0; i < 8; ++i)
		{
			reg.A = (currentResult << 3) + i;
			std::string currentOutput = ExecuteProgram(reg);

			// Finished:
			if (currentOutput == originalProgram)
			{
				finalResult = reg.A;
				return true;
			}

			if (originalProgram.ends_with(currentOutput))
			{
				// Try adding next digits to current value
				// If not successful, increment until subsequent digits match
				if (AddNextDigit(originalProgram, reg, reg.A, finalResult))
					return true;
			}
		}

		// Not possible with current bit configuration:
		return false;
	}

	std::string ChronospatialComputer::ExecutePart1(std::vector<int> program, Registers reg)
	{
		// Store program for execution:
		_program = program;
		return ExecuteProgram(reg);
	}

	std::string ChronospatialComputer::ExecutePart2(std::vector<int> program, Registers reg)
	{
		// Store program for use during recursion:
		_program = program;

		// Output has to match original program:
		std::string originalProgram;
		for (int op : program)
		{
			if (!originalProgram.empty())
				originalProgram += ',';
			originalProgram += std::to_string(op);
		}

		uint64_t registerA = 0;
		AddNextDigit(originalProgram, reg, 0, registerA);
		return std::to_string(registerA);
	}
}
