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
		Tile(int id, std::string top, std::string right, std::string bottom, std::string left) :
			m_id(id), m_unmatchedEdges({ top, right, bottom, left }),
			m_topEdge(std::move(top)), m_rightEdge(std::move(right)), m_bottomEdge(std::move(bottom)), m_leftEdge(std::move(left))
		{}

		int GetID() { return m_id; }

		// true if there is a matching edge to the given tile, false otherwise
		bool Match(Tile& tile)
		{
			// Skip if either this or the other tile already have all their edges matched:
			if (m_unmatchedEdges.empty() || tile.m_unmatchedEdges.empty())
				return false;

			for (auto edge = m_unmatchedEdges.begin(); edge != m_unmatchedEdges.end(); ++edge)
			{
				for (auto otherEdge = tile.m_unmatchedEdges.begin(); otherEdge != tile.m_unmatchedEdges.end(); ++otherEdge)
				{
					// check forward or reverse match (for tiles can be flipped)
					if (std::equal(edge->begin(), edge->end(), otherEdge->begin(), otherEdge->end()) ||
						std::equal(edge->begin(), edge->end(), otherEdge->rbegin(), otherEdge->rend()))
					{
						// m_matchedEdges[edge] = t;
						m_unmatchedEdges.erase(edge);

						// t->m_matchedEdges[otherEdge] = this;
						tile.m_unmatchedEdges.erase(otherEdge);

						// return on first match - two tiles can have one matching edge at most!
						return true;
					}
				}
			}
			return false;
		}

		bool operator==(const Tile& other) const
		{
			return m_id == other.m_id && m_unmatchedEdges == other.m_unmatchedEdges;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "Tile %d (top: '%s', right: '%s', bottom: '%s', left: '%s')", 
				m_id, m_topEdge.c_str(), m_rightEdge.c_str(), m_bottomEdge.c_str(), m_leftEdge.c_str());
			return std::string(buf);
		}

	private:
		int m_id;
		std::set<std::string> m_unmatchedEdges;
		std::string m_topEdge, m_rightEdge, m_bottomEdge, m_leftEdge;
		// std::map<std::string, Tile*> m_matchedEdges;	// not necessary for part 1 !?
	};
}