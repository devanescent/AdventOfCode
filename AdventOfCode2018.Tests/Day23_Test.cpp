#include "stdafx.h"
#include "Day23\Day23_ExperimentalEmergencyTeleportation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2018::Day23;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<Nanobot>(const Nanobot& gdr) { return to_wstring(gdr.ToString()); }

namespace AdventOfCode::Year2018::Tests
{
	TEST_CLASS(Year2018_Day23)
	{
	private:
		static std::vector<std::string> example1Data;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> example2Data;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			example1Data = std::vector<std::string>
			{
				"pos=<0,0,0>, r=4",
				"pos=<1,0,0>, r=1",
				"pos=<4,0,0>, r=3",
				"pos=<0,2,0>, r=1",
				"pos=<0,5,0>, r=3",
				"pos=<0,0,3>, r=1",
				"pos=<1,1,1>, r=1",
				"pos=<1,1,2>, r=1",
				"pos=<1,3,1>, r=1"
			};

			inputData2 = std::vector<std::string>
			{
				"pos=<-1,0,0>, r=1",
				"pos=<0,-2,0>, r=1",
				"pos=<-1,-2,-3>, r=1",
			};

			example2Data = std::vector<std::string>
			{
				"pos=<10,12,12>, r=2",
				"pos=<12,14,12>, r=2",
				"pos=<16,12,12>, r=4",
				"pos=<14,14,14>, r=6",
				"pos=<50,50,50>, r=200",
				"pos=<10,10,10>, r=5"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ExperimentalEmergencyTeleportation sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(example1Data);

			// Assert:
			Assert::AreEqual(7ull, result);
		}

		TEST_METHOD(Negative_Coordinates)
		{
			// Arrange:
			NanobotProcessor proc;

			// Act:
			std::vector<Nanobot> result = proc.Process(inputData2);

			// Assert:
			Assert::AreEqual(Nanobot(-1, 0, 0, 1), result[0]);
			Assert::AreEqual(Nanobot(0, -2, 0, 1), result[1]);
			Assert::AreEqual(Nanobot(-1, -2, -3, 1), result[2]);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			ExperimentalEmergencyTeleportation sut;

			// Act:
			uint64_t result = sut.GetResultOnPart2(example2Data);

			// Assert:
			Assert::AreEqual(36ull, result);
		}
	};

	std::vector<std::string> Year2018_Day23::example1Data = std::vector<std::string>();
	std::vector<std::string> Year2018_Day23::example2Data = std::vector<std::string>();
	std::vector<std::string> Year2018_Day23::inputData2 = std::vector<std::string>();
}