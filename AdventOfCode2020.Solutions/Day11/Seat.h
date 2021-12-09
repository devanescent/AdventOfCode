#pragma once
#include <vector>


namespace AdventOfCode::Year2020::Day11
{
	class Seat
	{
	public:
		enum class SeatType
		{
			NO_SEAT,
			EMPTY,
			OCCUPIED
		};

		Seat(SeatType type) : m_seatType(type), m_nextType(type) {}

		bool IsSeat() { return m_seatType != SeatType::NO_SEAT; }
		bool IsOccupied() { return m_seatType == SeatType::OCCUPIED; }

		// Next iteration
		void SetNextState(SeatType nextState) { m_nextType = nextState; }
		bool Update()
		{
			bool hasChanged = (m_nextType != m_seatType);
			m_seatType = m_nextType;
			return hasChanged;
		}

		
		bool operator==(const Seat& other) const
		{
			return m_seatType == other.m_seatType;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%s", 
				m_seatType == Seat::SeatType::OCCUPIED ? "OCCUPIED" : (m_seatType == Seat::SeatType::EMPTY ? "EMPTY" : "NO_SEAT"));

			return std::string(buf);
		}

	private:
		SeatType m_seatType;
		SeatType m_nextType;
	};

	typedef std::vector<Seat> SeatRow;
}