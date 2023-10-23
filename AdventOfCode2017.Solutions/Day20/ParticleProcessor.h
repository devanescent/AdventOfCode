#pragma once
#include "InputProcessor.h"
#include "Particle.h"

namespace AdventOfCode::Year2017::Day20
{
	class ParticleProcessor : public InputProcessorBase<Particle>
	{
	public:
		std::vector<Particle> Process(std::vector<std::string> input) override;
	};
}
