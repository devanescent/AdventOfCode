#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace AdventOfCode::Year2022::Day16
{
	class Valve
	{
	public:
		std::string Name;
		int FlowRate;
		std::vector<std::string> ConnectedValves;

		bool IsConnectedTo(const std::string& otherValve) const
		{
			return std::find(ConnectedValves.begin(), ConnectedValves.end(), otherValve) != ConnectedValves.end();
		}
	};
}
