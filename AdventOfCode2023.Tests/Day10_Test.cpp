#include "stdafx.h"
#include "Day10/Day10_PipeMaze.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day10;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day10)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;
		static std::vector<std::string> inputData4;
		static std::vector<std::string> inputData5;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				".....",
				".S-7.",
				".|.|.",
				".L-J.",
				"....."
			};

			inputData2 = std::vector<std::string>
			{
				"..F7.",
				".FJ|.",
				"SJ.L7",
				"|F--J",
				"LJ..."
			};

			inputData3 = std::vector<std::string>
			{
				"...........",
				".S-------7.",
				".|F-----7|.",
				".||.....||.",
				".||.....||.",
				".|L-7.F-J|.",
				".|..|.|..|.",
				".L--J.L--J.",
				"..........."
			};

			inputData4 = std::vector<std::string>
			{
				".F----7F7F7F7F-7....",
				".|F--7||||||||FJ....",
				".||.FJ||||||||L7....",
				"FJL7L7LJLJ||LJ.L-7..",
				"L--J.L7...LJS7F-7L7.",
				"....F-J..F7FJ|L7L7L7",
				"....L7.F7||L7|.L7L7|",
				".....|FJLJ|FJ|F7|.LJ",
				"....FJL-7.||.||||...",
				"....L---J.LJ.LJLJ..."
			};

			inputData5 = std::vector<std::string>
			{
				"FF7FSF7F7F7F7F7F---7",
				"L|LJ||||||||||||F--J",
				"FL-7LJLJ||||||LJL-77",
				"F--JF--7||LJLJ7F7FJ-",
				"L---JF-JLJ.||-FJLJJ7",
				"|F|F-JF---7F7-L7L|7|",
				"|FFJF7L7F-JF7|JL---7",
				"7-L-JL7||F7|L7F-7F7|",
				"L.L7LFJ|||||FJL7||LJ",
				"L7JLJL-JLJLJL--JLJ.L"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PipeMaze sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(4ull, result);
		};

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			PipeMaze sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData2);
			// Assert:
			Assert::AreEqual(8ull, result);
		};

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			PipeMaze sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData3);
			// Assert:
			Assert::AreEqual(4ull, result);
		};

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			PipeMaze sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData4);
			// Assert:
			Assert::AreEqual(8ull, result);
		};

		TEST_METHOD(CheckExample3_Part2)
		{
			// Arrange:
			PipeMaze sut;
			// Act:
			uint64_t result = sut.GetResultOnPart2(inputData5);
			// Assert:
			Assert::AreEqual(10ull, result);
		};
	};

	std::vector<std::string> Year2023_Day10::inputData1;
	std::vector<std::string> Year2023_Day10::inputData2;
	std::vector<std::string> Year2023_Day10::inputData3;
	std::vector<std::string> Year2023_Day10::inputData4;
	std::vector<std::string> Year2023_Day10::inputData5;
}
