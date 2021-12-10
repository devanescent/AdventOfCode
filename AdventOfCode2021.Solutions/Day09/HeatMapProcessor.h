#pragma once
#include "InputProcessor.h"
#include <utility>

namespace AdventOfCode::Year2021::Day09
{
	struct HeatMapNode
	{
		HeatMapNode(int h) : Height(h), IsMinimum(true) {}
		int Height;
		bool IsMinimum;

		void CompareToNeighbour(HeatMapNode& neighbourNode)
		{
			if (!IsMinimum && !neighbourNode.IsMinimum)
				return;

			bool canBeMin = (Height <= neighbourNode.Height);
			neighbourNode.IsMinimum &= !canBeMin;
			IsMinimum &= canBeMin;
		}

		bool operator==(const HeatMapNode& other) const
		{
			return Height == other.Height && IsMinimum == other.IsMinimum;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "Height: %d | IsMin: %s", Height, IsMinimum ? "true" : "false");
			return std::string(buf);
		}
	};

	class HeatMapProcessor : public InputProcessorBase<std::vector<HeatMapNode>>
	{
	public:
		virtual std::vector<std::vector<HeatMapNode>> Process(std::vector<std::string> input) override;
	};
}