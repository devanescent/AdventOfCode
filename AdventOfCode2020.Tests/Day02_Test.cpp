#include "stdafx.h"
#include "Day02\Day02_PasswordPhilosophy.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day02;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<PasswordPolicy>(const PasswordPolicy& pp) { return to_wstring(pp.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day02)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"1-3 a: abcde",
				"1-3 b: cdefg",
				"2-9 c: ccccccccc"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			PasswortPolicyProcessor ppProc;

			// Act:
			std::vector<PasswordPolicy> result = ppProc.Process(inputData);

			// Assert:
			Assert::AreEqual(PasswordPolicy('a', 1, 3, "abcde"), result[0], L"Policy data no.1 incorrect!");
			Assert::AreEqual(PasswordPolicy('b', 1, 3, "cdefg"), result[1], L"Policy data no.2 incorrect!");
			Assert::AreEqual(PasswordPolicy('c', 2, 9, "ccccccccc"), result[2], L"Policy data no.3 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			PasswordPhilosophy day02;

			// Act:
			uint64_t result = day02.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(2ull, result);
		}
	};

	std::vector<std::string> Day02::inputData = std::vector<std::string>();
}