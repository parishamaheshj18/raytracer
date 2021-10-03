//-------------------------------------------------------
//
//  Sphere.h
//
//  Sphere with a center and a radius
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Geometry.h"
#include "Vector.h"
#include "Color.h"
#include "Light.h"
#include "Ray.h"

class Sphere : public Geometry
{
    const Vector center_position;
    double radius;
    Color color;

public:
    Sphere(const Vector &center_input, double &radius_input, const Color &color_ip) : center_position(center_input), radius(radius_input), color(color_ip)
    {
    }
    const Vector &get_center_position() const;
    const double &get_radius() const;
    virtual float Intersection(const Ray &ray) const override;
    virtual Color get_color() const override;
    virtual Color shade(const Vector &P, const Light &l) const override;
};
#endif