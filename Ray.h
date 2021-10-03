//-------------------------------------------------------
//
//  Ray.h
//
//  Ray class with origin and direction
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#ifndef __RAY_H__
#define __RAY_H__

#include "Vector.h"

class Object;
class Ray
{
public:
    Ray();
    Ray(const Vector &origin_input, const Vector &direction_input);

    const Vector &get_origin() const;
    const Vector &get_direction() const;

private:
    Vector origin;
    Vector direction;
};

#endif