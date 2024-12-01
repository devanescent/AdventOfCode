#pragma once
#include "stdafx.h"
#include <string>

namespace Microsoft::VisualStudio::CppUnitTestFramework 
{
	std::string to_string(std::wstring wstr);
	std::wstring to_wstring(std::string str);
}