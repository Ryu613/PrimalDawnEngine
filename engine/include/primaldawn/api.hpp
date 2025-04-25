#pragma once

namespace primaldawn {
	/**
	* @brief protect interface classes cannot be created, destroyed or copied by the caller
	*/
	class Api {
	protected:
		Api() noexcept = default;
		~Api() = default;
	public:
		Api(const Api&) = delete;
		Api(Api&&) noexcept = delete;
		Api& operator=(const Api&) = delete;
		Api& operator=(Api&&) noexcept = delete;

		// cannot allocate on heap
		static void* operator new(size_t) = delete;
		static void* operator new[](size_t) = delete;
	};
} // namespace primaldawn
