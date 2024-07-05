#pragma once
#include <fstream>
#include <vector>
#include <iostream>

namespace PrimalDawnEngine {

    std::vector<char> ReadWholeFile(const std::string& filename);

}