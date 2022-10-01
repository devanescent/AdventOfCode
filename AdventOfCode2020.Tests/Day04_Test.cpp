#include "stdafx.h"
#include "Day04\Day04_PassportProcessing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day04;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<Passport>(const Passport& pp) { return to_wstring(pp.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day04)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"ecl:gry pid:860033327 eyr:2020 hcl:#fffffd",
				"byr:1937 iyr:2017 cid:147 hgt:183cm",
				"",
				"iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884",
				"hcl:#cfa07d byr:1929",
				"",
				"hcl:#ae17e1 iyr:2013",
				"eyr:2024",
				"ecl:brn pid:760753108 byr:1931",
				"hgt:179cm",
				"",
				"hcl:#cfa07d eyr:2025 pid:166559648",
				"iyr:2011 ecl:brn hgt:59in"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			PassportProcessor ppProc;

			// Act:
			std::vector<Passport> result = ppProc.Process(inputData);

			// Assert:
			Assert::AreEqual(Passport("1937", "2017", "2020", "183cm", "#fffffd", "gry", "860033327", "147"), result[0], L"Passport data no.1 incorrect!");
			Assert::AreEqual(Passport("1929", "2013", "2023", "", "#cfa07d", "amb", "028048884", "350"), result[1], L"Passport data no.2 incorrect!");
			Assert::AreEqual(Passport("1931", "2013", "2024", "179cm", "#ae17e1", "brn", "760753108", ""), result[2], L"Passport data no.3 incorrect!");
			Assert::AreEqual(Passport("", "2011", "2025", "59in", "#cfa07d", "brn", "166559648", ""), result[3], L"Passport data no.4 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			PassportProcessing sut = PassportProcessing();

			// Act:
			uint64_t result = sut.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(2ull, result);
		}

		TEST_METHOD(CheckExample1_Part2)
		{
			// Arrange:
			PassportProcessing sut = PassportProcessing();

			// Act:
			uint64_t result = sut.GetResultOnPart2(
				{
					"eyr:1972 cid:100",
					"hcl:#18171d ecl:amb hgt:170 pid:186cm iyr:2018 byr:1926",
					"",
					"iyr:2019",
					"hcl:#602927 eyr:1967 hgt:170cm",
					"ecl:grn pid:012533040 byr:1946",
					"",
					"hcl:dab227 iyr:2012",
					"ecl:brn hgt:182cm pid:021572410 eyr:2020 byr:1992 cid:277",
					"",
					"hgt:59cm ecl:zzz",
					"eyr:2038 hcl:74454a iyr:2023",
					"pid:3556412378 byr:2007"
				}
			);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(CheckExample2_Part2)
		{
			// Arrange:
			PassportProcessing sut = PassportProcessing();

			// Act:
			uint64_t result = sut.GetResultOnPart2(
				{
					"pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980",
					"hcl:#623a2f",
					"",
					"eyr:2029 ecl:blu cid:129 byr:1989",
					"iyr:2014 pid:896056539 hcl:#a97842 hgt:165cm",
					"",
					"hcl:#888785",
					"hgt:164cm byr:2001 iyr:2015 cid:88",
					"pid:545766238 ecl:hzl",
					"eyr:2022",
					"",
					"iyr:2010 hgt:158cm hcl:#b6652a ecl:blu byr:1944 eyr:2021 pid:093154719"
				}
			);

			// Assert:
			Assert::AreEqual(4ull, result);
		}
	};

	std::vector<std::string> Day04::inputData = std::vector<std::string>();
}