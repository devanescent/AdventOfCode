#include "ParticleProcessor.h"
#include <sstream>

namespace AdventOfCode::Year2017::Day20
{
	std::vector<Particle> ParticleProcessor::Process(std::vector<std::string> input)
	{
		// Format: p=< 4,0,0>, v=< 0,0,0>, a=<-2,0,0>

		std::vector<Particle> particles;

		int order = 0;
		for (const std::string& line : input)
		{
			std::istringstream iss(line);
			char discard;

			Particle p;
			p.Order = order;

			iss >> discard >> discard >> discard; // "p" | "=" | "<"

			// Position:
			iss >> p.Position.X >> discard >> p.Position.Y >> discard >> p.Position.Z
				 >> discard >> discard >> discard >> discard >> discard; // ">" | "," | "v" | "=" | "<"

			// Velocity:
			iss >> p.Velocity.X >> discard >> p.Velocity.Y >> discard >> p.Velocity.Z
				 >> discard >> discard >> discard >> discard >> discard; // ">" | "," | "a" | "=" | "<"

			// Acceleration:
			iss >> p.Acceleration.X >> discard >> p.Acceleration.Y >> discard >> p.Acceleration.Z;

			particles.emplace_back(p);
			++order;
		}

		return particles;
	}
}
