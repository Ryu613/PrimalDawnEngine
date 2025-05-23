#pragma once

/**
* same function comparing with pimpl, but pure interface classes are more cleaner.
* no members and impl pointer needed, but impl classes must inheritant from base classes
* ensure ABI(backward compatibility) without pimpl
*/
#define DOWNCAST(CLASS)                                    \
    inline Pd##CLASS& downcast(CLASS& that) noexcept {               \
        return static_cast<Pd##CLASS &>(that);                       \
    }                                                               \
    inline const Pd##CLASS& downcast(const CLASS& that) noexcept {   \
        return static_cast<const Pd##CLASS &>(that);                 \
    }                                                               \
    inline Pd##CLASS* downcast(CLASS* that) noexcept {               \
        return static_cast<Pd##CLASS *>(that);                       \
    }                                                               \
    inline Pd##CLASS const* downcast(CLASS const* that) noexcept {   \
        return static_cast<Pd##CLASS const *>(that);                 \
    }
