#pragma once
#include <map>
#include <optional>
#include <queue>

namespace AdventOfCode::Year2017
{
	enum class InstructionType
	{
		PlaySound,
		Set,
		Add,
		Subtract,
		Multiply,
		Modulo,
		RecoverSound,
		JumpGreaterZero,
		JumpNotZero,
	};

	enum ValueType
	{
		None,
		Register,
		Literal
	};

	struct InstructionParameter
	{
		ValueType ValType = ValueType::None;
		int64_t Value = 0ull;

		int64_t GetValue(std::map<char, int64_t>& registers)
		{
			if (ValType == ValueType::Register)
				return registers[static_cast<char>(Value)];
			else
				return Value;
		}
	};

	class Instruction
	{
	public:
		InstructionType Type;
		InstructionParameter Param1;
		InstructionParameter Param2;

		Instruction(InstructionType instrType, InstructionParameter p1, InstructionParameter p2) :
			Type(instrType), Param1(std::move(p1)), Param2(std::move(p2))
		{}

		void Execute1(std::vector<Instruction>::iterator& instrIt, std::map<char, int64_t>& registers, uint64_t& lastSoundPlayed, std::optional<uint64_t>& soundRecovered)
		{
			switch (Type)
			{
				case InstructionType::PlaySound:
					lastSoundPlayed = static_cast<uint64_t>(Param1.GetValue(registers));
					++instrIt;
					break;
				case InstructionType::RecoverSound:
					if (Param1.GetValue(registers) != 0)
						soundRecovered = lastSoundPlayed;
					++instrIt;
					break;
				default:
					ExecuteCommon(instrIt, registers);
					break;
			}
		}

		bool Execute2(std::vector<Instruction>::iterator& instrIt, std::map<char, int64_t>& registers, std::queue<int64_t>& sendQueue, std::queue<int64_t>& recvQueue, uint64_t& sendCnt)
		{
			switch (Type)
			{
				case InstructionType::PlaySound:
					sendQueue.push(Param1.GetValue(registers));
					++sendCnt;
					++instrIt;
					return true;
				case InstructionType::RecoverSound:
					if (!recvQueue.empty())
					{
						registers[static_cast<char>(Param1.Value)] = recvQueue.front();
						recvQueue.pop();
						++instrIt;
						return true;
					}
					else
						return false;
				default:
					ExecuteCommon(instrIt, registers);
					return true;
			}
			return false;
		}

		void ExecuteCommon(std::vector<Instruction>::iterator& instrIt, std::map<char, int64_t>& registers)
		{
			switch (Type)
			{
				case InstructionType::Set:
					registers[static_cast<char>(Param1.Value)] = Param2.GetValue(registers);
					break;
				case InstructionType::Add:
					registers[static_cast<char>(Param1.Value)] += Param2.GetValue(registers);
					break;
				case InstructionType::Subtract:
					registers[static_cast<char>(Param1.Value)] -= Param2.GetValue(registers);
					break;
				case InstructionType::Multiply:
					registers[static_cast<char>(Param1.Value)] *= Param2.GetValue(registers);
					break;
				case InstructionType::Modulo:
					registers[static_cast<char>(Param1.Value)] %= Param2.GetValue(registers);
					break;
				case InstructionType::JumpGreaterZero:
					if (Param1.GetValue(registers) > 0)
					{
						instrIt += Param2.GetValue(registers);
						return;
					}
					break;
				case InstructionType::JumpNotZero:
					if (Param1.GetValue(registers) != 0)
					{
						instrIt += Param2.GetValue(registers);
						return;
					}
					break;
			}
			++instrIt;
		}
	};
}
