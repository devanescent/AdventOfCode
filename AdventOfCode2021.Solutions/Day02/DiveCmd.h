#pragma once
#include <string>
#include <format>

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

		DiveCmdDirection Dir;
		int Value;

		bool operator==(const DiveCmd& other) const = default;

		std::string ToString() const
		{
			return std::format("{} {}", static_cast<char>(Dir), Value);
		}
	};
}