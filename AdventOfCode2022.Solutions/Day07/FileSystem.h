#pragma once
#include <map>
#include <numeric>
#include <string>
#include <vector>

namespace AdventOfCode::Year2022::Day07
{
	class File
	{
	public:
		File(std::string name, int size) :
			m_fileName(name), m_fileSize(size)
		{ }

		const std::string& GetName() const { return m_fileName; }
		uint64_t GetSize() const { return m_fileSize; }

	private:
		std::string m_fileName;
		int m_fileSize;
	};

	class Directory
	{
	public:
		Directory(std::string name, Directory* parentDir) : 
			m_dirName(name), m_parent(parentDir) {}


		const std::string& GetName() const { return m_dirName; }
		uint64_t GetSize() const
		{
			uint64_t totalFileSize = std::accumulate(m_files.begin(), m_files.end(), 0ull,
				[](uint64_t totalSize, const auto& fileEntry)
				{ return totalSize + fileEntry.second.GetSize(); }
			);

			uint64_t totalChildDirSize = std::accumulate(m_childDirs.begin(), m_childDirs.end(), 0ull,
				[](uint64_t totalSize, const auto& dirEntry)
				{ return totalSize + dirEntry.second.GetSize(); }
			);

			return totalFileSize + totalChildDirSize;
		}

		void AddFile(File file)
		{
			m_files.emplace(file.GetName(), std::move(file));
		}

		void AddDirectory(Directory dir)
		{
			m_childDirs.emplace(dir.GetName(), std::move(dir));
		}

		Directory* GetChildDir(const std::string& name)
		{
			return &(m_childDirs.at(name));
		}

		Directory* GetParent() const { return m_parent; }

		// Returns a list of this dir with all its child dirs (recursive)
		std::vector<Directory*> GetAllDirs()
		{
			std::vector<Directory*> dirs;
			GetDirsRecursive(dirs);
			return dirs;
		}

	private:
		std::string m_dirName;
		Directory* m_parent;

		std::map<std::string, Directory> m_childDirs;
		std::map<std::string, File> m_files;

		void GetDirsRecursive(std::vector<Directory*>& out_dirs)
		{
			out_dirs.push_back(this);
			for (auto& childDir : m_childDirs)
				childDir.second.GetDirsRecursive(out_dirs);
		}
	};
}
