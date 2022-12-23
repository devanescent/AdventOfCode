#include "Grove.h"
#include <algorithm>

namespace AdventOfCode::Year2022::Day23
{
	Grove::Grove()
	{
		m_moveProposals.push_back([this](Elf& e) { return ProposeMovingNorth(e); });
		m_moveProposals.push_back([this](Elf& e) { return ProposeMovingSouth(e); });
		m_moveProposals.push_back([this](Elf& e) { return ProposeMovingWest(e); });
		m_moveProposals.push_back([this](Elf& e) { return ProposeMovingEast(e); });
	}

	bool Grove::MoveElves(std::vector<Elf>& elves)
	{
		m_elvesByPosition.clear();
		m_elvesByPosition.insert(elves.begin(), elves.end());

		// First half: propose a move
		std::multiset<Point<int>> proposedMoves;

		for (Elf& elf : elves)
		{
			// Reset proposed move:
			elf.ProposedMove = elf.Pos;

			if (HasAdjacentElf(elf)) // An elf will not move if there is no other elf adjacent
			{
				// Check directions in the current order:
				for (const auto& proposal : m_moveProposals)
				{
					if (proposal(elf))
					{
						proposedMoves.insert(elf.ProposedMove);
						break;
					}
				}
			}
		}

		// Second half: Update positions
		if (proposedMoves.empty())
			return false;

		for (Elf& elf : elves)
		{
			// Check if elf proposed to move at all; only move if they were the only elf to propose that position:
			if (elf.Pos != elf.ProposedMove && proposedMoves.count(elf.ProposedMove) == 1)
				elf.Pos = elf.ProposedMove;
		}

		// Move proposal list to the left (the first item is moved to the back of the list):
		std::rotate(m_moveProposals.begin(), m_moveProposals.begin() + 1, m_moveProposals.end());
		return true;
	}

	// ------------------------------------------------------------------------------
	// Helper functions:

	bool Grove::HasAdjacentElf(const Elf& elf) const
	{
		return m_elvesByPosition.contains(elf.Pos.MoveBy(-1, -1)) ||
			m_elvesByPosition.contains(elf.Pos.MoveYBy(-1)) ||
			m_elvesByPosition.contains(elf.Pos.MoveBy(+1, -1)) ||
			m_elvesByPosition.contains(elf.Pos.MoveXBy(+1)) ||
			m_elvesByPosition.contains(elf.Pos.MoveBy(+1, +1)) ||
			m_elvesByPosition.contains(elf.Pos.MoveYBy(+1)) ||
			m_elvesByPosition.contains(elf.Pos.MoveBy(-1, +1)) ||
			m_elvesByPosition.contains(elf.Pos.MoveXBy(-1));
	}

	bool Grove::ProposeMovingNorth(Elf& elf) const
	{
		// No elf in positions NW, N, NE:
		if (!m_elvesByPosition.contains(elf.Pos.MoveBy(-1, -1)) &&
			!m_elvesByPosition.contains(elf.Pos.MoveYBy(-1)) &&
			!m_elvesByPosition.contains(elf.Pos.MoveBy(+1, -1)))
		{
			elf.ProposedMove = elf.Pos.MoveYBy(-1);
			return true;
		}
		return false;
	}

	bool Grove::ProposeMovingSouth(Elf& elf) const
	{
		// No elf in positions SW, S, SE:
		if (!m_elvesByPosition.contains(elf.Pos.MoveBy(-1, +1)) &&
			!m_elvesByPosition.contains(elf.Pos.MoveYBy(+1)) &&
			!m_elvesByPosition.contains(elf.Pos.MoveBy(+1, +1)))
		{
			elf.ProposedMove = elf.Pos.MoveYBy(+1);
			return true;
		}
		return false;
	}

	bool Grove::ProposeMovingWest(Elf& elf) const
	{
		// No elf in positions NW, W, SW:
		if (!m_elvesByPosition.contains(elf.Pos.MoveBy(-1, +1)) &&
			!m_elvesByPosition.contains(elf.Pos.MoveXBy(-1)) &&
			!m_elvesByPosition.contains(elf.Pos.MoveBy(-1, -1)))
		{
			elf.ProposedMove = elf.Pos.MoveXBy(-1);
			return true;
		}
		return false;
	}

	bool Grove::ProposeMovingEast(Elf& elf) const
	{
		// No elf in positions NE, E, SE:
		if (!m_elvesByPosition.contains(elf.Pos.MoveBy(+1, +1)) &&
			!m_elvesByPosition.contains(elf.Pos.MoveXBy(+1)) &&
			!m_elvesByPosition.contains(elf.Pos.MoveBy(+1, -1)))
		{
			elf.ProposedMove = elf.Pos.MoveXBy(+1);
			return true;
		}
		return false;
	}
}