//-------------------------------------------------------
//
//  Plane.h
//
//  Plane class with a point on plane and a normal
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#ifndef __PLANE_H__
#define __PLANE_H__

#include "Geometry.h"
#include "Vector.h"
#include "Color.h"
#include "Light.h"
#include "Ray.h"

class Plane : public Geometry
{
public:
    const Vector plane_position;
    Vector normal;
    Color color;

    Plane(const Vector &position, const Vector &normal_input, const Color &color_ip)
        : plane_position(position), normal(normal_input), color(color_ip)
    {
    }

    virtual float Intersection(const Ray &ray) const override;
    virtual Color get_color() const override;
    virtual Color shade(const Vector &P, const Light &l) const override;
};
#endif