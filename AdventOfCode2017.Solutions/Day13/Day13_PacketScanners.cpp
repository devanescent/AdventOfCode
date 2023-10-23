#include "Day13_PacketScanners.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2017::Day13
{
	PacketScanners::PacketScanners() : DayT(13, "Packet Scanners") { }

	uint64_t PacketScanners::ExecutePart1(std::vector<FirewallLayer> fwLayers)
	{
		int maxDepth = std::max_element(fwLayers.begin(), fwLayers.end(),
			[](const FirewallLayer& layer1, const FirewallLayer& layer2)
			{ return layer1.Depth < layer2.Depth; }
		)->Depth;

		// Map firewall layers by depth:
		std::map<int, FirewallLayer*> fwMap;
		for (auto& fwLayer : fwLayers)
			fwMap[fwLayer.Depth] = &fwLayer;

		// Run trip:
		int currentDepth = 0;
		uint64_t severity = 0;
		do
		{
			auto currentFwLayer = fwMap.find(currentDepth);
			if (currentFwLayer != fwMap.end() && currentFwLayer->second->ScannerPos == 0)
			{
				// Got caught:
				severity += currentFwLayer->second->Depth * currentFwLayer->second->Range;
			}

			// Move scanners:
			for (auto& fwLayer : fwLayers)
			{
				if (fwLayer.ScanDir == ScannerDirection::Down)
				{
					++fwLayer.ScannerPos;
					if (fwLayer.ScannerPos == fwLayer.Range - 1)
						fwLayer.ScanDir = ScannerDirection::Up;
				}
				else
				{
					--fwLayer.ScannerPos;
					if (fwLayer.ScannerPos == 0)
						fwLayer.ScanDir = ScannerDirection::Down;
				}
			}

			++currentDepth;

		} while (currentDepth <= maxDepth);

		return severity;
	}

	uint64_t PacketScanners::ExecutePart2(std::vector<FirewallLayer> fwLayers)
	{
		uint64_t delay = 0;
		bool wasCaught;

		// Find lowest possible delay to pass without being caught:
		do
		{
			wasCaught = false;
			++delay;
			for (auto& layer : fwLayers)
			{
				auto scannerPeriod = (layer.Range - 1) * 2;
				auto arrivalTime = layer.Depth + delay;
			
				// Check if scanner is at the top position:
				if (arrivalTime % scannerPeriod == 0)
				{
					wasCaught = true;
					break;
				}
			}

		} while (wasCaught);

		return delay;
	}
}
