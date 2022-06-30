#pragma once

namespace AdventOfCode::Year2018::Day12
{
	class PottedPlant
	{
	private:
		int m_potIndex;
		bool m_hasPlant;

	public:
		int PotIndex() const { return m_potIndex; }
		bool HasPlant() const { return m_hasPlant; }
		void SetPlant(bool hasPlant) { m_hasPlant = hasPlant; }

		PottedPlant(int potIx, bool hasPlant) : m_potIndex(potIx), m_hasPlant(hasPlant) {}
	};
}