#include "file_util.hpp"
#include "macro.hpp"

namespace PrimalDawn {
	String FileUtil::read_file(const String& filename) {
		std::ifstream ifs(filename);
		if (!ifs.is_open()) {
			LOG_ERROR("读取文件失败!" + filename);
			throw std::runtime_error("读取文件失败! " + filename);
		}
		std::stringstream buffer;
		buffer << ifs.rdbuf();
		return buffer.str();
	}
}