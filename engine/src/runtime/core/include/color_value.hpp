#pragma once

namespace PrimalDawn {
    class ColorValue {
    public:
        float r, g, b, a;
    public:
        explicit ColorValue(float red = 1.0f,
            float green = 1.0f,
            float blue = 1.0f,
            float alpha = 1.0f) : r(red), g(green), b(blue), a(alpha)
        { }
    };
}