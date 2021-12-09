#include "PassportProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2020::Day04
{
	// Each passport is represented as a sequence of key:value pairs separated by
	// spaces or newlines. Passports are separated by blank lines.
	std::vector<Passport> PassportProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Passport> passports;

		std::vector<std::string> passportList = JoinLines(input, true);
		for (const std::string& passportData : passportList)
			passports.push_back(ParsePassport(passportData));

		return passports;
	}

	// Parses the data into the passport fields
	Passport PassportProcessor::ParsePassport(const std::string& passportData)
	{
		std::istringstream passportIn = std::istringstream(passportData);
		std::string fieldData, fieldName;

		std::string* fieldValue;
		std::string birthYear, issueYear, expirationYear, height, hairColor, eyeColor, passportID, countryID;

		while (std::getline(passportIn, fieldData, ' '))
		{
			if (fieldData.empty())
				continue;

			// Split field and field value:
			size_t delimPos = fieldData.find(':');

			if (delimPos == std::string::npos)
				continue;

			fieldName = fieldData.substr(0, delimPos);

			// Assign to passport field
			fieldValue = nullptr;

			if (fieldName.compare("byr") == 0)
				fieldValue = &birthYear;
			else if (fieldName.compare("iyr") == 0)
				fieldValue = &issueYear;
			else if (fieldName.compare("eyr") == 0)
				fieldValue = &expirationYear;
			else if (fieldName.compare("hgt") == 0)
				fieldValue = &height;
			else if (fieldName.compare("hcl") == 0)
				fieldValue = &hairColor;
			else if (fieldName.compare("ecl") == 0)
				fieldValue = &eyeColor;
			else if (fieldName.compare("pid") == 0)
				fieldValue = &passportID;
			else if (fieldName.compare("cid") == 0)
				fieldValue = &countryID;

			if (fieldValue)
				*fieldValue = fieldData.substr(delimPos + 1);
		}

		return Passport(birthYear, issueYear, expirationYear, height, hairColor, eyeColor, passportID, countryID);
	}

}