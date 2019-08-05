//
// Created by mads on 05/08/2019.
//

#ifndef MGI_CAMERA_H
#define MGI_CAMERA_H


#include "vector3.h"
#include "ray.h"

class Camera {
private:
    Vector3 m_origin;
    double m_theta;
    double m_psi;
    int m_width;
    int m_height;
    double m_fov_x;
    double m_fov_y;
    double m_aspect_ratio;

    Vector3 getWorldCoords (int u, int v){
        double x = ((double) 2.0*u-m_width)/((double) m_width)*std::tan(m_fov_x);
        double y = ((double) 2.0*v-m_height)/((double) m_height)*std::tan(m_fov_y);
        double z = -1.0;

        return Vector3(x, y, z);
    }

public:
    Camera(Vector3 position, Vector3 direction, int width, int height, double fov_x){
        m_width = width, m_height = height, m_fov_x = fov_x;
        m_fov_y =((double) m_height)/((double) width) * m_fov_x;
        m_aspect_ratio = ((double) width)/((double) height);
    }

    Ray getRay(int u, int v){

        return {m_origin, getWorldCoords(u, v) - m_origin};

    }

    // TODO Implement setCameraOrientation
    void  setCameraOrientation(double theta, double psi);

    void setCameraPosition(Vector3 new_position){
        m_origin = new_position;
    }
};


#endif //MGI_CAMERA_H
