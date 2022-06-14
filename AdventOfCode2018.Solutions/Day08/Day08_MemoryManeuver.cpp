#include "Day08_MemoryManeuver.h"
#include <memory>
#include <numeric>

namespace AdventOfCode::Year2018::Day08
{
	class Node
	{
	public:
		void AddChild(std::unique_ptr<Node> child) { m_children.emplace_back(std::move(child)); }

		void SetMetadata(std::vector<int>::iterator metaBegin, std::vector<int>::iterator metaEnd) 
		{ m_metadata = std::vector<int>(metaBegin, metaEnd); }

		int GetMetaSum() const { return std::accumulate(m_metadata.begin(), m_metadata.end(), 0); }

		template <typename TFunc, typename TAggregate>
		TAggregate AggregateNodes(TFunc func, TAggregate initValue) const
		{
			TAggregate value = func(initValue, *this);
			for (const auto& childNode : m_children)
				value = childNode->AggregateNodes(func, value);

			return value;
		}

	private:
		std::vector<std::unique_ptr<Node>> m_children;
		std::vector<int> m_metadata;
	};


	std::unique_ptr<Node> ProcessNode(std::vector<int>::iterator& data)
	{
		// Read header:
		int numChildren = *(data++);
		int lenMetadata = *(data++);

		auto node = std::make_unique<Node>();

		// Process children:
		for (int i = 0; i < numChildren; ++i)
			node->AddChild(ProcessNode(data));

		// Read metadata:
		node->SetMetadata(data, data + lenMetadata);
		data += lenMetadata;

		return node;
	}

	MemoryManeuver::MemoryManeuver() : DayT(8, "Memory Maneuver")
	{}

	uint64_t MemoryManeuver::ExecutePart1(std::vector<int> rootNodeData)
	{
		auto data = rootNodeData.begin();
		auto rootNode = ProcessNode(data);

		// Sum metadata:
		return rootNode->AggregateNodes([](uint64_t value, const Node& node)
			{ return value + node.GetMetaSum(); }, 0ull);
	}
}
