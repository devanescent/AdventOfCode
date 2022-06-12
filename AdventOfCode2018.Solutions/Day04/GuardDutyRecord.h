#pragma once
#include <algorithm>
#include <map>
#include <numeric>

namespace AdventOfCode::Year2018::Day04
{
	class GuardSleepTimes;

	class GuardDutyRecord
	{
	protected:
		GuardDutyRecord(int year, int month, int day, int hour, int minute) :
			m_year(year), m_month(month), m_day(day), m_hour(hour), m_minute(minute)
		{}

	public:
		virtual ~GuardDutyRecord() = default;

		// Implement ordering of records:
		bool operator<(const GuardDutyRecord& other)
		{
			if (m_year != other.m_year)
				return m_year < other.m_year;
			else if (m_month != other.m_month)
				return m_month < other.m_month;
			else if (m_day != other.m_day)
				return m_day < other.m_day;
			else if (m_hour != other.m_hour)
				return m_hour < other.m_hour;
			else
				return m_minute < other.m_minute;
		}

		virtual bool operator==(const GuardDutyRecord& other) const = 0;

		int Minute() const { return m_minute; }

		virtual void UpdateSleepTimes(GuardSleepTimes& sleepTimes) const = 0;
		virtual std::string ToString() const = 0;

	protected:
		int m_year;
		int m_month;
		int m_day;
		int m_hour;
		int m_minute;
	};

	class BeginShiftRecord : public GuardDutyRecord
	{
	public:
		BeginShiftRecord(int year, int month, int day, int hour, int minute, int guardId) :
			GuardDutyRecord(year, month, day, hour, minute),
			m_guardId(guardId)
		{}

		bool operator==(const GuardDutyRecord& other) const override
		{
			const BeginShiftRecord& bsr = dynamic_cast<const BeginShiftRecord&>(other);

			return m_year == bsr.m_year &&
				m_month == bsr.m_month &&
				m_day == bsr.m_day &&
				m_hour == bsr.m_hour &&
				m_minute == bsr.m_minute &&
				m_guardId == bsr.m_guardId;
		}

		int GuardID() const { return m_guardId; }
		void UpdateSleepTimes(GuardSleepTimes& sleepTimes) const override;
		std::string ToString() const override
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "Began shift: %04d-%02d-%02d %02d:%02d (#%d)", 
				m_year, m_month, m_day, m_hour, m_minute, m_guardId);
			return std::string(buf);
		}

	private:
		int m_guardId;
	};

	class SleepRecord : public GuardDutyRecord
	{
	public:
		SleepRecord(int year, int month, int day, int hour, int minute, bool isAsleep) :
			GuardDutyRecord(year, month, day, hour, minute),
			m_isAsleep(isAsleep)
		{}

		bool operator==(const GuardDutyRecord& other) const override
		{
			const SleepRecord& sr = dynamic_cast<const SleepRecord&>(other);

			return m_year == sr.m_year &&
				m_month == sr.m_month &&
				m_day == sr.m_day &&
				m_hour == sr.m_hour &&
				m_minute == sr.m_minute &&
				m_isAsleep == sr.m_isAsleep;
		}

		bool FellAsleep() const { return m_isAsleep; }
		bool WokeUp() const { return !m_isAsleep; }

		void UpdateSleepTimes(GuardSleepTimes& sleepTimes) const override;
		std::string ToString() const override
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%s: %04d-%02d-%02d %02d:%02d",
				m_isAsleep ? "Fell asleep" : "Woke up", m_year, m_month, m_day, m_hour, m_minute);
			return std::string(buf);
		}

	private:
		bool m_isAsleep;
	};

	class GuardSleepTimes
	{
	private:
		int m_lastShiftStartedGuard;
		int m_lastSleepBegan; // last minute a guard fell asleep

		using SleepMap = std::map<int, std::map<int, int>>; // maps how often a guard was asleep a specific minute
		SleepMap m_allSleepPeriods; // Periods of sleep by guard ID

	public:
		void BeginShift(const BeginShiftRecord& beginShiftRec);
		void GuardFellAsleep(const SleepRecord& sleepRecord);
		void GuardWokeUp(const SleepRecord& sleepRecord);

		uint64_t FindMostAsleepGuard();
		uint64_t FindMostAsleepMinute();
	};
}
