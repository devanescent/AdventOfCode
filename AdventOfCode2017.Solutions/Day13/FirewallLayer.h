#pragma once

namespace AdventOfCode::Year2017::Day13
{
	enum class ScannerDirection
	{
		Up,
		Down
	};

	class FirewallLayer
	{
	public:
		int Depth;
		int Range;

		int ScannerPos = 0;
		ScannerDirection ScanDir = ScannerDirection::Down;
	};
}
