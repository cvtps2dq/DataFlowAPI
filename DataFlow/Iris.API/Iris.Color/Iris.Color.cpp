#include "Iris.Color.h"

#include <__algorithm/clamp.h>

namespace Iris {

    // Arithmetic operations

    Color Color::operator+(const Color &other) const {
        return {
            std::clamp(this->_red + other._red, 0, 255),
            std::clamp(this->_green + other._green, 0, 255),
            std::clamp(this->_blue + other._blue, 0, 255),
            std::clamp(this->_alpha + other._alpha, 0, 255)
        };
    }

    Color Color::operator-(const Color &other) const {
        return {
            std::clamp(this->_red - other._red, 0, 255),
            std::clamp(this->_green - other._green, 0, 255),
            std::clamp(this->_blue - other._blue, 0, 255),
            std::clamp(this->_alpha - other._alpha, 0, 255)
        };
    }

    Color &Color::operator+=(const Color &other) {
        *this = *this + other;
        return *this;
    }

    Color &Color::operator-=(const Color &other) {
        *this = *this - other;
        return *this;
    }

    Color Color::operator*(const double scale) const {
        return {
            std::clamp(static_cast<int>(this->_red * scale), 0, 255),
            std::clamp(static_cast<int>(this->_green * scale), 0, 255),
            std::clamp(static_cast<int>(this->_blue * scale), 0, 255),
            std::clamp(static_cast<int>(this->_alpha * scale), 0, 255)
        };
    }

    Color &Color::operator*=(const double scale) {
        *this = *this * scale;
        return *this;
    }

    Color Color::operator/(const double scale) const {
        return {
            std::clamp(static_cast<int>(this->_red / scale), 0, 255),
            std::clamp(static_cast<int>(this->_green / scale), 0, 255),
            std::clamp(static_cast<int>(this->_blue / scale), 0, 255),
            std::clamp(static_cast<int>(this->_alpha / scale), 0, 255)
        };
    }

    Color &Color::operator/=(const double scale) {
        *this = *this / scale;
        return *this;
    }
}
