#pragma once
#include <array>
#include <string>
#include <sstream>

namespace AdventOfCode::Year2018::Day16
{
	enum class OpCode
	{
		addr,
		addi,

		mulr,
		muli,

		banr,
		bani,

		borr,
		bori,

		setr,
		seti,

		gtir,
		gtri,
		gtrr,

		eqir,
		eqri,
		eqrr
	};

	class Register
	{
	public:
		Register(int r0, int r1, int r2, int r3) :
			m_regValues{ r0, r1, r2, r3 }
		{ }

		Register(const std::string& regStr)
		{
			char comma;
			std::istringstream iss(regStr);
			for (int& r : m_regValues)
			{
				iss >> r;
				iss >> comma;
			}
		}

		int& operator[](int index)
		{
			return m_regValues[index];
		}

		bool operator==(const Register& other) const
		{
			return m_regValues == other.m_regValues;
		}

	private:
		std::array<int, 4> m_regValues;
	};
}