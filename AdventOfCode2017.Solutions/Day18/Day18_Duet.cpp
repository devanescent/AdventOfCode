#include "Day18_Duet.h"
#include <map>
#include <optional>
#include <queue>

namespace AdventOfCode::Year2017::Day18
{
	Duet::Duet() : DayT(18, "Duet") { }

	uint64_t Duet::ExecutePart1(std::vector<SoundInstruction> instructions)
	{
		uint64_t lastFreqPlayed = 0;
		std::optional<uint64_t> recoveredFreq = {};

		std::map<char, int64_t> registers;
		auto currentInstr = instructions.begin();

		
		// Get the first recovered frequency:
		while (!recoveredFreq.has_value())
		{
			currentInstr->Execute1(currentInstr, registers, lastFreqPlayed, recoveredFreq);
		}

		return recoveredFreq.value_or(0ull);
	}

	uint64_t Duet::ExecutePart2(std::vector<SoundInstruction> instructions)
	{
		std::map<char, int64_t> registers1;
		registers1['p'] = 0;

		std::map<char, int64_t> registers2;
		registers1['p'] = 1;
		
		auto currentInstr1 = instructions.begin();
		auto currentInstr2 = instructions.begin();

		std::queue<int64_t> from1To2;
		std::queue<int64_t> from2To1;

		uint64_t sendCnt1 = 0, sendCnt2 = 0;

		bool isDeadlock;

		do
		{
			bool p1Continues = currentInstr1 != instructions.end() && currentInstr1->Execute2(currentInstr1, registers1, from1To2, from2To1, sendCnt1);
			bool p2Continues = currentInstr2 != instructions.end() && currentInstr2->Execute2(currentInstr2, registers2, from2To1, from1To2, sendCnt2);
			
			// programs are running as long as one of them can continue execution:
			isDeadlock = !p1Continues && !p2Continues;

		} while (!isDeadlock);

		return sendCnt1;
	}
}
