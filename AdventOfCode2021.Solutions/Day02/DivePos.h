#pragma once
#include "DiveCmd.h"

namespace AdventOfCode::Year2021::Day02
{
	// Simple dive positioning
	class DivePos
	{
	public:
		int HorizontalPosition = 0;
		int Depth = 0;

		virtual void ApplyDiveCmd(const DiveCmd& dCmd)
		{
			switch (dCmd.Dir)
			{
				// Forward: increase only horizontal position:
				case DiveCmdDirection::Forward:
					HorizontalPosition += dCmd.Value;
					break;

				// Up / Down: decrease / increase depth:
				case DiveCmdDirection::Up:
					Depth -= dCmd.Value;
					break;

				case DiveCmdDirection::Down:
					Depth += dCmd.Value;
					break;
			}
		}
	};

	// Extended dive positioning
	class DivePosEx : public DivePos
	{
	public:
		// Extend position by 'Aim'
		int Aim = 0;

		void ApplyDiveCmd(const DiveCmd& dCmd) override
		{
			switch (dCmd.Dir)
			{
				// Forward: increase horizontal position and depth based on aim:
				case DiveCmdDirection::Forward:
					HorizontalPosition += dCmd.Value;
					Depth += Aim * dCmd.Value;
					break;

				// Up / Down: adjust aim:
				case DiveCmdDirection::Up:
					Aim -= dCmd.Value;
					break;

				case DiveCmdDirection::Down:
					Aim += dCmd.Value;
					break;
			}
		}
	};
}