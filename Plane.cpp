//-------------------------------------------------------
//
//  Plane.cpp
//
//  Plane class with a point on plane and a normal
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#include "Plane.h"

float Plane::Intersection(const Ray &ray) const
{

    Vector og = ray.get_origin();
    Vector dir = ray.get_direction();
    double t = -(og - plane_position) * normal;
    t = t / (dir * normal);
    if (dir * normal == 0) // Checking if the ray is on the plane
    {
        return -1;
    }
    else
    {
        if (t >= 0)
        {
            return t;
        }
        else
        {
            return -1;
        }
    }
};
Color Plane::get_color() const
{
    return color;
};
Color Plane::shade(const Vector &P, const Light &l) const
{
    Vector normal_at_intersection = normal;
    normal_at_intersection = normal_at_intersection.normalize();
    Vector vectorToLight = l.get_position() - P;
    vectorToLight = vectorToLight.normalize();
    double f;
    if (normal_at_intersection * vectorToLight > 0)
    {
        f = normal_at_intersection * vectorToLight;
    }
    else
    {
        f = 0;
    }
    float red = l.get_color().red() * color.red() * f;
    float green = l.get_color().green() * color.green() * f;
    float blue = l.get_color().blue() * color.blue() * f;
    const Color shaded_color(red, green, blue, 0);
    return shaded_color;
};
