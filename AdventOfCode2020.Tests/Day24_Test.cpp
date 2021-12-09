#include "stdafx.h"
#include "Day24\Day24_LobbyLayout.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2020::Day24;

template<> static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::
ToString<HexCoords>(const HexCoords& hex) { return to_wstring(hex.ToString()); }

namespace AdventOfCode::Year2020::Tests
{
	TEST_CLASS(Day24)
	{
	private:
		static std::vector<std::string> inputData;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData = std::vector<std::string>
			{
				"sesenwnenenewseeswwswswwnenewsewsw",
				"neeenesenwnwwswnenewnwwsewnenwseswesw",
				"seswneswswsenwwnwse",
				"nwnwneseeswswnenewneswwnewseswneseene",
				"swweswneswnenwsewnwneneseenw",
				"eesenwseswswnenwswnwnwsewwnwsene",
				"sewnenenenesenwsewnenwwwse",
				"wenwwweseeeweswwwnwwe",
				"wsweesenenewnwwnwsenewsenwwsesesenwne",
				"neeswseenwwswnwswswnw",
				"nenwswwsewswnenenewsenwsenwnesesenew",
				"enewnwewneswsewnwswenweswnenwsenwsw",
				"sweneswneswneneenwnewenewwneswswnese",
				"swwesenesewenwneswnwwneseswwne",
				"enesenwswwswneneswsenwnewswseenwsese",
				"wnwnesenesenenwwnenwsewesewsesesew",
				"nenewswnwewswnenesenwnesewesw",
				"eneswnwswnwsenenwnwnwwseeswneewsenese",
				"neswnwewnwnwseenwseesewsenwsweewe",
				"wseweeenwnesenwwwswnew"
			};
		}

		TEST_METHOD(ParseInput)
		{
			// Arrange:
			HexProcessor hexProc;

			// Act:
			std::vector<HexCoords> result = hexProc.Process(inputData);

			// Assert:
			Assert::AreEqual(HexCoords(-3, -1), result[0], L"HexCoords no.1 incorrect!");
			Assert::AreEqual(HexCoords(1, -2), result[1], L"HexCoords no.2 incorrect!");
			Assert::AreEqual(HexCoords(-3, 0), result[2], L"HexCoords no.3 incorrect!");
		}

		TEST_METHOD(CheckExample_Part1)
		{
			// Arrange:
			LobbyLayout day24;

			// Act:
			uint64_t result = day24.GetResultOnPart1(inputData);

			// Assert:
			Assert::AreEqual(10ull, result);
		}
	};

	std::vector<std::string> Day24::inputData = std::vector<std::string>();
}