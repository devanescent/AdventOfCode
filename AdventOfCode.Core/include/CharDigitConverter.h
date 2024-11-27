#pragma once

namespace AdventOfCode
{
	// Convert a digit from char to its numerical value:
	template<typename T>
	inline T CharToDigit(char c)
	{
		return static_cast<T>(c - '0');
	}
}