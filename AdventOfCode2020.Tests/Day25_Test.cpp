#include "stdafx.h"
#include "Day25\Day25_ComboBreaker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day25;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day25)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"5764801",
				"17807724"
			};
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			ComboBreaker day25;

			// Act:
			uint64_t result = day25.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(14897079ull, result);
		}
	};

	std::vector<std::string> Day25::inputData = std::vector<std::string>();
}