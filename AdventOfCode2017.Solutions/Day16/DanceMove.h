#pragma once
#include <algorithm>

namespace AdventOfCode::Year2017::Day16
{
	class DanceMove
	{
	public:
		virtual void Execute(std::vector<char>& programs) const = 0;
	};

	class Spin : public DanceMove
	{
	public:
		Spin(int spinSize) : m_spinSize(spinSize) {}

		void Execute(std::vector<char>& programs) const override
		{
			std::rotate(programs.rbegin(), programs.rbegin() + m_spinSize, programs.rend());
		}

	private:
		int m_spinSize;
	};

	class Exchange : public DanceMove
	{
	public:
		Exchange(int posA, int posB) : m_posA(posA), m_posB(posB) {}

		void Execute(std::vector<char>& programs) const override
		{
			std::swap(programs[m_posA], programs[m_posB]);
		}

	private:
		int m_posA;
		int m_posB;
	};

	class Partner : public DanceMove
	{
	public:
		Partner(char prgmA, char prgmB) : m_prgmA(prgmA), m_prgmB(prgmB) {}

		void Execute(std::vector<char>& programs) const override
		{
			auto posPrgmA = std::find(programs.begin(), programs.end(), m_prgmA);
			auto posPrgmB = std::find(programs.begin(), programs.end(), m_prgmB);
			std::swap(*posPrgmA, *posPrgmB);
		}

	private:
		char m_prgmA;
		char m_prgmB;
	};
}
