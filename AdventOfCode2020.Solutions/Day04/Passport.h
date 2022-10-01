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

		enum class ValidateData
		{
			Enabled,
			Disabled
		};

		bool IsValid(ValidateData validateData)
		{
			if (m_birthYear.empty() || m_issueYear.empty() || m_expirationYear.empty() || m_height.empty() ||
				m_hairColor.empty() || m_eyeColor.empty() || m_passportID.empty())
			{
				// Missing a field other than 'cid':
				return false;
			}
			else if (validateData == ValidateData::Enabled)
			{
				// Also validate the data:
				int birthyear = atoi(m_birthYear.c_str());
				if (birthyear < 1920 || birthyear > 2002) return false;

				int issueYear = atoi(m_issueYear.c_str());
				if (issueYear < 2010 || issueYear > 2020) return false;

				int expirationYear = atoi(m_expirationYear.c_str());
				if (expirationYear < 2020 || expirationYear > 2030) return false;

				int height = atoi(m_height.c_str());
				std::string heightUnit = m_height.substr(m_height.length() - 2);
				if (heightUnit != "cm" && heightUnit != "in") return false;
				else if (heightUnit == "cm" && (height < 150 || height > 193)) return false;
				else if (heightUnit == "in" && (height < 59 || height > 76)) return false;

				// Length: 7 ('#' + 6-digit color)
				if (m_hairColor.length() != 7 || m_hairColor[0] != '#' || 
					m_hairColor.substr(1).find_first_not_of("abcdef0123456789") != std::string::npos) return false;

				if (m_eyeColor != "amb" && m_eyeColor != "blu" && m_eyeColor != "brn" && m_eyeColor != "gry" &&
					m_eyeColor != "grn" && m_eyeColor != "hzl" && m_eyeColor != "oth") return false;

				if (m_passportID.length() != 9 || m_passportID.find_first_not_of("0123456789") != std::string::npos) return false;
			}
			
			// Otherwise, passport is valid:
			return true;
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
