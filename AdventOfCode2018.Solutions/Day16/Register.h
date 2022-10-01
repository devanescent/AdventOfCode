#pragma once
#include <array>
#include <string>
#include <sstream>

namespace AdventOfCode::Year2018::Day16
{
	enum class OpCode
	{
		unknown, 

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
			for (uint64_t& r : m_regValues)
			{
				iss >> r;
				iss >> comma;
			}
		}

		uint64_t& operator[](int index)
		{
			return m_regValues[index];
		}

		bool operator==(const Register<N>& other) const
		{
			return m_regValues == other.m_regValues;
		}

	private:
		std::array<uint64_t, N> m_regValues;
	};
}