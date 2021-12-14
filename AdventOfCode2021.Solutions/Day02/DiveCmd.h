#pragma once
#include <string>

namespace AdventOfCode::Year2021::Day02
{
	enum class DiveCmdDirection : char
	{
		Forward = 'F',
		Up		= 'U',
		Down	= 'D'
	};

	class DiveCmd
	{
	public:
		DiveCmd(DiveCmdDirection dir, int value) : Dir(dir), Value(value) {}
		DiveCmd() : DiveCmd(DiveCmdDirection::Forward, 0) {}

		const DiveCmdDirection Dir;
		const int Value;

		bool operator==(const DiveCmd& other) const
		{
			return Dir == other.Dir && Value == other.Value;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%c %d", static_cast<char>(Dir), Value);
			return std::string(buf);
		}
	};
}