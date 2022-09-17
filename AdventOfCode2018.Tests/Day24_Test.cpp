#include "stdafx.h"
#include "Day24\Day24_ImmuneSystemSimulator20XX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day24;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day24)
	{
	private:
		static std::vector<std::string> exampleData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			exampleData = std::vector<std::string>
			{
				"Immune System:",
				"17 units each with 5390 hit points (weak to radiation, bludgeoning) with an attack that does 4507 fire damage at initiative 2",
				"989 units each with 1274 hit points (immune to fire; weak to bludgeoning, slashing) with an attack that does 25 slashing damage at initiative 3",
				"",
				"Infection:",
				"801 units each with 4706 hit points (weak to radiation) with an attack that does 116 bludgeoning damage at initiative 1",
				"4485 units each with 2961 hit points (immune to radiation; weak to fire, cold) with an attack that does 12 slashing damage at initiative 4"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ImmuneSystemSimulator20XX sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(exampleData);

			// Assert:
			Assert::AreEqual(5216ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ImmuneSystemSimulator20XX sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(exampleData);

			// Assert:
			Assert::AreEqual(51ull, result);
		}
	};

	std::vector<std::string> Year2018_Day24::exampleData = std::vector<std::string>();
}