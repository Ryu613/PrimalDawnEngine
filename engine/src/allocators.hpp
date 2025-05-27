#include "ze/allocator/allocator.hpp"

namespace primaldawn {

	// only need allocate on heap and aligned
	using HeapAllocator = ze::Arena<
		ze::ResourcePolicy::NullResource,
		ze::AllocatorPolicy::RawHeapAllocator,
		ze::LockingPolicy::NoLock,
		ze::TrackingPolicy::NoTracking
	>;
} // namespace primaldawn
