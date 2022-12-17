#include "stdafx.h"
#include "Day16\Day16_ProboscideaVolcanium.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day16;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day16)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"Valve AA has flow rate=0; tunnels lead to valves DD, II, BB",
				"Valve BB has flow rate=13; tunnels lead to valves CC, AA",
				"Valve CC has flow rate=2; tunnels lead to valves DD, BB",
				"Valve DD has flow rate=20; tunnels lead to valves CC, AA, EE",
				"Valve EE has flow rate=3; tunnels lead to valves FF, DD",
				"Valve FF has flow rate=0; tunnels lead to valves EE, GG",
				"Valve GG has flow rate=0; tunnels lead to valves FF, HH",
				"Valve HH has flow rate=22; tunnel leads to valve GG",
				"Valve II has flow rate=0; tunnels lead to valves AA, JJ",
				"Valve JJ has flow rate=21; tunnel leads to valve II"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ProboscideaVolcanium sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(1651ull, result);
		};

	};
	std::vector<std::string> Year2022_Day16::inputData1 = std::vector<std::string>();
}
