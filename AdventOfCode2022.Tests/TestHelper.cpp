#include "stdafx.h"
#include "TestHelper.h"
#include <locale>
#include <codecvt>

namespace Microsoft::VisualStudio::CppUnitTestFramework
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

	std::string to_string(std::wstring wstr)
	{
		return converter.to_bytes(wstr);
	}

	std::wstring to_wstring(std::string str)
	{
		return converter.from_bytes(str);
	}
}