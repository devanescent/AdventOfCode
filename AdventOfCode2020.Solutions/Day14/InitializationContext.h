#pragma once
#include "InitializationInstruction.h"
#include <algorithm>
#include <map>
#include <numeric>
#include <vector>

namespace AdventOfCode::Year2020::Day14
{
	class InitializationContext
	{
	public:
		InitializationContext() : m_bitmaskSet(0), m_bitmaskClear(0) {}

		// Bitmask will be split in two mask: one for setting specified bits to '1' 
		// and another one for clearing bits (setting them to '0').
		virtual void UpdateBitmask(const std::string& bitMask)
		{
			// The mask for setting bits will have a '1' in all positions where the bit will be set in the value, '0' otherwise.
			// By applying the mask with the OR operation, all '1' bits are set and all the other positions keep their value.
			std::string setmask = bitMask;
			std::replace(setmask.begin(), setmask.end(), 'X', '0');
			m_bitmaskSet = std::strtoull(setmask.c_str(), nullptr, 2);

			// The mask for clearing bits will have a '0' in all positions where the bit will be cleared, '1' otherwise.
			// By applying the mask with the AND operation, all '0' bits are cleared and all other positions keep their value.
			std::string clearmask = bitMask;
			std::replace(clearmask.begin(), clearmask.end(), 'X', '1');
			m_bitmaskClear = std::strtoull(clearmask.c_str(), nullptr, 2);
		}

		virtual void WriteToMemory(uint64_t addr, uint64_t val)
		{
			m_memory[addr] = ApplyMask(val);
		}

		uint64_t GetMemorySum()
		{
			// Sum up all values currently in memory:
			return std::accumulate(m_memory.cbegin(), m_memory.cend(), 0ull, 
				[](uint64_t sum, const std::pair<const uint64_t, uint64_t>& mem)
				{ 
					return sum + mem.second; 
				}
			);
		}

	protected:
		std::map<uint64_t, uint64_t> m_memory;

	private:
		uint64_t m_bitmaskSet;
		uint64_t m_bitmaskClear;

		uint64_t ApplyMask(uint64_t val)
		{
			return ((val & m_bitmaskClear) | m_bitmaskSet);
		}
	};

	class InitializationContextV2 : public InitializationContext
	{
	public:
		void UpdateBitmask(const std::string& bitMask) override
		{
			// Mask (to be used with OR-operation):
			// 0 - keep original value
			// 1 - overwrite with 1
			// X - floating bit; set all to 1 as initial state
			m_mask = bitMask;
			std::replace(m_mask.begin(), m_mask.end(), 'X', '1');
			m_bitmaskSet = std::strtoull(m_mask.c_str(), nullptr, 2);

			// Indices of floating bits:
			m_floatingBits.clear();
			for (int i = 0; i <= 35; ++i) // Bit 0 to 35
			{
				if (bitMask[35 - i] == 'X') // Bit 0 is the rightmost position
					m_floatingBits.emplace_back(i);
			}
		}

		void WriteToMemory(uint64_t addr, uint64_t val) override
		{
			// Apply the mask initially, then recursively replace the floating bits with zeros:
			ProcessFloatingBits(m_floatingBits.begin(), addr | m_bitmaskSet, val);
		}

		void ProcessFloatingBits(std::vector<int>::iterator bitIx, uint64_t addr, uint64_t val)
		{
			if (bitIx == m_floatingBits.end())
			{
				m_memory[addr] = val;
				return;
			}

			// Keep bit set to 1 and continue with the next floating bit:
			ProcessFloatingBits(bitIx + 1, addr, val);

			// Flip the floating bit to 0:
			// Because each floating bit is initially set to 1, to flip it substract 2^(bit) (or 1 << bit)
			ProcessFloatingBits(bitIx + 1, addr - (1ull << (*bitIx)), val);
		}

	private:
		std::string m_mask;
		uint64_t m_bitmaskSet;
		std::vector<int> m_floatingBits; // Indices of floating bits
	};
}