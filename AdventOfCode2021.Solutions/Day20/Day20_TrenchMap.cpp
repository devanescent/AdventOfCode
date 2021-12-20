#include "Day20_TrenchMap.h"

namespace AdventOfCode::Year2021::Day20
{
	TrenchMap::TrenchMap() : DayTC(20, "Trench Map") {}

	// ---------------------------------------------------------------------------
	// Part 1:
	// ---------------------------------------------------------------------------
	uint64_t TrenchMap::ExecutePart1(std::vector<std::string> inputImage, std::string enhancementAlgorithm)
	{
		return ApplyEnhancementAlgorithm(inputImage, enhancementAlgorithm, 2);
	}

	// ---------------------------------------------------------------------------
	// Part 2:
	// ---------------------------------------------------------------------------
	uint64_t TrenchMap::ExecutePart2(std::vector<std::string> inputImage, std::string enhancementAlgorithm)
	{
		return ApplyEnhancementAlgorithm(inputImage, enhancementAlgorithm, 50);
	}

	// ---------------------------------------------------------------------------
	// EnhanceImage
	// ---------------------------------------------------------------------------
	std::vector<std::string> TrenchMap::EnhanceImage(
		const std::vector<std::string>& image,		// the input image to be enhanced
		const std::string& enhancementAlgorithm,	// the enhancement algorithm
		bool infinityLit)									// true if all surrounding pixes of the infinite image are lit ('#') or not ('.')
	{
		// Assume constant width and height:
		int imageWidth = static_cast<int>(image[0].size());
		int imageHeight = static_cast<int>(image.size());

		// Image after enhancement:
		std::vector<std::string> enhancedImage(imageHeight + 2, std::string(imageWidth + 2, ' '));

		// Convert each pixel of the input image (and the surrounding border) to its binary representation:
		for (int y = -1; y < imageHeight + 1; ++y)
		{
			for (int x = -1; x < imageWidth + 1; ++x)
			{
				std::string binPixelRepr = "";

				// Check all surrounding pixels:
				for (int dy = -1; dy <= 1; ++dy)
				{
					for (int dx = -1; dx <= 1; ++dx)
					{
						int xPos = x + dx;
						int yPos = y + dy;

						if (xPos >= 0 && xPos < imageWidth && yPos >= 0 && yPos < imageHeight)
							binPixelRepr += (image[yPos][xPos] == '#' ? '1' : '0');
						else
							binPixelRepr += (infinityLit ? '1' : '0');
					}
				}

				// Convert binary string to number and get resulting pixel from enhancement algorithm:
				int ix = std::stoi(binPixelRepr, nullptr, 2);
				enhancedImage[y + 1][x + 1] = enhancementAlgorithm[ix];
			}
		}

		return enhancedImage;
	}

	// ---------------------------------------------------------------------------
	// EnhanceImage
	// ---------------------------------------------------------------------------
	std::uint64_t TrenchMap::ApplyEnhancementAlgorithm(const std::vector<std::string>& inputImage, const std::string& enhancementAlgorithm, int count)
	{
		std::vector<std::string> image = inputImage;

		bool infinityLit = false;	// states if the infinite pixels around the image are lit or not

		bool toggleInfinity = (enhancementAlgorithm[0] == '#' && enhancementAlgorithm[511] == '.');
		// -> all other combinations do either not toggle or do not create a valid enhancement algorithm

		// Apply enhancement algorithm two times:
		for (int i = 0; i < count; ++i)
		{
			image = EnhanceImage(image, enhancementAlgorithm, infinityLit);
			if (toggleInfinity) infinityLit = !infinityLit;
		}

		// Count all lit pixels:
		uint64_t litPixels = 0;
		for (const auto& imageRow : image)
		{
			for (const auto pixel : imageRow)
			{
				if (pixel == '#')
					++litPixels;
			}
		}

		return litPixels;
	}
}