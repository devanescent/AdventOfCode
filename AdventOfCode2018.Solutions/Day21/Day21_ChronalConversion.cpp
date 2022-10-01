#include "Day21_ChronalConversion.h"
#include "..\Day19\Program.h"

#include <algorithm>

namespace AdventOfCode::Year2018::Day21
{
	ChronalConversion::ChronalConversion() : DayTC(21, "Chronal Conversion") {}

	// Reuse classes:
	using Program = AdventOfCode::Year2018::Day19::Program;

	template<int N>
	using Register = AdventOfCode::Year2018::Day16::Register<N>;

	uint64_t ChronalConversion::ExecutePart1(std::vector<Instruction> program, int instrPtrReg)
	{
		// This code depends on the following assumptions after evaluating the input:
		// 1. There is just one single instruction that depends on the register 0.
		// 2. This instruction is 'eqrr'.
		// 3. No other instruction changes the value in register 0.

		// Therefore, the only way to alter the execution flow of the program is to alter 
		// the result of this single instruction.

		// Find the single instruction that is depending on the contents in register 0:
		auto dependantInstr = std::find_if(program.begin(), program.end(),
			[](const Instruction& instr) { return instr.DependsOnReg(0); }
		);

		// Index of this instruction
		int dependantInstrIx = static_cast<int>(dependantInstr - program.begin());

		// Execute the program until the dependant instruction is executed:
		Register<6> reg;
		Program prog(program);
		prog.ExecuteUntil(instrPtrReg, reg, [dependantInstrIx](int instrIx) { return instrIx == dependantInstrIx; });

		// At this point, the value in register 0 is compared to another value -> find the value to compare against
		int compRegIx = dependantInstr->GetA() == 0 ? dependantInstr->GetB() : dependantInstr->GetA();

		// This value must be put in register 0 to alter the program flow:
		return reg[compRegIx];
	}

	uint64_t ChronalConversion::ExecutePart2(std::vector<Instruction> program, int instrPtrReg)
	{
		// Try detecting a cycle in possible values
		std::vector<uint64_t> comparisonValues;

		auto dependantInstr = std::find_if(program.begin(), program.end(),
			[](const Instruction& instr) { return instr.DependsOnReg(0); }
		);

		int dependantInstrIx = static_cast<int>(dependantInstr - program.begin());

		Register<6> reg;
		Program prog(program);

		int currentInstr = 0;
		while (true)
		{
			currentInstr = prog.ExecuteUntil(instrPtrReg, reg, [dependantInstrIx](int instrIx) { return instrIx == dependantInstrIx; }, currentInstr);
			int compRegIx = dependantInstr->GetA() == 0 ? dependantInstr->GetB() : dependantInstr->GetA();

			if (std::find(comparisonValues.begin(), comparisonValues.end(), reg[compRegIx]) == comparisonValues.end())
				comparisonValues.push_back(reg[compRegIx]);
			else
				break;
		}
		
		return comparisonValues.back();
	}
}