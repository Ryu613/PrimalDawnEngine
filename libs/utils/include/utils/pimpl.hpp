#pragma once

namespace utils {
	template<typename T>
	class Pimpl {
	public:
		template<typename ... ARGS>
		explicit Pimpl(ARGS&& ... args) noexcept : impl_(new T(std::forward<ARGS>(args)...)){}
		Pimpl() noexcept : impl_(new T) {}
		~Pimpl() noexcept { delete impl_; }
		Pimpl(const Pimpl& rhs) noexcept : impl_(new T(*rhs.impl_)) {}
		Pimpl& operator=(const Pimpl& rhs) noexcept {
			if (this != &rhs) {
				*impl_ = *rhs.impl_;
			}
			return *this;
		}
		Pimpl(Pimpl&& rhs) noexcept : impl_(rhs.impl_) { rhs.impl_ = nullptr; }
		Pimpl& operator=(Pimpl&& rhs) noexcept {
			std::exchange(rhs.impl_, nullptr);
		}
	protected:
		T* impl_ = nullptr;
	};
}
