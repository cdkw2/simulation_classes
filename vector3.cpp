#include <cmath>

class Vector3{
public:
    float x, y, z;

    Vector3(float x = 0.0, float y = 0.0, float z = 0.0) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    Vector3 dot(const Vector3& other) const {
        return (x * other.x + y * other.y + z * other.z);
    }

    Vector3 cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3 normalized() const {
        float mag = magnitude();

        if (mag > 0.0f) {
            return Vector3(x / mag, y / mag, z/ mag);
        }

        return Vector3(0.0f, 0.0f, 0.0f);
    }
};