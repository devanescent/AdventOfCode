#include "stdafx.h"
#include "Day21/Day21_AllergenAssessment.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day21;
using namespace std::string_literals;

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day21)
	{
	public:
		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			AllergenAssessment sut;

			// Act:
			uint64_t result = sut.GetResultOnPart1(
			{
				"mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
				"trh fvjkl sbzzf mxmxvkd (contains dairy)",
				"sqjhc fvjkl (contains soy)",
				"sqjhc mxmxvkd sbzzf (contains fish)"
			});

			// Assert:
			Assert::AreEqual(5ull, result);
		}

		TEST_METHOD(CheckExample_Part2)
		{
			// Arrange:
			AllergenAssessment sut;

			// Act:
			std::string result = sut.GetResultOnPart2(
				{
					"mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
					"trh fvjkl sbzzf mxmxvkd (contains dairy)",
					"sqjhc fvjkl (contains soy)",
					"sqjhc mxmxvkd sbzzf (contains fish)"
				});

			// Assert:
			Assert::AreEqual("mxmxvkd,sqjhc,fvjkl"s, result);
		}
	};
}