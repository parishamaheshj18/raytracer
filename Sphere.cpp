//-------------------------------------------------------
//
//  Sphere.cpp
//
//  Sphere class with a center and radius
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#include "Sphere.h"
#include <cmath>
#include <cstdio>

const Vector &Sphere::get_center_position() const
{
    return center_position;
};

const double &Sphere::get_radius() const
{
    return radius;
};

float Sphere::Intersection(const Ray &ray) const
{
    Vector dir = ray.get_direction();
    Vector og = ray.get_origin();
    Vector sphrCen = get_center_position();
    double rad = get_radius();

    double a = dir * dir;
    double b = 2 * dir * (og - sphrCen);
    double c = ((og - sphrCen) * (og - sphrCen)) - (rad * rad);

    double f = b * b - 4 * a * c;
    double t1 = (-b + sqrt(f)) / 2;
    double t2 = (-b - sqrt(f)) / 2;
    if (f < 0)
    {
        return -1;
    }
    if (f == 0)
    {
        double t = -dir * (og - sphrCen);
        if (t < 0)
        {
            return -1;
        }
        if (t > 0)
        {
            return t;
        }
    }
    if (f > 0)
    {

        if (t1 < t2)
        {
            return t1;
        }
        else
        {
            return t2;
        }
    }
    else
    {
        return -1;
    }
};

Color Sphere::get_color() const { return color; };
Color Sphere::shade(const Vector &P, const Light &l) const
{
    //for 1 light
    Vector normal_at_intersection = P - center_position;
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

// //Uncomment this for generating output2.ppm
// Color Sphere::shade(const Vector &P, const Light &l1) const
// { // For two lights:

//     Vector light2_position = Vector(1, 1, -3);
//     Color light2_color = Color(0.15, 0.35, 0.05, 0);
//     Light l2(light2_position, light2_color);

//     Vector normal_at_intersection = P - center_position;
//     normal_at_intersection = normal_at_intersection.normalize();

//     Vector vectorToLight1 = l1.get_position() - P;
//     vectorToLight1 = vectorToLight1.normalize();
//     Vector vectorToLight2 = l2.get_position() - P;
//     vectorToLight2 = vectorToLight2.normalize();
//     double f1, f2;
//     if (normal_at_intersection * vectorToLight1 > 0)
//     {
//         f1 = normal_at_intersection * vectorToLight1;
//     }
//     else
//     {
//         f1 = 0;
//     }
//     if (normal_at_intersection * vectorToLight2 > 0)
//     {
//         f2 = normal_at_intersection * vectorToLight2;
//     }
//     else
//     {
//         f2 = 0;
//     }
//     float red = (l2.get_color().red() * color.red() * f2 + l1.get_color().red() * color.red() * f1) ;
//     float green = (l2.get_color().green() * color.green() * f2 + l1.get_color().green() * color.green() * f1) ;
//     float blue = (l2.get_color().blue() * color.blue() * f2 + l1.get_color().blue() * color.blue() * f1) ;
//     const Color shaded_color(red, green, blue, 0);
//     return shaded_color;
// }