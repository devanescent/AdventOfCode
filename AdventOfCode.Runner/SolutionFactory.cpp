#include "SolutionFactory.h"
#include "Solutions2017.h"
#include "Solutions2018.h"
#include "Solutions2020.h"
#include "Solutions2021.h"
#include "Solutions2022.h"
#include "Solutions2023.h"

namespace AdventOfCode
{
	std::unique_ptr<Solutions> AdventOfCode::SolutionFactory::GetYear(int year)
	{
		switch (year)
		{
			case 2017:	return std::make_unique<Year2017::Solutions2017>();
			case 2018:	return std::make_unique<Year2018::Solutions2018>();
			case 2020:	return std::make_unique<Year2020::Solutions2020>();
			case 2021:	return std::make_unique<Year2021::Solutions2021>();
			case 2022:	return std::make_unique<Year2022::Solutions2022>();
			case 2023:	return std::make_unique<Year2023::Solutions2023>();
			default:	return nullptr;
		}
	}
}
