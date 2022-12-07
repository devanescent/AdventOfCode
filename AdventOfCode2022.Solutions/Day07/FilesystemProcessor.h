#pragma once
#include "InputProcessor.h"
#include "FileSystem.h"

namespace AdventOfCode::Year2022::Day07
{
	class FilesystemProcessor : public InputProcessorBase<Directory>
	{
	public:
		std::vector<Directory> Process(std::vector<std::string> input) override;
	};
}
