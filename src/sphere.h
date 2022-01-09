#pragma once 
#include"hittable.h"

class sphere : public hittable {
    public:
        sphere() {}
        sphere(point3d c, double r) : center(c), radius(r) {};

        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

    public: 
        point3d center; 
        double radius; 
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto b_half = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;

    auto disciminant = b_half*b_half - a*c;
    if(disciminant < 0) {
        return false;
    } 
    auto sqrtd = sqrt(disciminant);

    auto root = (-b_half - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-b_half + sqrtd) / a;
        if (root < t_min || t_max < root) {
            return false; 
        }
    }
    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius; 
    rec.set_face_normal(r, outward_normal);

    return true;
}