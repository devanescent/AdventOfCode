#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>

namespace AdventOfCode::Year2020::Day16
{
	// ---------------------------------------------------------------------------
	// Helper / utility struct for ticket processing:
	class ValueInterval
	{
	public:
		ValueInterval(int lower, int upper, bool isClosed = true) :
			m_lowerLimit(lower), m_upperLimit(upper), m_isClosed(isClosed)
		{}

		// Checks if the given value is part of the interval
		bool Contains(int val) const
		{
			if (m_isClosed)
				return val >= m_lowerLimit && val <= m_upperLimit;
			else
				return val > m_lowerLimit && val < m_upperLimit;
		}

		bool operator==(const ValueInterval& other) const
		{
			return m_upperLimit == other.m_upperLimit && m_lowerLimit == other.m_lowerLimit && m_isClosed == other.m_isClosed;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%c%d-%d%c", m_isClosed ? '[' : '(', m_lowerLimit, m_upperLimit, m_isClosed ? ']' : ')');
			return std::string(buf);
		}

	private:
		// Interval boundaries:
		int m_lowerLimit;
		int m_upperLimit;

		// If closed, both limits are part of the interval, otherwise they are not
		bool m_isClosed;
	};

	// ---------------------------------------------------------------------------
	// Ticket class for holding all values on the ticket
	class Ticket
	{
	public:
		Ticket(std::vector<int> vals) :
			m_fieldValues(vals)
		{ }

		const std::vector<int>& Values() const { return m_fieldValues; }

		bool operator==(const Ticket& other) const
		{
			return m_fieldValues == other.m_fieldValues;
		}

		std::string ToString() const
		{
			std::string out = "Ticket: ";

			for (int i : m_fieldValues)
				out += std::to_string(i) + ",";

			out.pop_back();	// remove last ','
			return out;
		}

	private:
		std::vector<int> m_fieldValues;
	};

	// ---------------------------------------------------------------------------
	// A ticket field with allowed values
	class TicketField
	{
	public:
		TicketField(std::string name, std::vector<ValueInterval> ranges) :
			m_fieldName(name), m_allowedValues(ranges)
		{}

		const std::string& Name() const { return m_fieldName; }

		bool IsAllowed(int val)
		{
			for (const ValueInterval& vi : m_allowedValues)
			{
				if (vi.Contains(val))
					return true;
			}
			return false;
		}

		bool operator==(const TicketField& other) const
		{
			return m_fieldName == other.m_fieldName && m_allowedValues == other.m_allowedValues;
		}

		std::string ToString() const
		{
			std::string out = m_fieldName + ":";

			for (const ValueInterval& range : m_allowedValues)
				out += range.ToString() + " OR ";

			out = out.erase(out.length() - 4);	// remove last ' OR '
			return out;
		}

	private:
		std::string m_fieldName;
		std::vector<ValueInterval> m_allowedValues;
	};

	// ---------------------------------------------------------------------------
	// A collection of rules for all fields on a ticket
	class TicketRules
	{
	public:
		TicketRules(std::vector<TicketField> fields) :
			m_fields(fields)
		{}

		// Checks the given Ticket against all rules, returns true if the ticket is valid, false otherwise.
		// Additionally returns the error rate: the sum of all values that do not match any of the rules.
		bool Validate(const Ticket& ticket, int& errorRate)
		{
			bool isTicketValid = true;

			errorRate = 0;
			for (int val : ticket.Values())
			{
				bool isFieldValid = false;
				for (TicketField& tField : m_fields)
				{
					if (tField.IsAllowed(val))
					{
						isFieldValid = true;
						break;	// no need checking the rest of the rules for this value
					}
				}

				if (!isFieldValid)
				{
					isTicketValid = false;
					errorRate += val;
				}
			}

			return isTicketValid;
		}

		std::map<std::string, std::set<int>> MatchValuesToFields(const Ticket& ticket)
		{
			// For each rule by name, check which values (by index) of the ticket match this rule
			std::map<std::string, std::set<int>> matchingValueIndices;

			for (TicketField& tField : m_fields)
			{
				const auto& tValues = ticket.Values();
				for (int i = 0; i < tValues.size(); ++i)
				{
					if (tField.IsAllowed(tValues[i]))
						matchingValueIndices[tField.Name()].insert(i);
				}
			}

			return matchingValueIndices;
		}

		bool operator==(const TicketRules& other) const
		{
			return m_fields == other.m_fields;
		}

		std::string ToString() const
		{
			std::string out = "TicketRules: ";

			for (const TicketField& field : m_fields)
				out += field.ToString() + ";";

			out.pop_back();	// remove last ';'
			return out;
		}

	private:
		std::vector<TicketField> m_fields;
	};
}