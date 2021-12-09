#include "Solutions2020.h"

namespace AdventOfCode::Year2020
{
	// Instanciate all days with parameters according to the given task:
	Solutions::Solutions()
	{
		m_days.reserve(25);
		m_days.emplace_back(std::make_unique<Day01::ReportRepair>(2020));
		m_days.emplace_back(std::make_unique<Day02::PasswordPhilosophy>());
		m_days.emplace_back(std::make_unique<Day03::TobogganTrajectory>(3, 1));
		m_days.emplace_back(std::make_unique<Day04::PassportProcessing>());
		m_days.emplace_back(std::make_unique<Day05::BinaryBoarding>(128, 8));
		m_days.emplace_back(std::make_unique<Day06::CustomCustoms>());
		m_days.emplace_back(std::make_unique<Day07::HandyHaversacks>("shiny gold"));
		m_days.emplace_back(std::make_unique<Day08::HandheldHalting>());
		m_days.emplace_back(std::make_unique<Day09::EncodingError>(25));
		m_days.emplace_back(std::make_unique<Day10::AdapterArray>());
		m_days.emplace_back(std::make_unique<Day11::SeatingSystem>());
		m_days.emplace_back(std::make_unique<Day12::RainRisk>(Day12::NavDirection::E));
		m_days.emplace_back(std::make_unique<Day13::ShuttleSearch>());
		m_days.emplace_back(std::make_unique<Day14::DockingData>());
		m_days.emplace_back(std::make_unique<Day15::RambunctiousRecitation>(2020));
		m_days.emplace_back(std::make_unique<Day16::TicketTranslation>());
		m_days.emplace_back(std::make_unique<Day17::ConvayCubes>(6));
		m_days.emplace_back(std::make_unique<Day18::OperationOrder>());
		// Day19
		m_days.emplace_back(std::make_unique<Day20::JurassicJigsaw>());
		// Day21
		m_days.emplace_back(std::make_unique<Day22::CrabCombat>());
		m_days.emplace_back(std::make_unique<Day23::CrabCups>(100));
		m_days.emplace_back(std::make_unique<Day24::LobbyLayout>());
		m_days.emplace_back(std::make_unique<Day25::ComboBreaker>());
	}
}