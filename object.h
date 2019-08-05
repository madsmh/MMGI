//
// Created by mads on 05/08/2019.
//

#ifndef MGI_OBJECT_H
#define MGI_OBJECT_H


#include "vector3.h"
#include "ray.h"

class Object {
protected:
    Vector3 m_position;
    Vector3 m_color;
    double m_emission;
    int m_type;
public:
    virtual double intersect(const Ray&) const = 0;
    virtual Vector3 normal(const Vector3&) const = 0;
    Vector3 getPosition(){
        return  m_position;
    }
    void setPosition(Vector3 position){
        m_position = position;
    }
};


#endif //MGI_OBJECT_H
