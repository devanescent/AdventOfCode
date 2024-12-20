#include "Day09_DiskFragmenter.h"
#include "CharDigitConverter.h"
#include <array>

namespace AdventOfCode::Year2024::Day09
{
	DiskFragmenter::DiskFragmenter() : Day(9, "Disk Fragmenter") { }

	uint64_t DiskFragmenter::ExecutePart1(std::vector<std::string> input)
	{
		// Create memory image:
		std::vector<int> memory;
		
		// Iterate over diskmap, which alternately contains files and empty blocks:
		bool isFile = true;
		int fileID = 0;

		for (char c : input[0])
		{
			int blockLen = CharToDigit<int>(c);

			if (isFile)
			{
				// File block:
				for (int i = 0; i < blockLen; ++i)
					memory.push_back(fileID);

				++fileID;
			}
			else
			{
				// Empty block:
				for (int i = 0; i < blockLen; ++i)
					memory.push_back(-1);
			}

			isFile = !isFile;
		}
		
		// Copy from end to fill up empty blocks:
		auto insertIt = memory.begin();
		auto copyFromIt = memory.end() - 1;

		// Keep track of where the last file is to speed up file checksum calculation:
		auto memoryEnd = memory.end();

		while (insertIt < copyFromIt)
		{
			// Advance insert iterator if it's not on free space:
			if (*insertIt != -1)
				++insertIt;

			// Advance copy iterator if it's not on file data:
			if (*copyFromIt == -1)
				--copyFromIt;

			// If both iterators are at valid positions, copy data:
			if (*insertIt == -1 && *copyFromIt != -1)
			{
				*insertIt = *copyFromIt;
				*copyFromIt = -1;

				++insertIt;

				memoryEnd = copyFromIt;
				--copyFromIt;
			}
		}

		// Filesystem checksum:
		uint64_t filesystemChecksum = 0;
		int blockIx = 0;
		for (auto memIt = memory.begin(); memIt != memoryEnd; ++memIt)
		{
			filesystemChecksum += blockIx * *memIt;
			++blockIx;
		}

		return filesystemChecksum;
	}

	class MemoryBlock
	{
	private:
		// Each block has a maximum size of 9:
		std::array<int, 9> _blockMemory = { -1 };

		// Actual block size and offset within total memory
		int _blockSize = 0;
		int _blockOffset = 0;

		// Actual size filled in this block:
		int _dataSize = 0;

	public:
		MemoryBlock(int offset, int size) : _blockSize(size), _blockOffset(offset) {}

		bool AddFile(int fileID, int fileSize)
		{
			// Check if enough space for file:
			if (_blockSize - _dataSize < fileSize)
				return false;

			// Insert file into block memory:
			for (int i = 0; i < fileSize; ++i)
			{
				_blockMemory[_dataSize + i] = fileID;
			}

			_dataSize += fileSize;
			return true;
		}

		void Clear()
		{
			_dataSize = 0;
		}

		int GetDataSize() const { return _dataSize; }

		uint64_t GetChecksum() const
		{
			uint64_t checksum = 0;

			for (int i = 0; i < _dataSize; ++i)
			{
				if (_blockMemory[i] != -1)
					checksum += _blockMemory[i] * (i + _blockOffset);
			}

			return checksum;
		}
	};

	uint64_t DiskFragmenter::ExecutePart2(std::vector<std::string> input)
	{
		std::vector<MemoryBlock> memoryBlocks;

		bool isFile = true;
		int currentFileID = 0;

		int nextBlockIndex = 0;
		for (char c : input[0])
		{
			auto blockSize = CharToDigit<int>(c);
			MemoryBlock mb(nextBlockIndex, blockSize);

			if (isFile)
			{
				// File block
				mb.AddFile(currentFileID, blockSize);
				++currentFileID;
			}

			memoryBlocks.emplace_back(mb);
			nextBlockIndex += blockSize;
			isFile = !isFile;
		}

		// Try moving each file to the left once:
		// -> files are at every even index within the memory blocks:
		int lastFileIndex = (int)(memoryBlocks.size() % 2 == 0 ? memoryBlocks.size() - 2 : memoryBlocks.size() - 1);
		for (int fileIx = lastFileIndex; fileIx >= 0; fileIx -= 2)
		{
			int fileID = fileIx / 2;
			int fileSize = memoryBlocks[fileIx].GetDataSize();

			// Find a memory block to the left that has free space large enough for this file:
			// -> only every second block can possibly contain free space
			for (int freeIx = 1; freeIx < fileIx; freeIx += 2)
			{
				if (memoryBlocks[freeIx].AddFile(fileID, fileSize))
				{
					memoryBlocks[fileIx].Clear();
					break;
				}
			}
		}

		// Filesystem checksum:
		uint64_t filesystemChecksum = 0;
		for (const auto& mb : memoryBlocks)
			filesystemChecksum += mb.GetChecksum();

		return filesystemChecksum;
	}
}
