#pragma once
#include "InitializationContext.h"
#include <string>

namespace AdventOfCode::Year2020::Day14
{
	class InitializationInstruction
	{
	private:
		enum class InstructionType { Mask, Mem };

		uint64_t m_address;
		uint64_t m_value;
		std::string m_mask;
		InstructionType m_instrType;

	public:
		InitializationInstruction(uint64_t addr, uint64_t val) :
			m_address(addr), m_value(val), m_instrType(InstructionType::Mem)
		{}

		InitializationInstruction(std::string mask) :
			m_address(0), m_value(0), m_mask(std::move(mask)), m_instrType(InstructionType::Mask)
		{}

		void Execute(InitializationContext& ctx)
		{
			switch (m_instrType)
			{
			case InstructionType::Mask:
				ctx.UpdateBitmask(m_mask);
				break;
			case InstructionType::Mem:
				ctx.WriteToMemory(m_address, m_value);
				break;
			}
		}

		bool operator==(const InitializationInstruction& other) const
		{
			return m_address == other.m_address && m_value == other.m_value && m_mask == other.m_mask && m_instrType == other.m_instrType;
		}

		std::string ToString() const
		{
			char buf[256] {0};

			switch (m_instrType)
			{
			case InstructionType::Mask:
				snprintf(buf, sizeof(buf), "Mask=%s", m_mask.c_str());
				break;
			case InstructionType::Mem:
				snprintf(buf, sizeof(buf), "Mem[%llu]=%llu", m_address, m_value);
				break;
			}

			return std::string(buf);
		}
	};
}