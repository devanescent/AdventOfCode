#include "Day20_ParticleSwarm.h"
#include <algorithm>
#include <map>

namespace AdventOfCode::Year2017::Day20
{
	ParticleSwarm::ParticleSwarm() : DayT(20, "Particle Swarm") { }

	uint64_t ParticleSwarm::ExecutePart1(std::vector<Particle> particles)
	{
		// Sort by acceleration length, then velocity length, then distance to origin
		auto closestParticle = std::min_element(particles.begin(), particles.end(),
			[](const Particle& p1, const Particle& p2)
			{
				auto acc1 = p1.Acceleration.GetLength();
				auto acc2 = p2.Acceleration.GetLength();

				if (acc1 != acc2)
					return acc1 < acc2;
				else
				{
					auto v1 = p1.Velocity.GetLength();
					auto v2 = p2.Velocity.GetLength();
					if (v1 != v2)
						return v1 < v2;
					else
					{
						return p1.Position.GetLength() < p2.Position.GetLength();
					}
				}
			}
		);

		return closestParticle->Order;
	}

	uint64_t ParticleSwarm::ExecutePart2(std::vector<Particle> particles)
	{
		// Simulate 100 ticks to find all collisions:
		for (int t = 0; t < 100; ++t)
		{
			// Update particles and find collisions:
			std::map<Vector3, std::vector<int>> particlesByPos;

			for (int i = 0; i < particles.size(); ++i)
			{
				Particle& p = particles[i];
				p.Velocity = p.Velocity + p.Acceleration;
				p.Position = p.Position + p.Velocity;
				particlesByPos[p.Position].push_back(p.Order);
			}

			// Remove particles that have the same position:
			for (auto& kv : particlesByPos)
			{
				if (kv.second.size() > 1)
				{
					std::erase_if(particles, 
						[&kv](const Particle& p)
						{
							return std::find(kv.second.begin(), kv.second.end(), p.Order) != kv.second.end();
						});
				}
			}
		}

		return particles.size();
	}
}
