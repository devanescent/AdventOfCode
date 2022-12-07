#include "FilesystemProcessor.h"

namespace AdventOfCode::Year2022::Day07
{
	std::vector<Directory> FilesystemProcessor::Process(std::vector<std::string> input)
	{
		Directory root("/", nullptr);
		Directory* currentDir = &root;

		for (const std::string& line : input)
		{
			// cd command
			if (line.rfind("$ cd", 0) == 0)
			{
				std::string dirName = line.substr(line.rfind(' ') + 1);
				
				if (dirName == "..")
				{
					currentDir = currentDir->GetParent();
				}
				else if (dirName != "/") // all dirs but root (is already handled manually)
				{
					currentDir = currentDir->GetChildDir(dirName);
				}
			}
			// ls command
			else if (line == "$ ls")
			{
				continue;
			}
			// results of ls command: directory
			else if (line.rfind("dir", 0) == 0)
			{
				std::string dirName = line.substr(line.rfind(' ') + 1);
				currentDir->AddDirectory(Directory(dirName, currentDir));
			}
			// results of ls command: file
			else
			{
				int size = std::stoi(line);
				std::string fileName = line.substr(line.rfind(' ') + 1);
				currentDir->AddFile(File(fileName, size));
			}
		}

		std::vector<Directory> dirs;
		dirs.emplace_back(std::move(root));
		return dirs;
	}
}
