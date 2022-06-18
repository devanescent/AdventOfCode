#include "Day13_MineCartMadness.h"
#include <set>

namespace AdventOfCode::Year2018::Day13
{
	MineCartMadness::MineCartMadness() : DayTC(13, "Mine Cart Madness")
	{}

	void MoveCart(Minecart& cart, TrackType tt)
	{
		switch (tt)
		{
		case TrackType::Horizontal: // '-'
		case TrackType::Vertical:   // '|'
			cart.MoveForward();
			break;
		case TrackType::RightCurve: // '/'
			// Right turn for carts comming from top or below.
			// For carts coming from left or right, this is actually a left turn.
			if (cart.GetForwardDirection() == Direction::Up || cart.GetForwardDirection() == Direction::Down)
				cart.TurnRight();
			else
				cart.TurnLeft();
			break;
		case TrackType::LeftCurve:	// '\'
			// Left turn for carts comming from top or below.
			// For carts coming from left or right, this is actually a right turn.
			if (cart.GetForwardDirection() == Direction::Up || cart.GetForwardDirection() == Direction::Down)
				cart.TurnLeft();
			else
				cart.TurnRight();
			break;
		case TrackType::Intersection:	// '+'
			cart.PassIntersection();
			break;
		}
	}

	bool FindNextCollision(
		std::set<Minecart>& mineCarts, 
		const MineTracks& tracks, 
		bool removeCollidedCartsAndContinue, 
		std::pair<int, int>& out_collisionCoords)
	{
		// For each 'tick': update all carts in correct order and check for collisions:
		while (mineCarts.size() > 1)
		{
			std::set<Minecart> updatedCarts;

			auto cartToUpdate = mineCarts.begin();
			while (cartToUpdate != mineCarts.end())
			{
				// Make a copy to update cart:
				Minecart cart = *cartToUpdate;
				MoveCart(cart, tracks.at(cart.GetPosition()));

				// Check in the original list, if there is a cart at the new position:
				// that has not been moved during the current tick:
				auto nextCartNotUpdated = cartToUpdate;
				nextCartNotUpdated++;
				auto colWithNotUpdatedCart = std::find(nextCartNotUpdated, mineCarts.end(), cart);

				// Check in the new list, if there is already a cart at the new position:
				auto colWithUpdatedCart = updatedCarts.insert(cart);

				bool hasCollided = 
					colWithNotUpdatedCart != mineCarts.end() || 
					!colWithUpdatedCart.second; // Failed to insert: another cart already occupied this position

				if (hasCollided)
				{
					out_collisionCoords = cart.GetPosition();
					if (removeCollidedCartsAndContinue)
					{
						// remove the previously inserted cart also, with which the collision occured
						// or the just inserted cart if it collided with one that has not moved yet:
						updatedCarts.erase(colWithUpdatedCart.first);

						// If the collision happened with a cart not updated yet, remove this from
						// the iterated collection:
						if (colWithNotUpdatedCart != mineCarts.end()) mineCarts.erase(colWithNotUpdatedCart);
					}
					else
						return true;
				}
				
				cartToUpdate++;
			}

			mineCarts = std::move(updatedCarts);
		}

		return false;
	}
	
	uint64_t MineCartMadness::ExecutePart1(std::vector<Minecart> mineCarts, MineTracks tracks)
	{
		// Put in set for ordered iteration and collision detection:
		std::set<Minecart> carts(mineCarts.begin(), mineCarts.end());

		std::pair<int, int> firstCollision;
		FindNextCollision(carts, tracks, false, firstCollision);

		return 0ull;
	}


	uint64_t MineCartMadness::ExecutePart2(std::vector<Minecart> mineCarts, MineTracks tracks)
	{
		// Put in set for ordered iteration and collision detection:
		std::set<Minecart> carts(mineCarts.begin(), mineCarts.end());

		// Let the cards collide until only one remains:
		std::pair<int, int> collision;
		while (FindNextCollision(carts, tracks, true, collision));

		auto lastCartPos = carts.begin()->GetPosition();

		return 0ull;
	}
}
