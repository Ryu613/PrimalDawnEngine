#include "utils/allocator.hpp"

namespace primaldawn {

	// only need allocate on heap and aligned
	using HeapAllocator = utils::Arena<
		utils::ResourcePolicy::NullResource,
		utils::AllocatorPolicy::HeapAllocator,
		utils::LockingPolicy::NoLock,
		utils::TrackingPolicy::Untracked
	>;
} // namespace primaldawn
