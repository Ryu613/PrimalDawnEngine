#include <memory_resource>

#include "utils/pimpl.hpp"

namespace utils {
	enum class AllocatorType {
		LINEAR = 1,
		FREELIST = 2,
	};
	enum class AreaType {
		HEAP = 1,
	};

	enum class TracingType {
		NO_TRACE = 0,
	};

	enum class LockingType {
		NO_LOCK = 0,
	};

	class HeapResource : public std::pmr::memory_resource {

	};

	class StackResource : public std::pmr::memory_resource {

	};

	template <typename T>
	class PmrAllocator : public std::pmr::polymorphic_allocator {
		struct PmrAllocatorDetails;
	public:
		class Builder : public Pimpl<PmrAllocatorDetails> {
			friend class PmrAllocator;
		public:
			Builder& allocatorType(const AllocatorType alloc_type) noexcept;
			Builder& areaType(const AreaType area_type) noexcept;
			Builder& tracingType(const TracingType tracing) noexcept;
			Builder& lockingType(const LockingType locking) noexcept;
			PmrAllocator* Build() const;
		};
	};
}
