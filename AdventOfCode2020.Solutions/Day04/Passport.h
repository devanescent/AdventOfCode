#pragma once
#include <string>

namespace AdventOfCode::Year2020::Day04
{
	class Passport
	{
	public:
		Passport(std::string birthYear, std::string issueYear, std::string expYear, std::string height,
			std::string hairColor, std::string eyeColor, std::string passportID, std::string countryID) :
			m_birthYear(birthYear), m_issueYear(issueYear), m_expirationYear(expYear), m_height(height),
			m_hairColor(hairColor), m_eyeColor(eyeColor), m_passportID(passportID), m_countryID(countryID)
		{}

		// Checks if passport is valid, ignores empty 'CountryID' field
		bool IsValid()
		{
			return !(m_birthYear.empty() || m_issueYear.empty() || m_expirationYear.empty() || m_height.empty() ||
				m_hairColor.empty() || m_eyeColor.empty() || m_passportID.empty());
		}

		bool operator==(const Passport& other) const
		{
			return m_birthYear == other.m_birthYear &&
				m_issueYear == other.m_issueYear &&
				m_expirationYear == other.m_expirationYear &&
				m_height == other.m_height &&
				m_hairColor == other.m_hairColor &&
				m_eyeColor == other.m_eyeColor &&
				m_passportID == other.m_passportID &&
				m_countryID == other.m_countryID;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "BYR:%s, IYR:%s, EYR:%s, HGT:%s, HCL:%s, ECL:%s, PID:%s, CID:%s",
				m_birthYear.c_str(), m_issueYear.c_str(), m_expirationYear.c_str(), m_height.c_str(),
				m_hairColor.c_str(), m_eyeColor.c_str(), m_passportID.c_str(), m_countryID.c_str());

			return std::string(buf);
		}

	private:
		std::string m_birthYear;
		std::string m_issueYear;
		std::string m_expirationYear;
		std::string m_height;
		std::string m_hairColor;
		std::string m_eyeColor;
		std::string m_passportID;
		std::string m_countryID;
	};
}
