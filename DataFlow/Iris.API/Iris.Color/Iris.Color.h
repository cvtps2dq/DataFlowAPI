#pragma once
#ifndef IRIS_COLOR_H
#define IRIS_COLOR_H

#include <algorithm>

namespace Iris {
    class Color {
        int _red;
        int _green;
        int _blue;
        int _alpha;

    public:
        // Default constructor
        Color() : _red(0), _green(0), _blue(0), _alpha(255) {}

        // Template constructors
        template <typename T>
        Color(T r, T g, T b, T a = 1.0) {
            _red = std::clamp(static_cast<int>(r * 255), 0, 255);
            _green = std::clamp(static_cast<int>(g * 255), 0, 255);
            _blue = std::clamp(static_cast<int>(b * 255), 0, 255);
            _alpha = std::clamp(static_cast<int>(a * 255), 0, 255);
        }

        // Copy constructor
        Color(const Color &other) = default;
        Color &operator=(const Color &other) = default;

        // Arithmetic operators
        Color operator+(const Color &other) const;
        Color operator-(const Color &other) const;
        Color &operator+=(const Color &other);
        Color &operator-=(const Color &other);
        Color operator*(double scale) const;
        Color &operator*=(double scale);
        Color operator/(double scale) const;
        Color &operator/=(double scale);

        [[nodiscard]] std::array<double, 3> normalize() const;

        Color *Interpolate(Color &other, double ratio);

        template <typename T = int>
        [[nodiscard]] T red() const { return static_cast<T>(_red); }

        template <typename T = int>
        [[nodiscard]] T green() const { return static_cast<T>(_green); }

        template <typename T = int>
        [[nodiscard]] T blue() const { return static_cast<T>(_blue); }

        template <typename T = int>
        [[nodiscard]] T alpha() const { return static_cast<T>(_alpha); }

        // Setters
        template <typename T>
        void set_red(T r) { _red = std::clamp(static_cast<int>(r), 0, 255); }

        template <typename T>
        void set_green(T g) { _green = std::clamp(static_cast<int>(g), 0, 255); }

        template <typename T>
        void set_blue(T b) { _blue = std::clamp(static_cast<int>(b), 0, 255); }

        template <typename T>
        void set_alpha(T a) { _alpha = std::clamp(static_cast<int>(a), 0, 255); }

        [[nodiscard]] std::string toString() const;
    };
}

#endif // IRIS_COLOR_H