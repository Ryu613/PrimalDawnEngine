#pragma once

#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <memory_resource>

namespace utils {

	// allocate aligned memory
	// ensure memory is aligned in different platform
	inline void* aligned_alloc(size_t size, size_t align) noexcept {
		// for compatibility, align must larger than pointer's size
		align = (align < sizeof(void*)) ? sizeof(void*) : align;
		// align > 0 and must be power of 2
		assert(align && !(align & align - 1));
		// compatibility for POSIX
		assert((align % sizeof(void*)) == 0);
		void* p = nullptr;
		// some platform or SDK not support std::aligned_alloc, so call os-specific malloc instead
		// ref: https://developercommunity.visualstudio.com/t/c17-stdaligned-alloc%E7%BC%BA%E5%A4%B1/468021
#if defined(_WIN32)
		p = ::_aligned_malloc(size, align);
#else
		(void)::posix_memalign(&p, align, size);
#endif
		return p;
	}

	inline void aligned_free(void* p) noexcept {
#if defined(_WIN32)
		::_aligned_free(p);
#else
		::free(p);
#endif
	}


namespace AllocatorPolicy {
	/**
	* heap allocator
	*/
	class HeapAllocator {
	public:
		HeapAllocator() noexcept = default;
		~HeapAllocator() noexcept = default;

		template <typename AreaPolicy>
		explicit HeapAllocator(const AreaPolicy&&) {}

		void* alloc(size_t size, size_t alignment = alignof(std::max_align_t)) {
			return aligned_alloc(alignment, size);
		}

		void free(void* p) noexcept {
			aligned_free(p);
		}
	};
} // namespace AllocatorPolicy

namespace TrackingPolicy {
	struct Untracked {

	};
} // namespace TrackingPolicy

namespace AreaPolicy {
	class HeapResource : public std::pmr::memory_resource {
	public:
		HeapResource() noexcept = default;
		explicit HeapResource(size_t size) {
			if (size) {
				//begin_ = 
			}
		}
	private:
		void* begin_ = nullptr;
		void* end_ = nullptr;
	};
}

namespace LockingPolicy {
	struct NoLock {};
}

	/**
	* arena is a contiguous piece of memory, not only heap region
	* it only need allocate once, then manually using it by handing out part of that memory
	* when memory allocation performance is something vital, you can use this allocator
	* 
	* AreaPolicy: Heap/Stack/...
	* AllocatorPolicy: HeapAllocator/LinearAllocator/...
	* LockingPolicy: NoLock/Locking
	* TrackingPolicy: NoTrack/...
	*/
	template<
		typename AreaPolicy,
		typename AllocatorPolicy,
		typename LockingPolicy,
		typename TrackingPolicy,
	>
	class Arena {
	public:
		Arena() = default;

		template<typename ... ARGS>
		Arena(const char* name, size_t size, ARGS&& ... args)
			: name_(name),
			  area_(size),
			  allocator_(area_, std::forward<ARGS>(args)...) {
		}

		void* alloc(size_t size, size_t alignment = alignof(std::max_align_t)) noexcept {
			allocator_.alloc(size, alignment);
		}
	private:
		const char* name_ = nullptr;
		AreaPolicy area_;
		AllocatorPolicy allocator_;
		LockingPolicy lock_;
		TrackingPolicy listener_;

	};

	using HeapArena = Arena<
		AreaPolicy::HeapArea,
		AllocatorPolicy::HeapAllocator,
		LockingPolicy::NoLock,
		TrackingPolicy::Untracked>;
}
