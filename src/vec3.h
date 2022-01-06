#pragma once

#include<array>
#include<cmath>
#include<iostream>

class vec3 {
    public: 
        vec3() : e{0,0,0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const {return e[0]; }
        double y() const {return e[1]; }
        double z() const {return e[2]; }

        vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const {return e.at(i); }
        double& operator[](int i) {return e.at(i); }

        vec3& operator+=(const vec3 &v) {
            e[0] += v[0];
            e[1] += v[1];
            e[2] += v[2];
            return *this;
         }

         vec3& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
         }

        vec3& operator/=(const double t) {
            return (*this *= 1/t);
         }

         double length() const {
             return sqrt(length_squared());
         }

         double length_squared() const {
             return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
         }


    private:
        std::array<double, 3> e{};
};

// aliases 

using point3 = vec3; 
using color = vec3;

// utility functions

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3{u.x()+v.x(), u.y()+v.y(), u.z()+v.z()};
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3{u.x()-v.x(), u.y()-v.y(), u.z()-v.z()};
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3{u.x()*v.x(), u.y()*v.y(), u.z()*v.z()};
}

inline vec3 operator*(const vec3 &u, const double t) {
    return vec3{u.x()*t, u.y()*t, u.z()*t};
}

inline vec3 operator*(const double t, const vec3 &u) {
    return u*t;
}

inline vec3 operator/(const vec3 &u, const double t) {
    return 1/t * u;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.x() * v.x()
         + u.y() * v.y()
         + u.z() * v.z();
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

inline vec3 unit_vector(vec3 u) {
    return u / u.length();
}
