//-------------------------------------------------------
//
//  Camera.C
//
//  Camera class
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#include "Camera.h"

const Vector Camera::view(const float x, const float y) const
{
    Vector ray_direction = view_direction + (right_direction * (x - 0.5) + up_direction * (y - 0.5));
    ray_direction = ray_direction.normalize();
    return ray_direction;
}
