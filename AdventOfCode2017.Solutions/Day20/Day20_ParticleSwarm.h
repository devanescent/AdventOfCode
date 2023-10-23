#pragma once
#include "DayT.h"
#include "ParticleProcessor.h"

namespace AdventOfCode::Year2017::Day20
{
	// ---------------------------------------------------------------------------
	// Day20: Particle Swarm
	// ---------------------------------------------------------------------------
	class ParticleSwarm : public DayT<ParticleProcessor>
	{
	public:
		ParticleSwarm();

	protected:
		uint64_t ExecutePart1(std::vector<Particle> particles) override;
		uint64_t ExecutePart2(std::vector<Particle> particles) override;
	};
}
