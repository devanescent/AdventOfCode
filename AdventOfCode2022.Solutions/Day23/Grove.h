#pragma once
#include "Elf.h"
#include <functional>
#include <set>
#include <vector>

namespace AdventOfCode::Year2022::Day23
{
	// Using a custom comparator for the set of elves that allows using Point<int> for comparisons directly
	// (by defining 'is_transparent')
	struct ElfPosComparer
	{
		using is_transparent = void;

		bool operator()(const Elf& elf1, const Elf& elf2) const
		{
			return elf1.Pos < elf2.Pos;
		}
		bool operator()(const Point<int>& p, const Elf& elf) const
		{
			return p < elf.Pos;
		}
		bool operator()(const Elf& elf, const Point<int>& p) const
		{
			return elf.Pos < p;
		}
	};

	class Grove
	{
	public:
		Grove();
		bool MoveElves(std::vector<Elf>& elves);

	private:
		std::set<Elf, ElfPosComparer> m_elvesByPosition; // Current positions of all elves in the grove
		std::vector<std::function<bool(Elf&)>> m_moveProposals; // Order in which the propsals are evaluated

		bool HasAdjacentElf(const Elf& elf) const;
		bool ProposeMovingNorth(Elf& elf) const;
		bool ProposeMovingSouth(Elf& elf) const;
		bool ProposeMovingWest(Elf& elf) const;
		bool ProposeMovingEast(Elf& elf) const;
	};
}
