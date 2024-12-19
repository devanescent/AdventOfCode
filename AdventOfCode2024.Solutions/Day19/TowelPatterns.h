#pragma once
#include "InputProcessorWithContext.h"
#include <map>
#include <string_view>

namespace AdventOfCode::Year2024::Day19
{
	using DisplayDesign = std::string;
	using TowelPattern = std::string;

	class TowelPatterns
	{
	private:
		std::vector<TowelPattern> _patterns;
		std::map<std::string, uint64_t, std::less<>> _knownPatternOptions;

		bool AppendAndMatchPattern(const TowelPattern& pattern, const DisplayDesign& targetDesign, int currentDesignIx) const
		{
			// Compare stripe for stripe until a mismatch is found:
			for (int i = 0; i < pattern.length(); ++i)
			{
				auto designIx = currentDesignIx + i;
				if (designIx >= targetDesign.length() || targetDesign[designIx] != pattern[i])
				{
					// Some part of the pattern does not match the target design or the appended pattern was to long:
					return false;
				}
			}

			return true;
		}

	public:
		void AddPattern(TowelPattern pattern)
		{
			_patterns.emplace_back(std::move(pattern));
		}

		// Check if design can be created from available patterns:
		bool CanCreateDesign(const DisplayDesign& targetDesign, int currentDesignIx) const
		{
			for (const auto& pattern : _patterns)
			{
				// Try appending each pattern to the current design so far and
				// compare to the required design:
				bool patternMatches = AppendAndMatchPattern(pattern, targetDesign, currentDesignIx);
				int newDesignIx = currentDesignIx + pattern.length();

				if (!patternMatches)
				{
					continue;
				}
				else if (newDesignIx == targetDesign.length())
				{
					// Full design was matched:
					return true;
				}
				else
				{
					// If it does not match the full design recursivly append more patterns:
					if (CanCreateDesign(targetDesign, newDesignIx))
						return true;
				}
			}

			// If the function ends up here, no combination of patterns matched the required design:
			return false;
		}

		// Count all possible options of combining patterns to create a design
		uint64_t CountDesignOptions(const DisplayDesign& targetDesign, int currentDesignIx)
		{
			uint64_t designOptions = 0;

			for (const auto& pattern : _patterns)
			{
				// Try appending each pattern to the current design so far and
				// compare to the required design:
				bool patternMatches = AppendAndMatchPattern(pattern, targetDesign, currentDesignIx);
				int newDesignIx = currentDesignIx + pattern.length();

				if (!patternMatches)
				{
					continue;
				}
				else if (newDesignIx == targetDesign.length())
				{
					// Full design was matched:
					++designOptions;
				}
				else
				{
					// Get the rest of the design that has not been matched yet
					// (and the number of options for creating it):
					std::string_view remainingDesign = std::string_view(targetDesign).substr(newDesignIx);
					uint64_t remainingDesignOptions = 0;

					// Check if this part of the design was evaluated before:
					auto knownIt = _knownPatternOptions.find(remainingDesign);
					if (knownIt != _knownPatternOptions.end())
					{
						remainingDesignOptions = knownIt->second;
					}
					else
					{
						// If this part of the design was not created before, count options and remember it if encountered again:
						remainingDesignOptions = CountDesignOptions(targetDesign, newDesignIx);
						_knownPatternOptions.emplace(remainingDesign, remainingDesignOptions);
					}

					designOptions += remainingDesignOptions;
				}
			}

			return designOptions;
		}
	};
}