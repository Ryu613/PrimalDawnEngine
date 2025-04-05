#pragma once

/**
* 这些函数用于把某类的指针/引用安全地转为Pd开头的指针/引用
* 
* 主要用于对外接口类和私有类的公私分离
* 例如: engine* 转为Pdengine* 
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
