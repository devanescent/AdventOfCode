#pragma once
#include "AluInstruction.h"
#include "CharDigitConverter.h"

namespace AdventOfCode::Year2021::Day24
{
	struct ALU
	{
		// Register:
		int64_t W = 0;
		int64_t X = 0;
		int64_t Y = 0;
		int64_t Z = 0;

	private:
		int64_t& GetRegisterByName(std::string_view regName)
		{
			if (regName == "w")
				return W;
			else if (regName == "x")
				return X;
			else if (regName == "y")
				return Y;
			else
				return Z;
		}

		int64_t GetValue(const std::string& operand)
		{
			if (operand[0] >= 'w' && operand[0] <= 'z')
				return GetRegisterByName(operand);
			else
				return std::stoll(operand);
		}

	public:

		void ApplyInstruction(const AluInstruction& instr, std::string& inputData)
		{
			auto& reg = GetRegisterByName(instr.Operand1);

			switch (instr.Operation)
			{
				case InstructionType::Input:
				{
					// Read next input digit:
					reg = CharToDigit<int>(inputData[0]);
					inputData.erase(inputData.begin());
					break;
				}
				case InstructionType::Add:
				{
					auto val = GetValue(instr.Operand2);
					reg += val;
					break;
				}
				case InstructionType::Multiply:
				{
					auto val = GetValue(instr.Operand2);
					reg *= val;
					break;
				}
				case InstructionType::Divide:
				{
					auto val = GetValue(instr.Operand2);
					reg /= val;
					break;
				}
				case InstructionType::Modulo:
				{
					auto val = GetValue(instr.Operand2);
					reg %= val;
					break;
				}
				case InstructionType::Equal:
				{
					auto val1 = GetValue(instr.Operand1);
					auto val2 = GetValue(instr.Operand2);
					reg = val1 == val2 ? 1 : 0;
					break;
				}
			}
		}
	};
}
