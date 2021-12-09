#pragma once
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <string>

namespace AdventOfCode::Year2020::Day20
{
	class Tile
	{
	public:
		Tile(int id, std::string edge1, std::string edge2, std::string edge3, std::string edge4):
			m_id(id), m_unmatchedEdges({ edge1, edge2, edge3, edge4 })
		{}

		int GetID() { return m_id; }

		// true if there is a matching edge to the given tile, false otherwise
		bool Match(Tile* t)
		{
			if (t == this || m_unmatchedEdges.empty() || t->m_unmatchedEdges.empty())
				return false;

			for (const std::string& edge : m_unmatchedEdges)
			{
				for (const std::string& otherEdge : t->m_unmatchedEdges)
				{
					// check forward or reverse match (for tiles can be flipped)
					if (std::equal(edge.begin(), edge.end(), otherEdge.begin(), otherEdge.end()) ||
						std::equal(edge.begin(), edge.end(), otherEdge.rbegin(), otherEdge.rend()))
					{
						// m_matchedEdges[edge] = t;
						m_unmatchedEdges.erase(edge);

						// t->m_matchedEdges[otherEdge] = this;
						t->m_unmatchedEdges.erase(otherEdge);

						// return on first match - two tiles can have one matching edge at most!
						return true;
					}
				}
			}
			return false;
		}

		bool operator==(const Tile& other) const = default;

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "Tile %d", m_id);
			return std::string(buf);
		}

	private:
		int m_id;
		std::set<std::string> m_unmatchedEdges;
		// std::map<std::string, Tile*> m_matchedEdges;	// not necessary for part 1 !?
	};
}