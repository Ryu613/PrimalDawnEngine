#pragma once

#include "prequisites.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace PrimalDawn {
	class FileUtil {
	public:
		static String read_file(const String& filename);

	};
}