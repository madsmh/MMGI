//
// Created by mads on 05/08/2019.
//

#ifndef MGI_SCENE_H
#define MGI_SCENE_H


#include <vector>
#include "light.h"
#include "object.h"
#include "camera.h"

struct HitRecord {
    bool isHit;
    double intersect;

};

class Scene {
private:
    std::vector<Object> m_objects;
    std::vector<Light> m_lights;
    std::vector<Camera> m_cameras;

public:
    Scene (std::vector<Camera> camera_list, std::vector<Object> object_list, std::vector<Light> light_list){
        m_cameras = camera_list; m_objects = object_list; m_lights = light_list;
    }

    // Returns the location of the closest object the ray hits.
    int getClosestObjectID(Ray ray, double& t_min){

        double t = MAXFLOAT;
        int id = -1;

        for (int i = 0; i < (int) m_objects.size(); ++i) {

            double t_temp = m_objects[i].intersect(ray);

            if (t_temp>0 and t > t_temp){
                t=t_temp;
                id = i;
            }
        }

        t_min = t;
        return id;
    }

    Ray getRayFromCamera(int cam_number, int u, int v){
        return m_cameras[cam_number].getRay(u,v);
    }

};




#endif //MGI_SCENE_H
