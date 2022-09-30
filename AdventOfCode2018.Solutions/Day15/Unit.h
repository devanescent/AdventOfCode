#pragma once

namespace AdventOfCode::Year2018::Day15
{
	class Unit
	{
	public:
		enum class UnitType : char
		{
			Elf = 'E',
			Goblin = 'G'
		};

		Unit(UnitType type) : m_type(type), m_hitPoints(200), m_attackPower(3) {}

		bool IsAlive() const { return m_hitPoints > 0; }
		UnitType GetUnitType() const { return m_type; }
		int GetHitPoints() const { return m_hitPoints; }

		void Attack(Unit& target) const
		{
			target.m_hitPoints -= m_attackPower;
		}

		void IncreaseAttackPower(int inc)
		{
			m_attackPower += inc;
		}

	private:
		UnitType m_type;
		int m_hitPoints;
		int m_attackPower;
	};
}