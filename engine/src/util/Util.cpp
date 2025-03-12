#include "util/Util.hpp"

#include <fstream>

namespace pd {
    namespace util {
        std::vector<char> readFile(const std::string& filepath, bool isBinary) {
            std::ifstream file(filepath);
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
