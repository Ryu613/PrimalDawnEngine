#pragma once
#include <vector>
#include <string>
#include <filesystem>

namespace pd {
	namespace util {
		static std::vector<char> readFile(const std::string& filepath, bool isBinary);
	}
}
