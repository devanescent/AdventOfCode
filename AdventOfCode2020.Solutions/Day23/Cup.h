#pragma once

namespace AdventOfCode::Year2020::Day23
{
	class Cup
	{
	public:
		Cup(int label, Cup* prevCup = nullptr) :
			m_label(label), m_next(nullptr)
		{
			if (prevCup)
				prevCup->SetNext(this);
		}

		int GetLabel() const { return m_label; }

		// Set cup order:
		void SetNext(Cup* nextCup) { m_next = nextCup; }

		// Get next cup (or, by giving a skip value, the next after that, etc.)
		Cup* GetNext(int skip = 0) const
		{
			Cup* pRet = m_next;
			for (int i = 0; i < skip; ++i)
				pRet = pRet->m_next;

			return pRet;
		}

	private:
		int	m_label;
		Cup*	m_next;
	};
}