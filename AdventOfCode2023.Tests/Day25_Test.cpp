#include "stdafx.h"
#include "Day25/Day25_Snowverload.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2023::Day25;

namespace AdventOfCode::Year2023::Tests
{
	TEST_CLASS(Year2023_Day25)
	{
	private:
		static std::vector<std::string> inputData1;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>
			{
				"jqt: rhn xhk nvd",
				"rsh: frs pzl lsr",
				"xhk: hfx",
				"cmg: qnr nvd lhk bvb",
				"rhn: xhk bvb hfx",
				"bvb: xhk hfx",
				"pzl: lsr hfx nvd",
				"qnr: nvd",
				"ntq: jqt hfx bvb xhk",
				"nvd: lhk",
				"lsr: lhk",
				"rzs: qnr cmg lsr rsh",
				"frs: qnr lhk lsr"
			};
		};

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			Snowverload sut;
			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData1);
			// Assert:
			Assert::AreEqual(54ull, result);
		};
	};

	std::vector<std::string> Year2023_Day25::inputData1;
}
