#pragma once
#include "InputProcessor.h"
#include "Room.h"

namespace AdventOfCode::Year2018::Day20
{
	class RoomProcessor : public InputProcessorBase<Room>
	{
	public:
		std::vector<Room> Process(std::vector<std::string> input) override;
	};
}
