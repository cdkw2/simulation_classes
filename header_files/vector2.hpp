#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <cmath>

class Vector2 {
public:
    float x, y;

    Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2& operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    float dot(const Vector2& other) const {
        return (x * other.x + y * other.y);
    }

    float cross(const Vector2& other) const {
        return (x * other.y - y * other.x);
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2 normalized() const {
        float mag = magnitude();
        if (mag > 0.0f) {
            return Vector2(x / mag, y / mag);
        }
        return Vector2(0.0f, 0.0f);
    }
};

#endif