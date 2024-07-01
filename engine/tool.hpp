#pragma once
#include <fstream>
#include <vector>
#include <iostream>

namespace engine {

    std::vector<char> ReadWholeFile(const std::string& filename);

}