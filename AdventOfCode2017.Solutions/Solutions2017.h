#pragma once
#include <memory>
#include "Solutions.h"
#include "Day01\Day01_InverseCaptcha.h"
#include "Day02\Day02_CorruptionChecksum.h"
#include "Day03\Day03_SpiralMemory.h"
#include "Day04\Day04_HighEntropyPassphrases.h"
#include "Day05\Day05_AMazeOfTwistyTrampolinesAllAlike.h"
#include "Day06\Day06_MemoryReallocation.h"
#include "Day07\Day07_RecursiveCircus.h"
#include "Day08\Day08_IHeardYouLikeRegisters.h"
#include "Day09\Day09_StreamProcessing.h"
#include "Day10\Day10_KnotHash.h"
#include "Day11\Day11_HexEd.h"
#include "Day12\Day12_DigitalPlumber.h"
#include "Day13\Day13_PacketScanners.h"
#include "Day14\Day14_DiskDefragmentation.h"
#include "Day15\Day15_DuelingGenerators.h"
#include "Day16\Day16_PermutationPromenade.h"

namespace AdventOfCode::Year2017
{
	class Solutions2017 : public Solutions
	{
		std::unique_ptr<Day> GetDay(int day) override
		{
			switch (day)
			{
				case  1:	return std::make_unique<Day01::InverseCaptcha>();
				case  2:	return std::make_unique<Day02::CorruptionChecksum>();
				case  3:	return std::make_unique<Day03::SpiralMemory>();
				case  4:	return std::make_unique<Day04::HighEntropyPassphrases>();
				case  5:	return std::make_unique<Day05::AMazeOfTwistyTrampolinesAllAlike>();
				case  6:	return std::make_unique<Day06::MemoryReallocation>();
				case  7:	return std::make_unique<Day07::RecursiveCircus>();
				case  8:	return std::make_unique<Day08::IHeardYouLikeRegisters>();
				case  9:	return std::make_unique<Day09::StreamProcessing>();
				case 10:	return std::make_unique<Day10::KnotHash>();
				case 11:	return std::make_unique<Day11::HexEd>();
				case 12:	return std::make_unique<Day12::DigitalPlumber>();
				case 13:	return std::make_unique<Day13::PacketScanners>();
				case 14:	return std::make_unique<Day14::DiskDefragmentation>();
				case 15:	return std::make_unique<Day15::DuelingGenerators>();
				case 16:	return std::make_unique<Day16::PermutationPromenade>();
				default:	return nullptr;
			}
		}
	};
}

