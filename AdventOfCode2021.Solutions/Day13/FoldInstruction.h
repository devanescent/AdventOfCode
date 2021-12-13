#pragma once

namespace AdventOfCode::Year2021::Day13
{
	enum class FoldDirection : char
	{
		Vertical = 'x',
		Horizontal = 'y'
	};

	class FoldInstruction
	{
	public:
		FoldInstruction(FoldDirection dir, int pos) : 
			Direction(dir), Position(pos) {}

		FoldDirection Direction;
		int Position;

		bool operator==(const FoldInstruction& other) const
		{
			return Direction == other.Direction && Position == other.Position;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%c=%d", static_cast<char>(Direction), Position);
			return std::string(buf);
		}
	};
}