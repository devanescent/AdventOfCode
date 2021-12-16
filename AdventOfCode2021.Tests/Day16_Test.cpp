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

		static std::vector<std::string> inputData5;
		static std::vector<std::string> inputData6;
		static std::vector<std::string> inputData7;
		static std::vector<std::string> inputData8;
		static std::vector<std::string> inputData9;
		static std::vector<std::string> inputData10;
		static std::vector<std::string> inputData11;
		static std::vector<std::string> inputData12;
		static std::vector<std::string> inputData13;

	public:
		TEST_CLASS_INITIALIZE(Init)
		{
			inputData1 = std::vector<std::string>{ "8A004A801A8002F478" };	
			inputData2 = std::vector<std::string>{ "620080001611562C8802118E34" };
			inputData3 = std::vector<std::string>{ "C0015000016115A2E0802F182340" };
			inputData4 = std::vector<std::string>{ "A0016C880162017C3686B18A3D4780" };

			inputData5 = std::vector<std::string>{ "C200B40A82" };
			inputData6 = std::vector<std::string>{ "04005AC33890" };
			inputData7 = std::vector<std::string>{ "880086C3E88112" };
			inputData8 = std::vector<std::string>{ "CE00C43D881120" };
			inputData9 = std::vector<std::string>{ "D8005AC2A8F0" };
			inputData10 = std::vector<std::string>{ "F600BC2D8F" };
			inputData11 = std::vector<std::string>{ "9C005AC2F8F0" };
			inputData12 = std::vector<std::string>{ "9C0141080250320F1802104A08" };
			inputData13 = std::vector<std::string>{ "D2FE28" };
		}

		TEST_METHOD(VersionSum_Example1)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1(inputData1);

			// Assert:
			Assert::AreEqual(16ull, result);
		}

		TEST_METHOD(VersionSum_Example2)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1(inputData2);

			// Assert:
			Assert::AreEqual(12ull, result);
		}

		TEST_METHOD(VersionSum_Example3)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1(inputData3);

			// Assert:
			Assert::AreEqual(23ull, result);
		}

		TEST_METHOD(VersionSum_Example4)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1(inputData4);

			// Assert:
			Assert::AreEqual(31ull, result);
		}

		TEST_METHOD(OperationAdd)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2(inputData5);

			// Assert:
			Assert::AreEqual(3ull, result);
		}

		TEST_METHOD(OperationMultiply)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2(inputData6);

			// Assert:
			Assert::AreEqual(54ull, result);
		}

		TEST_METHOD(OperationMin)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2(inputData7);

			// Assert:
			Assert::AreEqual(7ull, result);
		}

		TEST_METHOD(OperationMax)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2(inputData8);

			// Assert:
			Assert::AreEqual(9ull, result);
		}

		TEST_METHOD(OperationGreaterThan)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2(inputData9);

			// Assert:
			Assert::AreEqual(1ull, result);
		}

		TEST_METHOD(OperationLessThan)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2(inputData10);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(OperationNotEquals)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2(inputData11);

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(OperationEquals)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2(inputData12);

			// Assert:
			Assert::AreEqual(1ull, result);
		}

		TEST_METHOD(LongerLiteralValue)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2(inputData13);

			// Assert:
			Assert::AreEqual(2021ull, result);
		}
	};

	std::vector<std::string> Day16::inputData1 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData2 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData3 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData4 = std::vector<std::string>();

	std::vector<std::string> Day16::inputData5 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData6 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData7 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData8 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData9 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData10 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData11 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData12 = std::vector<std::string>();
	std::vector<std::string> Day16::inputData13 = std::vector<std::string>();
}