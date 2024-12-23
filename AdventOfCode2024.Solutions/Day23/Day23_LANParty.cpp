#include "Day23_LANParty.h"
#include <algorithm>
#include <map>
#include <set>

namespace AdventOfCode::Year2024::Day23
{
	LANParty::LANParty() : DayT(23, "LAN Party") { }

	std::vector<std::set<std::string>> GetSize3Networks(const std::vector<Connection>& connections)
	{
		// Find sets of three interconnected computers:
		std::vector<std::set<std::string>> networks;

		// For each connections a-b && b-c, check if there is a connection a-c
		for (auto con1 = connections.cbegin(); con1 != connections.cend() - 2; ++con1)
		{
			for (auto con2 = con1 + 1; con2 != connections.cend() - 1; ++con2)
			{
				if (!con1->IsEqual(*con2) && con1->IsConnectedWith(*con2))
				{
					auto requiredConnection = con1->GetRequired3WayConnection(*con2);
					if (std::find_if(con2 + 1, connections.cend(),
						[&requiredConnection](const Connection& c)
						{
							return c.IsEqual(requiredConnection);
						}) != connections.cend())
					{
						std::set<std::string> network;
						network.insert(con1->Computer1);
						network.insert(con1->Computer2);
						network.insert(con2->Computer1);
						network.insert(con2->Computer2);
						networks.emplace_back(network);
					}
				}
			}
		}

		return networks;
	}

	uint64_t LANParty::ExecutePart1(std::vector<Connection> connections)
	{
		auto networks = GetSize3Networks(connections);

		// Count networks that contain at least 1 computer with a name that starts with a 't':
		uint64_t networksWithComputerT = std::count_if(networks.begin(), networks.end(),
			[](const auto& network)
			{
				return std::find_if(network.begin(), network.end(),
					[](const std::string& comp) { return comp[0] == 't'; }) != network.end();

			});

		return networksWithComputerT;
	}

	std::string LANParty::ExecutePart2(std::vector<Connection> connections)
	{
		auto networks = GetSize3Networks(connections);

		// Get all connections for each computer:
		std::map<std::string, std::set<std::string>> allConnections;
		for (const auto& con : connections)
		{
			allConnections[con.Computer1].insert(con.Computer2);
			allConnections[con.Computer2].insert(con.Computer1);
		}

		// Try adding computers to networks if they have connections to all other computers in them:
		bool addedCompToNetwork;
		do
		{
			addedCompToNetwork = false;
			for (const auto& [comp, conns] : allConnections)
			{
				for (auto& nw : networks)
				{
					if (!nw.contains(comp))
					{
						// Check if computer is connected to all other computers in the network:
						bool isConnectedToAll = std::all_of(nw.begin(), nw.end(), [&conns](const auto& nwComp) { return conns.contains(nwComp); });
						if (isConnectedToAll)
						{
							nw.insert(comp);
							addedCompToNetwork = true;
						}
					}
				}
			}
		} while (addedCompToNetwork);

		// Find largest network:
		auto largestNetwork = std::max_element(networks.begin(), networks.end(), [](const auto& nw1, const auto& nw2) { return nw1.size() < nw2.size(); });

		// Network is a std::set<>: computer names are already sorted alphabetically,
		// just combine computer names:
		std::string result;
		for (const auto& comp : *largestNetwork)
		{
			if (!result.empty())
				result += ',';
			result += comp;
		}

		return result;
	}
}
