//---------------------------------------------------------------------
//
//  Geometry.h
//
//  Geometry class to store objects such as triangle, sphere, planes
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//----------------------------------------------------------------------

#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Vector.h"
#include <vector>
#include "Color.h"
#include "Light.h"

//static const double small_t = 1e-4;

class Ray;

class Geometry
{
public:
    //Geometry();
    virtual float Intersection(const Ray &ray) const = 0;
    virtual Color get_color() const { return Color(0.0, 0.0, 0.0, 0); };
    virtual Color shade(const Vector &P, const Light &l) const { return Color(0.0, 0.0, 0.0, 0); };
};
#endif