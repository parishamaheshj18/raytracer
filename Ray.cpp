//-------------------------------------------------------
//
//  Ray.cpp
//
//  Ray with an origin and direction
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#include "Ray.h"

const Vector &Ray::get_origin() const { return origin; };
const Vector &Ray::get_direction() const { return direction; };
Ray::Ray()
{
    origin = Vector(0, 0, 0);
    direction = Vector(1, 0, 0);
}

Ray::Ray(const Vector &origin_input, const Vector &direction_input)
{
    origin = origin_input;
    direction = direction_input;
};