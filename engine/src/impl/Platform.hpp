#pragma once

#include <memory>

#include "primaldawn/config.hpp"
#include "primaldawn/enums.hpp"

#include "downcast.hpp"

namespace primaldawn {
	class PdWindowSystem;

	class PdPlatform {
	public:
		const PdWindowSystem& GetWindowSystem() const;
		explicit PdPlatform(const config::Platform& config);
		virtual ~PdPlatform();
		const OS GetOS() const;
	private:
		config::Platform config_;
		std::unique_ptr<PdWindowSystem> window_system_{nullptr};
	public:
		PdPlatform(const PdPlatform&) = delete;
		PdPlatform(PdPlatform&&) noexcept = delete;
		PdPlatform& operator=(const PdPlatform&) = delete;
		PdPlatform& operator=(PdPlatform&&) noexcept = delete;
	};

	// DOWNCAST(Platform);
} // namespace primaldawn
