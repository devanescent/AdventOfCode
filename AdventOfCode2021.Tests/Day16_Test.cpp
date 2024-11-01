#include "stdafx.h"
#include "Day16/Day16_PacketDecoder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AdventOfCode::Year2021::Day16;

namespace AdventOfCode::Year2021::Tests
{
	TEST_CLASS(Day16)
	{
	public:
		TEST_METHOD(VersionSum_Example1)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1({ "8A004A801A8002F478" });

			// Assert:
			Assert::AreEqual(16ull, result);
		}

		TEST_METHOD(VersionSum_Example2)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1({ "620080001611562C8802118E34" });

			// Assert:
			Assert::AreEqual(12ull, result);
		}

		TEST_METHOD(VersionSum_Example3)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1({ "C0015000016115A2E0802F182340" });

			// Assert:
			Assert::AreEqual(23ull, result);
		}

		TEST_METHOD(VersionSum_Example4)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart1({ "A0016C880162017C3686B18A3D4780" });

			// Assert:
			Assert::AreEqual(31ull, result);
		}

		TEST_METHOD(OperationAdd)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2({ "C200B40A82" });

			// Assert:
			Assert::AreEqual(3ull, result);
		}

		TEST_METHOD(OperationMultiply)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2({ "04005AC33890" });

			// Assert:
			Assert::AreEqual(54ull, result);
		}

		TEST_METHOD(OperationMin)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2({ "880086C3E88112" });

			// Assert:
			Assert::AreEqual(7ull, result);
		}

		TEST_METHOD(OperationMax)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2({ "CE00C43D881120" });

			// Assert:
			Assert::AreEqual(9ull, result);
		}

		TEST_METHOD(OperationGreaterThan)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2({ "D8005AC2A8F0" });

			// Assert:
			Assert::AreEqual(1ull, result);
		}

		TEST_METHOD(OperationLessThan)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2({ "F600BC2D8F" });

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(OperationNotEquals)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2({ "9C005AC2F8F0" });

			// Assert:
			Assert::AreEqual(0ull, result);
		}

		TEST_METHOD(OperationEquals)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2({ "9C0141080250320F1802104A08" });

			// Assert:
			Assert::AreEqual(1ull, result);
		}

		TEST_METHOD(LongerLiteralValue)
		{
			// Arrange:
			PacketDecoder day16;

			// Act:
			uint64_t result = day16.GetResultOnPart2({ "D2FE28" });

			// Assert:
			Assert::AreEqual(2021ull, result);
		}
	};
}