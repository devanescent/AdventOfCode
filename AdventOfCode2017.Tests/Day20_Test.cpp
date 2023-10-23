#include "stdafx.h"
#include "Day20\Day20_ParticleSwarm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2017::Day20;

namespace AdventOfCode::Year2017::Tests
{
	TEST_CLASS(Year2017_Day20)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"p=< 3,0,0>, v=< 2,0,0>, a=<-1,0,0>",
				"p=< 4,0,0>, v=< 0,0,0>, a=<-2,0,0>"
			};

		};
		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			ParticleSwarm sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(0ull, result);
		};

	};
	std::vector<std::string> Year2017_Day20::inputData1 = std::vector<std::string>();
}
