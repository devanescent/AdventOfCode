#include "SnailfishNum.h"

namespace AdventOfCode::Year2021::Day18
{
	// ---------------------------------------------------------------------------
	// IncreaseDepth
	// ---------------------------------------------------------------------------
	void SnailfishNum::IncreaseDepth()
	{
		Depth += 1;
		if (std::holds_alternative<std::unique_ptr<SnailfishNum>>(Left))
			std::get<std::unique_ptr<SnailfishNum>>(Left)->IncreaseDepth();
		if (std::holds_alternative<std::unique_ptr<SnailfishNum>>(Right))
			std::get<std::unique_ptr<SnailfishNum>>(Right)->IncreaseDepth();
	}

	// ---------------------------------------------------------------------------
	// Explode
	// ---------------------------------------------------------------------------
	bool SnailfishNum::Explode()
	{
		if (!std::holds_alternative<int>(Left))
		{
			// Has nested pair to the left: check for explodes
			if (std::get<std::unique_ptr<SnailfishNum>>(Left)->Explode())
				return true;
		}

		if (!std::holds_alternative<int>(Right))
		{
			// Has nested pair to the right: check for explodes
			if (std::get<std::unique_ptr<SnailfishNum>>(Right)->Explode())
				return true;
		}

		// otherwise: check if regular pair with depth of at least 4:
		if (Depth >= 4 && std::holds_alternative<int>(Left) && std::holds_alternative<int>(Right))
		{
			// Explode: add values to nearest value left and right:
			AddToNextLeft(std::get<int>(Left));
			AddToNextRight(std::get<int>(Right));

			// replace self with zero:
			if (PosInParent == ChildPos::LeftChild)
				Parent->Left = 0;
			else if (PosInParent == ChildPos::RightChild)
				Parent->Right = 0;

			// Explode happened:
			return true;
		}

		// No explode happened:
		return false;
	}

	// ---------------------------------------------------------------------------
	// Split
	// ---------------------------------------------------------------------------
	bool SnailfishNum::Split()
	{
		if (!std::holds_alternative<int>(Left))
		{
			// Has nested pair to the left: check for splits
			if (std::get<std::unique_ptr<SnailfishNum>>(Left)->Split())
				return true;
		}
		else if (std::get<int>(Left) >= 10)
		{
			int i = std::get<int>(Left);
			std::unique_ptr<SnailfishNum> newPair = std::make_unique<SnailfishNum>();
			newPair->Left = i / 2;
			newPair->Right = i / 2 + (i % 2 ? 1 : 0); // for odd i, add 1 to "round up"
			newPair->Depth = Depth + 1;
			newPair->Parent = this;
			newPair->PosInParent = ChildPos::LeftChild;
			Left = std::move(newPair);
			return true;
		}

		if (!std::holds_alternative<int>(Right))
		{
			// Has nested pair to the right: check for splits
			if (std::get<std::unique_ptr<SnailfishNum>>(Right)->Split())
				return true;
		}
		else if (std::get<int>(Right) >= 10)
		{
			int i = std::get<int>(Right);
			std::unique_ptr<SnailfishNum> newPair = std::make_unique<SnailfishNum>();
			newPair->Left = i / 2;
			newPair->Right = i / 2 + (i % 2 ? 1 : 0); // for odd i, add 1 to "round up"
			newPair->Depth = Depth + 1;
			newPair->Parent = this;
			newPair->PosInParent = ChildPos::RightChild;
			Right = std::move(newPair);
			return true;
		}

		return false;
	}

	// ---------------------------------------------------------------------------
	// Reduce
	// ---------------------------------------------------------------------------
	void SnailfishNum::Reduce()
	{
		bool reduce = true;

		while (reduce)
		{
			// First, check for explodes; if non happened, check for splits
			if (!Explode())
				reduce = Split(); // After every split, first check again for explodes
		}
	}

	// ---------------------------------------------------------------------------
	// GetMagnitude
	// ---------------------------------------------------------------------------
	uint64_t SnailfishNum::GetMagnitude()
	{
		return 
			3 * (std::holds_alternative<int>(Left) ? 
				std::get<int>(Left) : 
				std::get<std::unique_ptr<SnailfishNum>>(Left)->GetMagnitude()) +
			2 * (std::holds_alternative<int>(Right) ? 
				std::get<int>(Right) : 
				std::get<std::unique_ptr<SnailfishNum>>(Right)->GetMagnitude());
	}

	// ---------------------------------------------------------------------------
	// AddToNextLeft
	// ---------------------------------------------------------------------------
	void SnailfishNum::AddToNextLeft(int i)
	{
		SnailfishNum* target = this;

		// While child is to the left, continue search upwards
		while (target->PosInParent == ChildPos::LeftChild)
			target = target->Parent;

		if (target->PosInParent == ChildPos::Undefined)
			return; // this was the leftmost element, no other number to the left

		// First child to the right: check left sibling
		target = target->Parent;
		if (std::holds_alternative<int>(target->Left))
		{
			std::get<int>(target->Left) += i;
			return;
		}

		// Otherwise: continue search downwards from this
		target = std::get<std::unique_ptr<SnailfishNum>>(target->Left).get();

		// Search downwards to the right:
		while (!std::holds_alternative<int>(target->Right))
			target = std::get<std::unique_ptr<SnailfishNum>>(target->Right).get();

		// Found the number:
		std::get<int>(target->Right) += i;
	}

	// ---------------------------------------------------------------------------
	// AddToNextRight
	// ---------------------------------------------------------------------------
	void SnailfishNum::AddToNextRight(int i)
	{
		SnailfishNum* target = this;

		// While child is to the right, continue search upwards
		while (target->PosInParent == ChildPos::RightChild)
			target = target->Parent;

		if (target->PosInParent == ChildPos::Undefined)
			return; // this was the rightmost element, no other number to the right

		// First child to the left: check right sibling:
		target = target->Parent;
		if (std::holds_alternative<int>(target->Right))
		{
			std::get<int>(target->Right) += i;
			return;
		}

		// Otherwise: continue search downwards from this
		target = std::get<std::unique_ptr<SnailfishNum>>(target->Right).get();

		// Search downwards to the left:
		while (!std::holds_alternative<int>(target->Left))
			target = std::get<std::unique_ptr<SnailfishNum>>(target->Left).get();

		// Found the number:
		std::get<int>(target->Left) += i;
	}

	// ---------------------------------------------------------------------------
	// PartToString
	// ---------------------------------------------------------------------------
	std::string SnailfishNum::PartToString(const std::variant<int, std::unique_ptr<SnailfishNum>>& part) const
	{
		if (std::holds_alternative<int>(part))
			return std::to_string(std::get<int>(part));
		else
			return std::get<std::unique_ptr<SnailfishNum>>(part)->ToString();
	}
}