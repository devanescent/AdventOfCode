#include "ScannerProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2021::Day19
{
	std::vector<Scanner> ScannerProcessor::Process(std::vector<std::string> input)
	{
		std::vector<Scanner> scanners;

		// First line identifies the scanner:
		bool firstScannerLine = true;

		for (const std::string& line : input)
		{
			std::istringstream iss(line);

			if (firstScannerLine)
			{
				// Format: --- scanner X ---
				std::string dump;
				int scannerNo;
				iss >> dump >> dump >> scannerNo;

				// Create new scanner:
				scanners.emplace_back(scannerNo);
				firstScannerLine = false;
			}
			else if (line.empty())
			{
				// Scanners are separated by empty lines:
				firstScannerLine = true;
			}
			else
			{
				// Add scanned beacon coordinates to current scanner:
				int x, y, z;
				char comma;
				iss >> x >> comma >> y >> comma >> z;

				scanners.back().ScannedBeacons.emplace_back(x, y, z);
			}
		}

		return scanners;
	}
}
