#include "SpreadsheetProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2017::Day02
{
	std::vector<std::vector<int>> SpreadsheetProcessor::Process(std::vector<std::string> input)
	{
		std::vector<std::vector<int>> spreadsheet;

		for (const std::string& rowValues : input)
		{
			std::istringstream iss(rowValues);

			std::vector<int> row;
			int val;

			while (iss >> val)
				row.push_back(val);

			spreadsheet.emplace_back(row);
		}

		return spreadsheet;
	}
}
