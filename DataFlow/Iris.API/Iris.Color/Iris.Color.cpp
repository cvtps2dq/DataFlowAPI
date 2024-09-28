#include "Iris.Color.h"

#include <array>
#include <string>
#include <__algorithm/clamp.h>

namespace Iris {

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

    std::array<double, 3> Color::normalize() const {
        std::array<double, 3> array = {};
        array[0] = static_cast<double>(this->red()) / 255;
        array[1] = static_cast<double>(this->green()) / 255;
        array[2] = static_cast<double>(this->blue()) / 255;
        return array;
    }

    Color *Color::Interpolate(Color &other, const double ratio)
    {
        const std::array<double, 3> input = other.normalize();
        const std::array<double, 3> curColor = normalize();

        if (ratio <= 0.0)
        {
            return this;
        }
        if (ratio >= 1.0)
        {
            return &other;
        }
        return new Color(
            curColor[0] + (input[0] - curColor[0]) * ratio,
            curColor[1] + (input[1] - curColor[1]) * ratio,
            curColor[2] + (input[2] - curColor[2]) * ratio
        );
    }

    std::string Color::toString() const {
        return "red: " + std::to_string(this->_red) + ";"
        + " green: " + std::to_string(this->_green) + ";"
        + " blue: " + std::to_string(this->_blue) + ";"
        + " alpha: " + std::to_string(this->_alpha);

    }
}
