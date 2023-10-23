#include "Day18_Duet.h"
#include <map>
#include <optional>

namespace AdventOfCode::Year2017::Day18
{
	Duet::Duet() : DayT(18, "Duet") { }

	uint64_t Duet::ExecutePart1(std::vector<SoundInstruction> instructions)
	{
		uint64_t lastFreqPlayed = 0;
		std::optional<uint64_t> recoveredFreq = {};

		std::map<char, int64_t> registers;
		auto currentInstr = instructions.begin();

		auto getValue = [&registers](const InstructionParameter& p) -> int64_t
			{
				if (p.ValType == ValueType::Register)
					return registers[static_cast<char>(p.Value)];
				else
					return p.Value;
			};

		// Get the first recovered frequency:
		while (!recoveredFreq.has_value())
		{
			switch (currentInstr->Type)
			{
				case InstructionType::PlaySound:
					lastFreqPlayed = static_cast<uint64_t>(getValue(currentInstr->Param1));
					++currentInstr;
					break;
				case InstructionType::Set:
					registers[static_cast<char>(currentInstr->Param1.Value)] = getValue(currentInstr->Param2);
					++currentInstr;
					break;
				case InstructionType::Add:
					registers[static_cast<char>(currentInstr->Param1.Value)] += getValue(currentInstr->Param2);
					++currentInstr;
					break;
				case InstructionType::Multiply:
					registers[static_cast<char>(currentInstr->Param1.Value)] *= getValue(currentInstr->Param2);
					++currentInstr;
					break;
				case InstructionType::Modulo:
					registers[static_cast<char>(currentInstr->Param1.Value)] %= getValue(currentInstr->Param2);
					++currentInstr;
					break;
				case InstructionType::RecoverSound:
					if (getValue(currentInstr->Param1) != 0)
						recoveredFreq = lastFreqPlayed;
					++currentInstr;
					break;
				case InstructionType::JumpGreaterZero:
					if (getValue(currentInstr->Param1) > 0)
						currentInstr += getValue(currentInstr->Param2);
					else
						++currentInstr;
					break;
			}
		}

		return recoveredFreq.value_or(0ull);
	}

	uint64_t Duet::ExecutePart2(std::vector<SoundInstruction> instructions)
	{
		return uint64_t();
	}
}
