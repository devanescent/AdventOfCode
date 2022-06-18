#include "CartAndTracksProcessor.h"

namespace AdventOfCode::Year2018::Day13
{
	std::pair<std::vector<Minecart>, MineTracks> CartsAndTracksProcessor::Process(std::vector<std::string> input)
	{
		std::pair<std::vector<Minecart>, MineTracks> procResult;
		std::vector<Minecart>& carts = procResult.first;
		MineTracks& tracks = procResult.second;

		int y = 0;
		for (const auto& tracksRow : input)
		{
			int x = 0;
			for (char track : tracksRow)
			{
				switch (track)
				{
					case '>': case '<': carts.emplace_back(x, y, track == '>' ? Direction::Right : Direction::Left); // fall-though to track
					case '-': tracks[{x, y}] = TrackType::Horizontal; break;

					case '^': case 'v': carts.emplace_back(x, y, track == '^' ? Direction::Up : Direction::Down); // fall-though to track
					case '|': tracks[{x, y}] = TrackType::Vertical; break;

					case '/': tracks[{x, y}] = TrackType::RightCurve; break;
					case '\\': tracks[{x, y}] = TrackType::LeftCurve; break;
					case '+': tracks[{x, y}] = TrackType::Intersection; break;
				}
				x++;
			}
			y++;
		}

		return procResult;
	}
}
