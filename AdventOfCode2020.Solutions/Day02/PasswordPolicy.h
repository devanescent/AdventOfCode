#pragma once
#include <string>
#include <algorithm>

namespace AdventOfCode::Year2020::Day02
{
	class PasswordPolicy
	{
	public:
		PasswordPolicy(char letter, int minOcc, int maxOcc, std::string password) :
			m_requiredLetter(letter), m_minOccurance(minOcc), m_maxOccurance(maxOcc), m_password(password)
		{ }

		bool IsValid()
		{
			char reqLetter = m_requiredLetter;
			int occ = static_cast<int>(std::count_if(m_password.begin(), m_password.end(), [reqLetter](char letter) { return letter == reqLetter; }));

			return occ >= m_minOccurance && occ <= m_maxOccurance;
		}

		bool operator==(const PasswordPolicy& other) const
		{
			return m_requiredLetter == other.m_requiredLetter &&
				m_minOccurance == other.m_minOccurance &&
				m_maxOccurance == other.m_maxOccurance &&
				m_password == other.m_password;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "%d-%d %c: %s", m_minOccurance, m_maxOccurance, m_requiredLetter, m_password.c_str());
			return std::string(buf);
		}

	private:
		char m_requiredLetter;
		int m_minOccurance;
		int m_maxOccurance;
		std::string m_password;
	};
}

