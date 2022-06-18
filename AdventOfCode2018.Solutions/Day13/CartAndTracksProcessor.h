#pragma once
#include "InputProcessorWithContext.h"
#include "CartAndTracks.h"
#include <map>

namespace AdventOfCode::Year2018::Day13
{
	using MineTracks = std::map<std::pair<int, int>, TrackType>;

	class CartsAndTracksProcessor : public InputProcessorWithContextBase<Minecart, MineTracks>
	{
	public:
		std::pair<std::vector<Minecart>, MineTracks> Process(std::vector<std::string> input) override;
	};
}