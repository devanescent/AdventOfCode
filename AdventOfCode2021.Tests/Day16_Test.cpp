#include "stdafx.h"
#include "Day16\Day16_PacketDecoder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day16;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day16)
	{
	private:
		static std::vector<std::string> inputData1;
		static std::vector<std::string> inputData2;
		static std::vector<std::string> inputData3;
		static std::vector<std::string> inputData4;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>{ "8A004A801A8002F478" };	
			inputData2 = std::vector<std::string>{ "620080001611562C8802118E34" };
			inputData3 = std::vector<std::string>{ "C0015000016115A2E0802F182340" };
			inputData4 = std::vector<std::string>{ "A0016C880162017C3686B18A3D4780" };
		}

		TEST_METHOD(CheckExample1_Part1)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1(inputData1);

			// Assert:
			Assert::AreEqual(16ull, result);
		}

		TEST_METHOD(CheckExample2_Part1)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1(inputData2);

			// Assert:
			Assert::AreEqual(12ull, result);
		}

		TEST_METHOD(CheckExample3_Part1)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1(inputData3);

			// Assert:
			Assert::AreEqual(23ull, result);
		}

		TEST_METHOD(CheckExample4_Part1)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1(inputData4);

			// Assert:
			Assert::AreEqual(31ull, result);
		}
	};

	std::vector<std::string> Day16::inputData1 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData2 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData3 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData4 = std::vector<std::string>();
}