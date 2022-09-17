#pragma once
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

namespace AdventOfCode::Year2018::Day24
{
	// A single group of identical units:
	class UnitGroup
	{
	private:
		unsigned int m_unitCount;
		unsigned int m_unitsAlive;

		unsigned int m_hitpoints;
		unsigned int m_attackDamage;
		unsigned int m_attackBoost;
		unsigned int m_initiative;

		std::string m_attackType;
		std::vector<std::string> m_weaknesses;
		std::vector<std::string> m_immunities;

	public:
		UnitGroup(unsigned int count, unsigned int hp, unsigned int atkDmg, unsigned int init,
			std::string atkType, std::vector<std::string> weak, std::vector<std::string> immune) :
			m_unitCount(count), m_unitsAlive(count), m_hitpoints(hp), m_attackDamage(atkDmg), m_attackBoost(0), m_initiative(init),
			m_attackType(atkType), m_weaknesses(weak), m_immunities(immune)
		{}

		unsigned int GetUnitAliveCount() const { return m_unitsAlive; }
		unsigned int GetEffectivePower() const { return GetAttackDamage() * m_unitsAlive; }

		unsigned int GetInitiative() const { return m_initiative; }
		unsigned int GetAttackDamage() const { return m_attackDamage + m_attackBoost; }
		const std::string& GetAttackType() const { return m_attackType; }

		bool IsImmuneTo(const std::string& atkType) const
		{
			return std::find(m_immunities.begin(), m_immunities.end(), atkType) != m_immunities.end();
		}

		bool IsWeakTo(const std::string& atkType) const
		{
			return std::find(m_weaknesses.begin(), m_weaknesses.end(), atkType) != m_weaknesses.end();
		}

		unsigned int GetDamageAgainst(const UnitGroup& other) const
		{
			unsigned int baseDmg = GetEffectivePower();

			if (other.IsImmuneTo(m_attackType))
				baseDmg = 0;
			else if (other.IsWeakTo(m_attackType))
				baseDmg *= 2;

			return baseDmg;
		}

		unsigned int TakeDamageFrom(const UnitGroup& other)
		{
			unsigned int dmg = other.GetDamageAgainst(*this);
			unsigned int unitsLost = std::min(dmg / m_hitpoints, m_unitsAlive); // cannot lose more units as the army contains
			m_unitsAlive -= unitsLost;
			return unitsLost;
		}

		bool IsAlive() const { return m_unitsAlive > 0; }

		void Reset() { m_unitsAlive = m_unitCount; }
		void SetBoost(unsigned int boost) { m_attackBoost = boost; }
	};

	// A single fight that takes place between two unit groups:
	class Fight
	{
		UnitGroup* m_attackingGroup;
		UnitGroup* m_defendingGroup;

	public:
		Fight(UnitGroup* attacker, UnitGroup* defender) :
			m_attackingGroup(attacker), m_defendingGroup(defender)
		{}

		// Attacks in order of initiative:
		unsigned int GetAttackerInitiative() const
		{
			return m_attackingGroup->GetInitiative();
		}

		// Executes the fight and returns the number of units that died:
		unsigned int ExecuteFight()
		{
			if (m_attackingGroup->IsAlive())
				return m_defendingGroup->TakeDamageFrom(*m_attackingGroup);
			else
				return 0;
		}
	};


	class Army
	{
		std::vector<UnitGroup> m_army;

	public:
		// Adds a group of units to this army
		void AddUnitGroup(UnitGroup grp)
		{
			m_army.emplace_back(std::move(grp));
		}

		// Applies an attack boost to all unit gropus of this army
		void ApplyAttackBoost(unsigned int boost)
		{
			for (UnitGroup& grp : m_army)
				grp.SetBoost(boost);
		}

		// Reset the unit counts for all groups in this army:
		void ResetArmy()
		{
			for (UnitGroup& grp : m_army)
				grp.Reset();
		}

		// Returns a list of pointers to all unit groups that are still alive
		std::vector<UnitGroup*> GetActiveUnitsList()
		{
			std::vector<UnitGroup*> ptrList;
			ptrList.reserve(m_army.size());

			for (UnitGroup& grp : m_army)
			{
				if (grp.IsAlive())
					ptrList.push_back(&grp);
			}

			return ptrList;
		}

		// Checks if this army still has units that are alive
		bool ContainsAliveUnits() const
		{
			return std::any_of(m_army.begin(), m_army.end(), [](const UnitGroup& grp) { return grp.IsAlive(); });
		}

		// Sums up number of remaining units
		unsigned int GetNumberOfAliveUnits() const
		{
			unsigned int numOfUnitsAlive = 0;
			return std::accumulate(m_army.begin(), m_army.end(), numOfUnitsAlive,
				[](unsigned int numAlive, const UnitGroup& grp) { return numAlive + grp.GetUnitAliveCount(); }
			);
		}

		// Gets all fights of this army against a defending army
		std::vector<Fight> GetFights(Army& defendingArmy)
		{
			std::vector<Fight> fights;

			std::vector<UnitGroup*> attackers = GetActiveUnitsList();
			std::vector<UnitGroup*> defenders = defendingArmy.GetActiveUnitsList();

			// Target selection phase:
			// Sort attackers in correct order: in decreasing order by effective power first, then by initiative:
			std::sort(attackers.begin(), attackers.end(),
				[](UnitGroup* grp_1, UnitGroup* grp_2)
				{
					if (grp_1->GetEffectivePower() != grp_2->GetEffectivePower())
						return grp_1->GetEffectivePower() > grp_2->GetEffectivePower();
					else
						return grp_1->GetInitiative() > grp_2->GetInitiative();
				}
			);

			for (UnitGroup* attacker : attackers)
			{
				// Find target from immune system:
				auto defender = std::max_element(defenders.begin(), defenders.end(),
					[attacker](const UnitGroup* def1, const UnitGroup* def2)
					{
						// Select target by most damage first:
						unsigned int dmg1 = attacker->GetDamageAgainst(*def1);
						unsigned int dmg2 = attacker->GetDamageAgainst(*def2);

						if (dmg1 != dmg2)
							return dmg1 < dmg2;
						else
						{
							// If equal, then by largest effective power:
							unsigned effPow1 = def1->GetEffectivePower();
							unsigned effPow2 = def2->GetEffectivePower();
							if (effPow1 != effPow2)
								return effPow1 < effPow2;
							else
							{
								// If still equal, then by initiative:
								return def1->GetInitiative() < def2->GetInitiative();
							}
						}
					}
				);

				if (defender != defenders.end() && attacker->GetDamageAgainst(**defender) > 0)
				{
					fights.emplace_back(attacker, *defender);
					defenders.erase(defender); // Each defender can only be targeted once
				}
			}

			return fights;
		}
	};
}