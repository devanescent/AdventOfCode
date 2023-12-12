#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <variant>

namespace AdventOfCode
{
	class AoCResult
	{
	public:
		AoCResult(uint64_t num_result) : m_resultValue(num_result) {}
		AoCResult(std::string str_result) : m_resultValue(std::move(str_result)) {}

		operator const uint64_t&() const { return std::get<uint64_t>(m_resultValue); }
		operator const std::string&() const { return std::get<std::string>(m_resultValue); }

		std::string ToString() const
		{
			struct AoCResultFormatter
			{
				std::string operator()(const uint64_t& num_result) { return std::to_string(num_result); }
				std::string operator()(const std::string& str_result) { return str_result; }
			};
			return std::visit(AoCResultFormatter(), m_resultValue);
		}

		bool operator==(const AoCResult& other) const
		{
			return m_resultValue == other.m_resultValue;
		}

		bool operator==(const uint64_t& numVal) const
		{
			if (const uint64_t* pVal = std::get_if<uint64_t>(&m_resultValue))
				return *pVal == numVal;
			else
				return false;
		}

		bool operator==(const std::string& strVal) const
		{
			if (const std::string* pVal = std::get_if<std::string>(&m_resultValue))
				return *pVal == strVal;
			else
				return false;
		}

	private:
		std::variant<uint64_t, std::string> m_resultValue;
	};
}