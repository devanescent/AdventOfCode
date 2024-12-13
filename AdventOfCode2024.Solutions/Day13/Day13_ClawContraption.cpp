#include "Day13_ClawContraption.h"

namespace AdventOfCode::Year2024::Day13
{
	ClawContraption::ClawContraption() : DayT(13, "Claw Contraption") { }

	uint64_t ClawContraption::ExecutePart1(std::vector<ClawMachine> clawMachines)
	{
		uint64_t totalTokens = 0;

		for (const auto& m : clawMachines)
		{
			// Current position of the claw:
			Point<int> clawPos(0, 0);
			
			// Best price found:
			uint64_t bestPrice = UINT64_MAX;

			for (int a = 1; a <= 100; ++a)
			{
				clawPos.X += m.ButtonA.X;
				clawPos.Y += m.ButtonA.Y;

				if (clawPos.X > m.Prize.X || clawPos.Y > m.Prize.Y)
				{
					// Overshot the target, cannot win prize anymore:
					break;
				}
				else
				{
					// Remaining distance to the prize:
					auto dx = m.Prize.X - clawPos.X;
					auto dy = m.Prize.Y - clawPos.Y;

					// Check if prize can be reached with B button presses:
					if (dx % m.ButtonB.X == 0 && dy % m.ButtonB.Y == 0 &&
						dx / m.ButtonB.X == dy / m.ButtonB.Y)
					{
						int b = dx / m.ButtonB.X;
						uint64_t tokenPrice = a * 3 + b;
						bestPrice = std::min(tokenPrice, bestPrice);
					}
				}
			}

			if (bestPrice != UINT64_MAX)
			{
				totalTokens += bestPrice;
			}
		}

		return totalTokens;
	}

	uint64_t ClawContraption::ExecutePart2(std::vector<ClawMachine> clawMachines)
	{
		uint64_t totalTokens = 0;

		for (auto& m : clawMachines)
		{
			// Increase prize position:
			m.Prize = m.Prize.MoveBy(10000000000000, 10000000000000);

			// Solve mathematically:
			// px,py = prize location, a,b = buttons, t = times buttonA is pressed, u = times buttonB is pressed
			// 
			// => px = t * ax + u * bx
			// => py = t * ay + u * by

			// => t = (bx*py - by*px) / (ay*bx - ax*by)
			// => u = (ax*py - ay*px) / (ax*by - ay*bx)

			int64_t t_num = m.ButtonB.X * m.Prize.Y - m.ButtonB.Y * m.Prize.X;
			int64_t t_denom = m.ButtonA.Y * m.ButtonB.X - m.ButtonA.X * m.ButtonB.Y;
			int64_t t = t_num / t_denom;

			int64_t u_num = m.ButtonA.X * m.Prize.Y - m.ButtonA.Y * m.Prize.X;
			int64_t u_denom = m.ButtonA.X * m.ButtonB.Y - m.ButtonA.Y * m.ButtonB.X;
			int64_t u = u_num / u_denom;

			// Check for positive integer solution:
			if (t >= 0 && t * t_denom == t_num && u >= 0 && u * u_denom == u_num)
			{
				totalTokens += (uint64_t)t * 3 + (uint64_t)u;
			}
		}

		return totalTokens;
	}
}
