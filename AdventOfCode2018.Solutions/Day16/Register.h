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

	// For extracting opcodes by name from a stringstream
	std::istringstream& operator>>(std::istringstream& in, OpCode& opCode);

	template<int N>
	class Register
	{
	public:
		Register() :
			m_regValues{ 0 }
		{}

		Register(const std::string& regStr) :
			m_regValues()
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

		bool operator==(const Register<N>& other) const
		{
			return m_regValues == other.m_regValues;
		}

	private:
		std::array<int, N> m_regValues;
	};
}