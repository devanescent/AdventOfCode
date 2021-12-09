#include "stdafx.h"
#include "Day13\Day13_ShuttleSearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day13;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<ShuttleLine>(const ShuttleLine& s) { return to_wstring(s.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day13)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"939",
				"7,13,x,x,59,x,31,19"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			ShuttleLineProcessor shuttleProc;

			// Act:
			std::pair<std::vector<ShuttleLine>, int> result = shuttleProc.Process(inputData);

			// Assert:
			Assert::AreEqual(939, result.second, L"Timestamp incorrect!");
			Assert::AreEqual(ShuttleLine(7), result.first[0], L"Shuttle line no.1 incorrect!");
			Assert::AreEqual(ShuttleLine(59), result.first[2], L"Shuttle line no.3 incorrect!");
			Assert::AreEqual(ShuttleLine(19), result.first[4], L"Shuttle line no.5 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ShuttleSearch day13;

			// Act:
			uint64_t result = day13.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(295ull, result);
		}
	};

	std::vector<std::string> Day13::inputData = std::vector<std::string>();
}