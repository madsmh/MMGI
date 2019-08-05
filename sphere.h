//
// Created by mads on 05/08/2019.
//

#ifndef MGI_SPHERE_H
#define MGI_SPHERE_H


#include "object.h"

class Sphere : public Object {
private:
    double m_radius;
public:
    Sphere(Vector3 color = Vector3(),
            double emission = 0,
            int mat_type = 0,
            double radius=1,
            Vector3 postion = Vector3()){
        m_type = mat_type; m_emission = emission; m_type = mat_type;
        m_radius = radius; m_position = postion;
    }

    Vector3 normal(Vector3 p){
        return (m_position - p)/m_radius;
    }

    double intersect(const Ray& ray){

        // double a = ray.getDirection().norm2() = 1
        double b = 2 * (ray.getDirection().dot(ray.getOrigin()-m_position));
        double c = (ray.getOrigin()-m_position).norm2()-m_radius*m_radius;
        double d = b*b -4*c;

        if (d>0){
            d = std::sqrt(d);
            double s1 = -b + d;
            double s2 = -b - d;

            return (s2 > 0) ? s2/2 :( (s1>0) ? s1/2 : 0);
        }

        return false;



    }

};


#endif //MGI_SPHERE_H
