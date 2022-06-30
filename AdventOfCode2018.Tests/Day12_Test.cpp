#include "stdafx.h"
#include "Day12\Day12_SubterraneanSustainability.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day12;

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day12)
	{
	private:
		static std::vector<std::string> inputData;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{ 
				"initial state: #..#.#..##......###...###",
				"",
				"...## = > #",
				"..#.. => #",
				".#... => #",
				".#.#. => #",
				".#.## => #",
				".##.. => #",
				".#### => #",
				"#.#.# => #",
				"#.### => #",
				"##.#. => #",
				"##.## => #",
				"###.. => #",
				"###.# => #",
				"####. => #"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			SubterraneanSustainability sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(325ull, result);
		}
	};

	std::vector<std::string> Year2018_Day12::inputData = std::vector<std::string>();
}