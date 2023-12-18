#pragma once
#include <string>

namespace AdventOfCode::Year2023::Day18
{
	class DigPlan
	{
	public:
		// Dig direction:
		int dx = 0;
		int dy = 0;

		uint64_t Steps;
		std::string Color;

		// Extract direction / steps from color:
		void ExtractFromColor()
		{
			char dir = Color.back();
			switch (dir)
			{
				case '0': // R
					dx = 1;
					dy = 0;
					break;
				case '1': // D
					dx = 0;
					dy = 1;
					break;
				case '2': // L
					dx = -1;
					dy = 0;
					break;
				case '3': // U
					dx = 0;
					dy = -1;
					break;
			}

			std::string stepCountStr = Color;
			stepCountStr.pop_back();
			Steps = std::stoull(stepCountStr, nullptr, 16);
		}
	};
}
