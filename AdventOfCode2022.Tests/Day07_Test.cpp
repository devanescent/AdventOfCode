#include "stdafx.h"
#include "Day07/Day07_NoSpaceLeftOnDevice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2022::Day07;

namespace AdventOfCode::Year2022::Tests
{
	TEST_CLASS(Year2022_Day07)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"$ cd /",
				"$ ls",
				"dir a",
				"14848514 b.txt",
				"8504156 c.dat",
				"dir d",
				"$ cd a",
				"$ ls",
				"dir e",
				"29116 f",
				"2557 g",
				"62596 h.lst",
				"$ cd e",
				"$ ls",
				"584 i",
				"$ cd ..",
				"$ cd ..",
				"$ cd d",
				"$ ls",
				"4060174 j",
				"8033020 d.log",
				"5626152 d.ext",
				"7214296 k"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			NoSpaceLeftOnDevice sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(95437ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			NoSpaceLeftOnDevice sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData1);
			// Assert:
			Assert::AreEqual(24933642ull, result);
		};
	};

	std::vector<std::string> Year2022_Day07::inputData1;
}
