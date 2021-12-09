#include "stdafx.h"
#include "Day16\Day16_TicketTranslation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day16;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<Ticket>(const Ticket& t) { return to_wstring(t.ToString()); }

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<TicketRules>(const TicketRules& tr) { return to_wstring(tr.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day16)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"class: 1-3 or 5-7",
				"row: 6-11 or 33-44",
				"seat: 13-40 or 45-50",
				"",
				"your ticket:",
				"7,1,14",
				"",
				"nearby tickets:",
				"7,3,47",
				"40,4,50",
				"55,2,20",
				"38,6,12"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			TicketProcessor tProc;

			// Act:
			std::pair<std::vector<Ticket>, TicketRules> result = tProc.Process(inputData);

			// Assert:
			TicketField tf1("class", { ValueInterval(1,3), ValueInterval(5,7) });
			TicketField tf2("row", { ValueInterval(6,11), ValueInterval(33,44) });
			TicketField tf3("seat", { ValueInterval(13,40), ValueInterval(45,50) });

			Ticket t0({ 7,1,14 });
			Ticket t1({ 7,3,47 });
			Ticket t2({ 40,4,50 });
			Ticket t3({ 55,2,20 });
			Ticket t4({ 38,6,12 });

			TicketRules rules({ tf1, tf2, tf3 });
			
			Assert::AreEqual(t0, result.first[0], L"Ticket no.1 incorrect!");
			Assert::AreEqual(t2, result.first[2], L"Ticket no.3 incorrect!");
			Assert::AreEqual(t4, result.first[4], L"Ticket no.5 incorrect!");
			Assert::AreEqual(rules, result.second, L"Ticket rules incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			TicketTranslation day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(71ull, result);
		}
	};

	std::vector<std::string> Day16::inputData = std::vector<std::string>();
}