//-------------------------------------------------------
//
//  Camera.h
//
//  Camera header
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Vector.h"
#include "math.h"
#define PI 3.14159265
class Camera
{
public:
    Vector position;
    Vector view_direction;
    Vector up_direction;
    Vector right_direction;
    double h_field_of_view;
    double v_field_of_view;
    double aspect_ratio;

    Camera() : position(0, 0, 0),
               view_direction(0, 1, 0),
               up_direction(0, 0, 0), right_direction(0, 0, 1),
               h_field_of_view(90 * PI / 180),
               aspect_ratio(1.3333){};
    Camera(Vector &position_ip,
           Vector &view_direction_ip,
           Vector &up_direction_ip,
           Vector &right_direction_ip,
           double &h_fov,
           double &aspect_ratio_ip) : position(position_ip),
                                      view_direction(view_direction_ip),
                                      up_direction(up_direction_ip),
                                      right_direction(right_direction_ip),
                                      h_field_of_view(h_fov * PI / 180),
                                      aspect_ratio(aspect_ratio_ip) { v_field_of_view = 2 * atan(tan(h_fov * PI / (2 * 180)) / aspect_ratio_ip); };

    const Vector &get_camera_position() { return position; };
    const Vector &get_camera_direction() { return view_direction; };
    const Vector &get_camera_up_direction() { return up_direction; };
    const Vector &get_camera_right_direction() { return right_direction; };
    const Vector view(const float x, const float y) const;
};
#endif
