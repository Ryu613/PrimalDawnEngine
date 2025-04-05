#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

namespace pd {
	namespace util {
		static std::vector<char> readFile(const std::string& filepath, bool isBinary = false) {
            std::ios_base::openmode mode = std::ios::ate;
            if (isBinary) {
                mode |= std::ios::binary;
            }
            std::ifstream file(filepath, mode);
            if (!file.is_open()) {
                throw std::runtime_error("failed to open file");
            }
            size_t fileSize = (size_t)file.tellg();
            if (!isBinary) {
                fileSize += 1;
            }
            std::vector<char> buffer(fileSize);
            file.seekg(0);
            file.read(reinterpret_cast<char*>(buffer.data()), fileSize);
            file.close();
            if (!isBinary) {
                buffer[buffer.size() - 1] = '\0';
            }
            return buffer;
		}
	}
}
