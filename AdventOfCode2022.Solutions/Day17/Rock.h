#pragma once
#include "Day.h"
#include <unordered_set>
#include <algorithm>

namespace AdventOfCode::Year2022::Day17
{
	// Note: Y coordinates are increased from the bottom up in this day!

	enum class RockShape
	{
		HLine,
		Cross,
		LShape,
		VLine,
		Block
	};

	class Rock
	{
	public:
		Rock(RockShape shape, int bottom)
		{
			// Rocks appear two units away from the left
			switch (shape)
			{
				case RockShape::HLine:
					// ####
					m_rock.insert({ 2, bottom });
					m_rock.insert({ 3, bottom });
					m_rock.insert({ 4, bottom });
					m_rock.insert({ 5, bottom });
					break;
				case RockShape::Cross:
					// .#.
					// ###
					// .#.
					m_rock.insert({ 3, bottom + 2 });
					m_rock.insert({ 2, bottom + 1 });
					m_rock.insert({ 3, bottom + 1 });
					m_rock.insert({ 4, bottom + 1 });
					m_rock.insert({ 3, bottom });
					break;
				case RockShape::LShape:
					// ..#
					// ..#
					// ###
					m_rock.insert({ 4, bottom + 2 });
					m_rock.insert({ 4, bottom + 1 });
					m_rock.insert({ 2, bottom });
					m_rock.insert({ 3, bottom });
					m_rock.insert({ 4, bottom });
					break;
				case RockShape::VLine:
					// #
					// #
					// #
					// #
					m_rock.insert({ 2, bottom + 3 });
					m_rock.insert({ 2, bottom + 2 });
					m_rock.insert({ 2, bottom + 1 });
					m_rock.insert({ 2, bottom });
					break;
				case RockShape::Block:
					// ##
					// ##
					m_rock.insert({ 2, bottom + 1 });
					m_rock.insert({ 3, bottom + 1 });
					m_rock.insert({ 2, bottom });
					m_rock.insert({ 3, bottom });
					break;
			}
		}

		void MoveLeft(const std::unordered_set<Point<int>>& rockStructure)
		{
			// Check if the rock already touches the left wall
			// (in which case nothing happens)
			if (std::any_of(m_rock.begin(), m_rock.end(), [](const Point<int> rock) { return rock.X == 0; }))
				return;

			std::unordered_set<Point<int>> rockMovedToLeft;
			std::transform(m_rock.begin(), m_rock.end(), std::inserter(rockMovedToLeft, rockMovedToLeft.end()),
				[](const Point<int>& rock) { return rock.MoveXBy(-1); }
			);

			// Check if this would move the falling rock into the existing structure:
			if (std::any_of(rockMovedToLeft.begin(), rockMovedToLeft.end(), [&](const Point<int>& rock) { return rockStructure.contains(rock); }))
				return;
			else
				m_rock = std::move(rockMovedToLeft);
		}

		void MoveRight(const std::unordered_set<Point<int>>& rockStructure)
		{
			// Check if the rock already touches the right wall
			// (in which case nothing happens)
			if (std::any_of(m_rock.begin(), m_rock.end(), [](const Point<int> rock) { return rock.X == 6; }))
				return;

			std::unordered_set<Point<int>> rockMovedToRight;
			std::transform(m_rock.begin(), m_rock.end(), std::inserter(rockMovedToRight, rockMovedToRight.end()),
				[](const Point<int>& rock) { return rock.MoveXBy(+1); }
			);

			// Check if this would move the falling rock into the existing structure:
			if (std::any_of(rockMovedToRight.begin(), rockMovedToRight.end(), [&](const Point<int>& rock) { return rockStructure.contains(rock); }))
				return;
			else
				m_rock = std::move(rockMovedToRight);
		}

		// Returns true if the rocks acutually moved down, false if the rocks came to rest
		bool MoveDown(std::unordered_set<Point<int>>& rockStructure)
		{
			bool touchesRockTop = std::any_of(m_rock.begin(), m_rock.end(),
				[&](const Point<int> rock)
				{
					// Rock touches any rock already in chamber or the floor:
					return rock.Y == 1 || rockStructure.contains(rock.MoveYBy(-1));
				}
			);

			if (!touchesRockTop)
			{
				// Move down:
				std::unordered_set<Point<int>> rockMovedDown;
				std::transform(m_rock.begin(), m_rock.end(), std::inserter(rockMovedDown, rockMovedDown.end()),
					[](const Point<int>& rock) { return rock.MoveYBy(-1); }
				);

				m_rock = std::move(rockMovedDown);
				return true;
			}
			else
			{
				// Update rock structure in chamber:
				rockStructure.insert(m_rock.begin(), m_rock.end());
				return false;
			}
		}

	private:
		std::unordered_set<Point<int>> m_rock;
	};

}
