#pragma once
#include "Point.h"

namespace AdventOfCode::Year2022::Day23
{
	class Elf
	{
	public:
		Point<int> Pos;
		Point<int> ProposedMove;

		Elf(int x, int y) : Pos(x,y) {}
	};
}
