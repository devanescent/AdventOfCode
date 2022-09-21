#include "Instruction.h"

namespace AdventOfCode::Year2018::Day16
{
	std::istringstream& operator>>(std::istringstream& in, OpCode& opCode)
	{
		std::string strOpCode;
		in >> strOpCode;

		if (strOpCode == "addr") opCode = OpCode::addr;
		else if (strOpCode == "addi") opCode = OpCode::addi;

		else if (strOpCode == "mulr") opCode = OpCode::mulr;
		else if (strOpCode == "muli") opCode = OpCode::muli;

		else if (strOpCode == "banr") opCode = OpCode::banr;
		else if (strOpCode == "bani") opCode = OpCode::bani;

		else if (strOpCode == "borr") opCode = OpCode::borr;
		else if (strOpCode == "bori") opCode = OpCode::bori;

		else if (strOpCode == "setr") opCode = OpCode::setr;
		else if (strOpCode == "seti") opCode = OpCode::seti;

		else if (strOpCode == "gtir") opCode = OpCode::gtir;
		else if (strOpCode == "gtri") opCode = OpCode::gtri;
		else if (strOpCode == "gtrr") opCode = OpCode::gtrr;

		else if (strOpCode == "eqir") opCode = OpCode::eqir;
		else if (strOpCode == "eqri") opCode = OpCode::eqri;
		else if (strOpCode == "eqrr") opCode = OpCode::eqrr;

		return in;
	}
}