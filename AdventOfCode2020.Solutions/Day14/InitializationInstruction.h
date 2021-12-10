#pragma once
#include <map>
#include <numeric>

namespace AdventOfCode::Year2020::Day14
{
	class InitializationContext
	{
	public:
		// Bitmask will be split in two mask: one for setting specified bits to '1' 
		// and another one for clearing bits (setting them to '0').
		// 
		// The mask for setting bits will have a '1' in all positions where the bit will be set in the value, '0' otherwise.
		// By applying the mask with the OR operation, all '1' bits are set and all the other positions keep their value.
		//
		// The mask for clearing bits will have a '0' in all positions where the bit will be cleared, '1' otherwise.
		// By applying the mask with the AND operation, all '0' bits are cleared and all other positions keep their value.
		InitializationContext(uint64_t setMask, uint64_t clearMask) :
			m_bitmaskSet(setMask), m_bitmaskClear(clearMask)
		{}

		void SetMemory(int addr, uint64_t val)
		{
			m_memory[addr] = ApplyMask(val);
		}

		uint64_t GetMemorySum()
		{
			// Get sum of all values currently in memory:
			return std::accumulate(m_memory.cbegin(), m_memory.cend(), (uint64_t)0, 
				[](uint64_t res, const std::pair<int, uint64_t>& p) { return res + p.second; });
		}

	private:
		std::map<int, uint64_t> m_memory;
		uint64_t m_bitmaskSet;
		uint64_t m_bitmaskClear;

		uint64_t ApplyMask(uint64_t val)
		{
			return ((val & m_bitmaskClear) | m_bitmaskSet);
		}
	};

	class InitializationInstruction
	{
	public:
		InitializationInstruction(int addr, int val) :
			m_address(addr), m_value(val)
		{}

		int GetAddress() const { return m_address; }

		void Execute(InitializationContext& ctx)
		{
			ctx.SetMemory(m_address, m_value);
		}

		bool operator==(const InitializationInstruction& other) const
		{
			return m_address == other.m_address && m_value == other.m_value;
		}

		std::string ToString() const
		{
			char buf[256];
			snprintf(buf, sizeof(buf), "Mem[%d]=%d", m_address, m_value);
			return std::string(buf);
		}

	private:
		int m_address;
		int m_value;
	};
}