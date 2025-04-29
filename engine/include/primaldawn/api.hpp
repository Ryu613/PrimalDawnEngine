#pragma once

namespace primaldawn {
	/**
	* @brief protect interface classes cannot be created, destroyed, copied and moved by the caller
	* classes which derive from Api cannot construct on heap or stack(except private classes)
	*/
	class Api {
	protected:
		// cannot allocate on stack
		Api() noexcept = default;
		~Api() = default;
	public:
		Api(const Api&) = delete;
		Api(Api&&) noexcept = delete;
		Api& operator=(const Api&) = delete;
		Api& operator=(Api&&) noexcept = delete;

		// cannot allocate on heap directly, but placement new is allowed
		static void* operator new(size_t) = delete;
		static void* operator new[](size_t) = delete;
	};
} // namespace primaldawn
