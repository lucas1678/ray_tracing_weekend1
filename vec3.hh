#ifndef VEC3_HH
#define VEC3_HH

#include <cmath>
#include <iostream>

class vec3
{
    public:
        double e[3];
        vec3() : e{0,0,0} {}
        vec3(double e0,double e1,double e2) : e{e0,e1,e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; } //access value of vector at index i, such that we can only READ it (constant)
        double& operator[](int i) { return e[i]; } //get reference of value of vector at index i, in a way so we can modify it such as v[1] = 10; etc..

        vec3& operator+=(const vec3& v) //passing by a constant reference is a smart way to pass by value, without making an unecessary copy.. ;)
        {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator*=(double t)
        {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(double t)
        {
            return *this *= 1./t;
        }

        double length() const
        {
            return std::sqrt(length_squared());
        }

        double length_squared() const
        {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

};

using point3 = vec3; // declare an alias, AKA a typedef for <C++11

inline std::ostream& operator<<(std::ostream& out, const vec3& v)
{
    return out << '(' << v.e[0] << ',' << v.e[1] << ',' << v.e[2] << ')';
}

inline vec3 operator+(const vec3& v, const vec3& u)
{
    return vec3(v.e[0] + u.e[0], v.e[1] + u.e[1], v.e[2] + u.e[2]);
}

inline vec3 operator-(const vec3& v, const vec3& u)
{
    return vec3(v.e[0] - u.e[0], v.e[1] - u.e[1], v.e[2] - u.e[2]);
}

inline vec3 operator*(const vec3& v, const vec3& u)
{
    return vec3(v.e[0] * u.e[0], v.e[1] * u.e[1], v.e[2] * u.e[2]);
}

inline vec3 operator*(const vec3& v, double t)
{
    return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline vec3 operator*(double t, const vec3& v)
{
    return v*t;
}

inline vec3 operator/(const vec3& v, double t)
{
    return v*(1./t);
}

inline double dot(const vec3& v, const vec3& u)
{
    return v.e[0]*u.e[0] + v.e[1]*u.e[1] + v.e[1]*u.e[1];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v)
{
    return v / v.length();
}


#endif