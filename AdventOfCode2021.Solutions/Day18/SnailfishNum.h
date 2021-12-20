#pragma once
#include <variant>
#include <memory>
#include <string>

namespace AdventOfCode::Year2021::Day18
{
	class SnailfishNum
	{
	public:
		enum class ChildPos
		{
			Undefined,
			LeftChild,
			RightChild
		};

		/*non-owning*/ SnailfishNum* Parent = nullptr;
		ChildPos PosInParent = ChildPos::Undefined;
		int Depth = 0;

		std::variant<int, std::unique_ptr<SnailfishNum>> Left;
		std::variant<int, std::unique_ptr<SnailfishNum>> Right;

		void IncreaseDepth();		// After adding two pairs, increase all depths by one

		bool Explode();				// Explode pairs that are nested too deeply
		bool Split();					// Split numbers too large
		void Reduce();					// Applies Explode() and Split() according to the rules
		uint64_t GetMagnitude();	// Get magnitude of number

		std::string ToString() const { return "[" + PartToString(Left) + "," + PartToString(Right) + "]"; }

	private:
		void AddToNextLeft(int i);
		void AddToNextRight(int i);

		std::string PartToString(const std::variant<int, std::unique_ptr<SnailfishNum>>& part) const;
	};
}