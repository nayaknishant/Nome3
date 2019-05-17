//
// Copyright (c) 2008-2018 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "Vector2.h"
#include "MathDefs.h"

namespace tc
{

/// Three-dimensional vector with integer values.
class MATH_EXPORT IntVector3
{
public:
    /// Construct a zero vector.
    IntVector3() noexcept :
        x(0),
        y(0),
        z(0)
    {
    }

    /// Construct from coordinates.
    IntVector3(int x, int y, int z) noexcept :
        x(x),
        y(y),
        z(z)
    {
    }

    /// Construct from an int array.
    explicit IntVector3(const int* data) noexcept :
        x(data[0]),
        y(data[1]),
        z(data[2])
    {
    }

    /// Copy-construct from another vector.
    IntVector3(const IntVector3& rhs) noexcept = default;

    /// Assign from another vector.
    IntVector3& operator =(const IntVector3& rhs) noexcept = default;

    /// Test for equality with another vector.
    bool operator ==(const IntVector3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }

    /// Test for inequality with another vector.
    bool operator !=(const IntVector3& rhs) const { return x != rhs.x || y != rhs.y || z != rhs.z; }

    /// Add a vector.
    IntVector3 operator +(const IntVector3& rhs) const { return IntVector3(x + rhs.x, y + rhs.y, z + rhs.z); }

    /// Return negation.
    IntVector3 operator -() const { return IntVector3(-x, -y, -z); }

    /// Subtract a vector.
    IntVector3 operator -(const IntVector3& rhs) const { return IntVector3(x - rhs.x, y - rhs.y, z - rhs.z); }

    /// Multiply with a scalar.
    IntVector3 operator *(int rhs) const { return IntVector3(x * rhs, y * rhs, z * rhs); }

    /// Multiply with a vector.
    IntVector3 operator *(const IntVector3& rhs) const { return IntVector3(x * rhs.x, y * rhs.y, z * rhs.z); }

    /// Divide by a scalar.
    IntVector3 operator /(int rhs) const { return IntVector3(x / rhs, y / rhs, z / rhs); }

    /// Divide by a vector.
    IntVector3 operator /(const IntVector3& rhs) const { return IntVector3(x / rhs.x, y / rhs.y, z / rhs.z); }

    /// Add-assign a vector.
    IntVector3& operator +=(const IntVector3& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    /// Subtract-assign a vector.
    IntVector3& operator -=(const IntVector3& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    /// Multiply-assign a scalar.
    IntVector3& operator *=(int rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }

    /// Multiply-assign a vector.
    IntVector3& operator *=(const IntVector3& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }

    /// Divide-assign a scalar.
    IntVector3& operator /=(int rhs)
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }

    /// Divide-assign a vector.
    IntVector3& operator /=(const IntVector3& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        return *this;
    }

    /// Return integer data.
    const int* Data() const { return &x; }

    /// Return as string.
    std::string ToString() const;

    /// Return hash value for HashSet & HashMap.
    unsigned ToHash() const { return (unsigned)x * 31 * 31 + (unsigned)y * 31 + (unsigned)z; }

    /// Return length.
    float Length() const { return sqrtf((float)(x * x + y * y + z * z)); }

    /// X coordinate.
    int x;
    /// Y coordinate.
    int y;
    /// Z coordinate.
    int z;

    /// Zero vector.
    static const IntVector3 ZERO;
    /// (-1,0,0) vector.
    static const IntVector3 LEFT;
    /// (1,0,0) vector.
    static const IntVector3 RIGHT;
    /// (0,1,0) vector.
    static const IntVector3 UP;
    /// (0,-1,0) vector.
    static const IntVector3 DOWN;
    /// (0,0,-1) vector.
    static const IntVector3 FORWARD;
    /// (0,0,1) vector.
    static const IntVector3 BACK;
    /// (1,1,1) vector.
    static const IntVector3 ONE;
};

/// Three-dimensional vector.
class MATH_EXPORT Vector3
{
public:
    /// Construct a zero vector.
    Vector3() noexcept :
        x(0.0f),
        y(0.0f),
        z(0.0f)
    {
    }

    /// Copy-construct from another vector.
    Vector3(const Vector3& vector) noexcept = default;

    /// Construct from a two-dimensional vector and the Z coordinate.
    Vector3(const Vector2& vector, float z) noexcept :
        x(vector.x),
        y(vector.y),
        z(z)
    {
    }

    /// Construct from a two-dimensional vector (for Urho2D).
    explicit Vector3(const Vector2& vector) noexcept :
        x(vector.x),
        y(vector.y),
        z(0.0f)
    {
    }

    /// Construct from an IntVector3.
    explicit Vector3(const IntVector3& vector) noexcept :
        x((float)vector.x),
        y((float)vector.y),
        z((float)vector.z)
    {
    }

    /// Construct from coordinates.
    Vector3(float x, float y, float z) noexcept :
        x(x),
        y(y),
        z(z)
    {
    }

    /// Construct from two-dimensional coordinates (for Urho2D).
    Vector3(float x, float y) noexcept :
        x(x),
        y(y),
        z(0.0f)
    {
    }

    /// Construct from a float array.
    explicit Vector3(const float* data) noexcept :
        x(data[0]),
        y(data[1]),
        z(data[2])
    {
    }

    /// Assign from another vector.
    Vector3& operator =(const Vector3& rhs) noexcept = default;

    /// Test for equality with another vector without epsilon.
    bool operator ==(const Vector3& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }

    /// Test for inequality with another vector without epsilon.
    bool operator !=(const Vector3& rhs) const { return x != rhs.x || y != rhs.y || z != rhs.z; }

    /// Test for less than.
    bool operator <(const Vector3& rhs) const { return x < rhs.x && y < rhs.y && z < rhs.z; }

    /// Test for less than or equal to.
    bool operator <=(const Vector3& rhs) const { return x <= rhs.x && y <= rhs.y && z <= rhs.z; }

    /// Test for greater than.
    bool operator >(const Vector3& rhs) const { return x > rhs.x && y > rhs.y && z > rhs.z; }

    /// Test for greater than or equal to.
    bool operator >=(const Vector3& rhs) const { return x >= rhs.x && y >= rhs.y && z >= rhs.z; }

    /// Add a vector.
    Vector3 operator +(const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }

    /// Return negation.
    Vector3 operator -() const { return Vector3(-x, -y, -z); }

    /// Subtract a vector.
    Vector3 operator -(const Vector3& rhs) const { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }

    /// Multiply with a scalar.
    Vector3 operator *(float rhs) const { return Vector3(x * rhs, y * rhs, z * rhs); }

    /// Multiply with a vector.
    Vector3 operator *(const Vector3& rhs) const { return Vector3(x * rhs.x, y * rhs.y, z * rhs.z); }

    /// Divide by a scalar.
    Vector3 operator /(float rhs) const { return Vector3(x / rhs, y / rhs, z / rhs); }

    /// Divide by a vector.
    Vector3 operator /(const Vector3& rhs) const { return Vector3(x / rhs.x, y / rhs.y, z / rhs.z); }

    /// Add-assign a vector.
    Vector3& operator +=(const Vector3& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    /// Subtract-assign a vector.
    Vector3& operator -=(const Vector3& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    /// Multiply-assign a scalar.
    Vector3& operator *=(float rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }

    /// Multiply-assign a vector.
    Vector3& operator *=(const Vector3& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }

    /// Divide-assign a scalar.
    Vector3& operator /=(float rhs)
    {
        float invRhs = 1.0f / rhs;
        x *= invRhs;
        y *= invRhs;
        z *= invRhs;
        return *this;
    }

    /// Divide-assign a vector.
    Vector3& operator /=(const Vector3& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        return *this;
    }

    /// Normalize to unit length.
    void Normalize()
    {
        float lenSquared = LengthSquared();
        if (!tc::Equals(lenSquared, 1.0f) && lenSquared > 0.0f)
        {
            float invLen = 1.0f / sqrtf(lenSquared);
            x *= invLen;
            y *= invLen;
            z *= invLen;
        }
    }

    /// Return length.
    float Length() const { return sqrtf(x * x + y * y + z * z); }

    /// Return squared length.
    float LengthSquared() const { return x * x + y * y + z * z; }

    /// Calculate dot product.
    float DotProduct(const Vector3& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }

    /// Calculate absolute dot product.
    float AbsDotProduct(const Vector3& rhs) const
    {
        return tc::Abs(x * rhs.x) + tc::Abs(y * rhs.y) + tc::Abs(z * rhs.z);
    }

    /// Project direction vector onto axis.
    float ProjectOntoAxis(const Vector3& axis) const { return DotProduct(axis.Normalized()); }

    /// Project position vector onto plane with given origin and normal.
    Vector3 ProjectOntoPlane(const Vector3& origin, const Vector3& normal) const
    {
        const Vector3 delta = *this - origin;
        return *this - normal.Normalized() * delta.ProjectOntoAxis(normal);
    }

    /// Project position vector onto line segment.
    Vector3 ProjectOntoLine(const Vector3& from, const Vector3& to, bool clamped = false) const
    {
        const Vector3 direction = to - from;
        const float lengthSquared = direction.LengthSquared();
        float factor = (*this - from).DotProduct(direction) / lengthSquared;

        if (clamped)
            factor = Clamp(factor, 0.0f, 1.0f);

        return from + direction * factor;
    }

    /// Calculate distance to another position vector.
    float DistanceToPoint(const Vector3& point) const { return (*this - point).Length(); }

    /// Calculate distance to the plane with given origin and normal.
    float DistanceToPlane(const Vector3& origin, const Vector3& normal) const { return (*this - origin).ProjectOntoAxis(normal); }

    /// Make vector orthogonal to the axis.
    Vector3 Orthogonalize(const Vector3& axis) const { return axis.CrossProduct(*this).CrossProduct(axis).Normalized(); }

    /// Calculate cross product.
    Vector3 CrossProduct(const Vector3& rhs) const
    {
        return Vector3(
            y * rhs.z - z * rhs.y,
            z * rhs.x - x * rhs.z,
            x * rhs.y - y * rhs.x
        );
    }

    /// Return absolute vector.
    Vector3 Abs() const { return Vector3(tc::Abs(x), tc::Abs(y), tc::Abs(z)); }

    /// Linear interpolation with another vector.
    Vector3 Lerp(const Vector3& rhs, float t) const { return *this * (1.0f - t) + rhs * t; }

    /// Test for equality with another vector with epsilon.
    bool Equals(const Vector3& rhs) const
    {
        return tc::Equals(x, rhs.x) && tc::Equals(y, rhs.y) && tc::Equals(z, rhs.z);
    }

    /// Returns the angle between this vector and another vector in degrees.
    float Angle(const Vector3& rhs) const { return tc::Acos(DotProduct(rhs) / (Length() * rhs.Length())); }

    /// Return whether is NaN.
    bool IsNaN() const { return tc::IsNaN(x) || tc::IsNaN(y) || tc::IsNaN(z); }

    /// Return normalized to unit length.
    Vector3 Normalized() const
    {
        float lenSquared = LengthSquared();
        if (!tc::Equals(lenSquared, 1.0f) && lenSquared > 0.0f)
        {
            float invLen = 1.0f / sqrtf(lenSquared);
            return *this * invLen;
        }
        else
            return *this;
    }

    /// Return float data.
    const float* Data() const { return &x; }

    /// Return as string.
    std::string ToString() const;

    /// Return hash value for HashSet & HashMap.
    unsigned ToHash() const
    {
        unsigned hash = 37;
        hash = 37 * hash + FloatToRawIntBits(x);
        hash = 37 * hash + FloatToRawIntBits(y);
        hash = 37 * hash + FloatToRawIntBits(z);

        return hash;
    }

    /// X coordinate.
    float x;
    /// Y coordinate.
    float y;
    /// Z coordinate.
    float z;

    /// Zero vector.
    static const Vector3 ZERO;
    /// (-1,0,0) vector.
    static const Vector3 LEFT;
    /// (1,0,0) vector.
    static const Vector3 RIGHT;
    /// (0,1,0) vector.
    static const Vector3 UP;
    /// (0,-1,0) vector.
    static const Vector3 DOWN;
    /// (0,0,-1) vector.
    static const Vector3 FORWARD;
    /// (0,0,1) vector.
    static const Vector3 BACK;
    /// (1,1,1) vector.
    static const Vector3 ONE;
};

/// Multiply Vector3 with a scalar.
inline Vector3 operator *(float lhs, const Vector3& rhs) { return rhs * lhs; }

/// Multiply IntVector3 with a scalar.
inline IntVector3 operator *(int lhs, const IntVector3& rhs) { return rhs * lhs; }

/// Per-component linear interpolation between two 3-vectors.
inline Vector3 VectorLerp(const Vector3& lhs, const Vector3& rhs, const Vector3& t) { return lhs + (rhs - lhs) * t; }

/// Per-component min of two 3-vectors.
inline Vector3 VectorMin(const Vector3& lhs, const Vector3& rhs) { return Vector3(Min(lhs.x, rhs.x), Min(lhs.y, rhs.y), Min(lhs.z, rhs.z)); }

/// Per-component max of two 3-vectors.
inline Vector3 VectorMax(const Vector3& lhs, const Vector3& rhs) { return Vector3(Max(lhs.x, rhs.x), Max(lhs.y, rhs.y), Max(lhs.z, rhs.z)); }

/// Per-component floor of 3-vector.
inline Vector3 VectorFloor(const Vector3& vec) { return Vector3(Floor(vec.x), Floor(vec.y), Floor(vec.z)); }

/// Per-component round of 3-vector.
inline Vector3 VectorRound(const Vector3& vec) { return Vector3(Round(vec.x), Round(vec.y), Round(vec.z)); }

/// Per-component ceil of 3-vector.
inline Vector3 VectorCeil(const Vector3& vec) { return Vector3(Ceil(vec.x), Ceil(vec.y), Ceil(vec.z)); }

/// Per-component floor of 3-vector. Returns IntVector3.
inline IntVector3 VectorFloorToInt(const Vector3& vec) { return IntVector3(FloorToInt(vec.x), FloorToInt(vec.y), FloorToInt(vec.z)); }

/// Per-component round of 3-vector. Returns IntVector3.
inline IntVector3 VectorRoundToInt(const Vector3& vec) { return IntVector3(RoundToInt(vec.x), RoundToInt(vec.y), RoundToInt(vec.z)); }

/// Per-component ceil of 3-vector. Returns IntVector3.
inline IntVector3 VectorCeilToInt(const Vector3& vec) { return IntVector3(CeilToInt(vec.x), CeilToInt(vec.y), CeilToInt(vec.z)); }

/// Per-component min of two 3-vectors.
inline IntVector3 VectorMin(const IntVector3& lhs, const IntVector3& rhs) { return IntVector3(Min(lhs.x, rhs.x), Min(lhs.y, rhs.y), Min(lhs.z, rhs.z)); }

/// Per-component max of two 3-vectors.
inline IntVector3 VectorMax(const IntVector3& lhs, const IntVector3& rhs) { return IntVector3(Max(lhs.x, rhs.x), Max(lhs.y, rhs.y), Max(lhs.z, rhs.z)); }

/// Return a random value from [0, 1) from 3-vector seed.
inline float StableRandom(const Vector3& seed) { return StableRandom(Vector2(StableRandom(Vector2(seed.x, seed.y)), seed.z)); }

}
