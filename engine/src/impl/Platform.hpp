#pragma once

#include <memory>

#include "primaldawn/platform.hpp"
#include "primaldawn/config.hpp"

#include "downcast.hpp"

namespace primaldawn {
	class PdWindowSystem;

	class PdPlatform {
	public:
		PdWindowSystem* GetWindowSystem() const;
		explicit PdPlatform(config::Platform config);
		virtual ~PdPlatform();
	private:
		config::Platform config_;
		std::unique_ptr<PdWindowSystem> window_system_{nullptr};
	};

	// DOWNCAST(Platform);
} // namespace primaldawn
