#pragma once
#include "Point.h"

namespace AdventOfCode::Year2018::Day17
{
	enum class FlowDirection
	{
		Down,
		Left,
		Right
	};

	struct WaterStream
	{
		// Current position of the waterstream's "head"
		Point<int> Head;

		// Current direction of the waterstream
		FlowDirection FlowDir = FlowDirection::Down;

		// Position above a split (to continue from when a line of water
		// inside a reservoir has settled)
		Point<int> UpstreamOrigin;

		// Last horizontal bounds, if both are set, water will settle between them
		// Reset on downwards movement
		int LastLeftBound = -1;
		int LastRightBound = -1;

		WaterStream(int xOrig, int yOrig, FlowDirection flowDir = FlowDirection::Down) : 
			WaterStream(Point(xOrig, yOrig), flowDir)
		{}

		explicit WaterStream(Point<int> headOrig, FlowDirection flowDir = FlowDirection::Down) :
			Head(headOrig), FlowDir(flowDir)
		{
			UpstreamOrigin = Head.MoveYBy(-1);
			
			// Initial direction of left / right only after branching
			if (flowDir == FlowDirection::Left)
				++UpstreamOrigin.X; // Origin is at top right corner
			else if (flowDir == FlowDirection::Right)
				--UpstreamOrigin.X; // Origin is at top left corner
		}
		
		// Get the next position the water stream will reach
		Point<int> GetNextHeadPos() const
		{
			switch (FlowDir)
			{
				case FlowDirection::Down:
					return Head.MoveYBy(1);
				case FlowDirection::Left:
					return Head.MoveXBy(-1);
				case FlowDirection::Right:
					return Head.MoveXBy(+1);
				default:
					return Head;
			}
		}

		void MoveDown()
		{
			FlowDir = FlowDirection::Down;
			UpstreamOrigin = Head;
			++Head.Y;
			LastLeftBound = -1;
			LastRightBound = -1;
		}

		// Update the water stream's head position and related variables:
		void MoveForward()
		{
			switch (FlowDir)
			{
				case FlowDirection::Down:
					MoveDown();
					break;
				case FlowDirection::Left:
					--Head.X;
					break;
				case FlowDirection::Right:
					++Head.X;
					break;
			}
		}

		// Set (horizontal) bounds and reverse direction:
		void SetBlockedAndReverse(int xBlock)
		{
			if (FlowDir == FlowDirection::Left)
			{
				LastLeftBound = xBlock;
				FlowDir = FlowDirection::Right;
			}
			else if (FlowDir == FlowDirection::Right)
			{
				LastRightBound = xBlock;
				FlowDir = FlowDirection::Left;
			}
		}

		bool IsBlockedInBothDirs() const
		{
			return LastRightBound != -1 && LastLeftBound != -1;
		}

		// Range of water tiles between both bounds:
		Range<int> GetBoundedWaterRange()
		{
			if (IsBlockedInBothDirs())
				return Range(LastLeftBound + 1, LastRightBound - 1);
			else
				return Range<int>();
		}

		std::pair<WaterStream, WaterStream> Branch()
		{
			return std::make_pair(
				WaterStream(Head.MoveXBy(-1), FlowDirection::Left), 
				WaterStream(Head.MoveXBy(+1), FlowDirection::Right)
			);
		}
	};
}