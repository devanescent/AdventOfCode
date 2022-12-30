#include "Day19_NotEnoughMinerals.h"
#include <numeric>
#include <set>
#include <stack>

namespace AdventOfCode::Year2022::Day19
{
	struct ConstructionProgress
	{
		int OreRobots;
		int ClayRobots;
		int ObsidianRobots;
		int GeodeRobots;

		int Ore;
		int Clay;
		int Obsidian;
		int Geodes;

		int TimeRemaining;

		// Default constructor: start with 1 ore robot and the given amount of time
		ConstructionProgress(int time = 0) :
			OreRobots(1), ClayRobots(0), ObsidianRobots(0), GeodeRobots(0),
			Ore(0), Clay(0), Obsidian(0), Geodes(0),
			TimeRemaining(time)
		{}

		// Collects materials until robot can be built:
		bool TryBuildOreRobot(const Blueprint& bp, ConstructionProgress& out_next) const
		{
			out_next = *this;
			while (out_next.TimeRemaining > 1 && (out_next.Ore < bp.OrePerOreRobot))
				out_next.CollectMaterials();

			if (out_next.TimeRemaining < 3)
				return false; // not enough time for the robot to have an effect on geodes
			
			// Build robot (materials are still collected during build):
			out_next.CollectMaterials();
			out_next.Ore -= bp.OrePerOreRobot;
			out_next.OreRobots += 1;
			return true;
		}

		bool TryBuildClayRobot(const Blueprint& bp, ConstructionProgress& out_next) const
		{
			out_next = *this;
			while (out_next.TimeRemaining > 1 && (out_next.Ore < bp.OrePerClayRobot))
				out_next.CollectMaterials();

			if (out_next.TimeRemaining < 4)
				return false; // not enough time for the robot to have an effect on geodes

			// Build robot (materials are still collected during build):
			out_next.CollectMaterials();
			out_next.Ore -= bp.OrePerClayRobot;
			out_next.ClayRobots += 1;
			return true;
		}

		bool TryBuildObsidianRobot(const Blueprint& bp, ConstructionProgress& out_next) const
		{
			out_next = *this;
			while (out_next.TimeRemaining > 1 && (out_next.Ore < bp.OrePerObsidianRobot || out_next.Clay < bp.ClayPerObsidianRobot))
				out_next.CollectMaterials();

			if (out_next.TimeRemaining < 3)
				return false; // not enough time for the robot to have an effect on geodes

			// Build robot (materials are still collected during build):
			out_next.CollectMaterials();
			out_next.Ore -= bp.OrePerObsidianRobot;
			out_next.Clay -= bp.ClayPerObsidianRobot;
			out_next.ObsidianRobots += 1;
			return true;
		}

		bool TryBuildGeodeRobot(const Blueprint& bp, ConstructionProgress& out_next) const
		{
			out_next = *this;
			while (out_next.TimeRemaining > 1 && (out_next.Ore < bp.OrePerGeodeRobot || out_next.Obsidian < bp.ObsidianPerGeodeRobot))
				out_next.CollectMaterials();

			if (out_next.TimeRemaining < 2)
				return false; // not enough time for the robot to have an effect on geodes

			// Build robot (materials are still collected during build):
			out_next.CollectMaterials();
			out_next.Ore -= bp.OrePerGeodeRobot;
			out_next.Obsidian -= bp.ObsidianPerGeodeRobot;
			out_next.GeodeRobots += 1;
			return true;
		}

		int GetMaxPossibleGeodes() const
		{
			// Assume a geode robot can be built every minute:
			int estGeodes = Geodes;
			int estGeodeRobots = GeodeRobots;
			for (int t = 0; t < TimeRemaining; ++t)
			{
				estGeodes += estGeodeRobots;
				++estGeodeRobots;
			}
			return estGeodes;
		}

		int GetOpenedGeodes() const
		{
			// Get number of geodes that can be opened with the current robots until time is up:
			return Geodes + GeodeRobots * TimeRemaining;
		}

	private:
		void CollectMaterials()
		{
			TimeRemaining -= 1;
			Ore += OreRobots;
			Clay += ClayRobots;
			Obsidian += ObsidianRobots;
			Geodes += GeodeRobots;
		}
	};

	uint64_t GetMaxOpenedGeodes(const Blueprint& b, int time)
	{
		// Do not build more robots for a type of material than needed to build another robot:
		int maxOreCost = std::max(std::max(std::max(b.OrePerOreRobot, b.OrePerClayRobot), b.OrePerObsidianRobot), b.OrePerGeodeRobot);
		int maxClayCost = b.ClayPerObsidianRobot;
		int maxObsidianCost = b.ObsidianPerGeodeRobot;

		std::stack<ConstructionProgress> s;
		ConstructionProgress start(time);
		s.push(start);

		uint64_t maxGeodes = 0;
		while (!s.empty())
		{
			ConstructionProgress cp = s.top();
			s.pop();

			// Estimate geodes to skip states that cannot possibly open more geodes than the curent max:
			if (cp.GetMaxPossibleGeodes() < maxGeodes)
				continue;

			// Try constructing robots if there is enough time left for the robot to have an effect:
			// Max. number of a robot type = maximum cost of dependant robots
			bool constructedRobot = false;
			ConstructionProgress next;

			if (cp.TryBuildGeodeRobot(b, next))
			{
				constructedRobot = true;
				s.push(next);
			}

			if (cp.ObsidianRobots < maxObsidianCost && cp.TryBuildObsidianRobot(b, next))
			{
				constructedRobot = true;
				s.push(next);
			}

			if (cp.ClayRobots < maxClayCost && cp.TryBuildClayRobot(b, next))
			{
				constructedRobot = true;
				s.push(next);
			}

			if (cp.OreRobots < maxOreCost&& cp.TryBuildOreRobot(b, next))
			{
				constructedRobot = true;
				s.push(next);
			}

			if (!constructedRobot)
			{
				uint64_t geodes = cp.GetOpenedGeodes();
				maxGeodes = geodes > maxGeodes ? geodes : maxGeodes;
			}
		}

		return maxGeodes;
	}


	NotEnoughMinerals::NotEnoughMinerals() : DayT(19, "Not Enough Minerals") { }

	uint64_t NotEnoughMinerals::ExecutePart1(std::vector<Blueprint> blueprints)
	{
		return std::accumulate(blueprints.begin(), blueprints.end(), 0ull,
			[](uint64_t qualityLevelSum, const Blueprint& b)
			{
				// Sum up quality levels:
				return qualityLevelSum + GetMaxOpenedGeodes(b, 24) * b.ID;
			}
		);
	}

	uint64_t NotEnoughMinerals::ExecutePart2(std::vector<Blueprint> blueprints)
	{
		uint64_t maxGeodeProduct = 1;

		// Try only the first three blueprints:
		for (int i = 0; i < 3; ++i)
		{
			if (i >= blueprints.size())
				break;

			maxGeodeProduct *= GetMaxOpenedGeodes(blueprints[i], 32);
		}

		return maxGeodeProduct;
	}
}
