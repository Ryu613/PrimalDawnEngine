#pragma once

#include "GLCommon.hpp"

namespace pd {
	class GLShader {
	public:

		unsigned int ID;
		GLShader() = default;
		GLShader(const char* vertexPath, const char* fragmentPath);

		void use();
		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, bool value) const;
		void setFloat(const std::string& name, bool value) const;
		void setMat4(const std::string& name, const glm::mat4& mat4) const;
	};
}
