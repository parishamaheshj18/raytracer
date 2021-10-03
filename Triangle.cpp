//-------------------------------------------------------
//
//  Triangle.cpp
//
//  Triangle class with vertices, color and normal
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#include "Triangle.h"
#include <cmath>
#include <cstdio>

float Triangle::Intersection(const Ray &ray) const
{
    // Algorithm: first find the intersection of ray with triangle plane and then check if the point is inside the triangle bounds.
    Vector ray_dir = ray.get_direction();
    Vector ray_og = ray.get_origin();
    Vector edge1 = vertex_1 - vertex_0;
    Vector edge2 = vertex_2 - vertex_0;
    Vector T = ray.get_origin() - vertex_0;
    Vector P = ray.get_direction() ^ edge2;
    Vector og = ray.get_origin();
    Vector dir = ray.get_direction();
    double t = -(og - vertex_0) * normal;
    t = t / (dir * normal);
    Vector Q = T ^ edge1;
    double u = (P * T) / (P * edge1);
    double v = (Q * ray_dir) / (P * edge1);
    if (dir * normal == 0)
    {
        return -1;
    }
    else
    {

        if (t >= 0)
        {
            if (u >= 0 && u <= 1 && v >= 0 && v <= 1 && (u + v) >= 0 && (u + v) <= 1)
            {
                return t;
            }
            else
            {

                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
}

Color Triangle::get_color() const
{
    return color;
};

Color Triangle::shade(const Vector &P, const Light &l1) const
{
    //for 1 light
    Vector normal_at_intersection = normal;
    normal_at_intersection = normal_at_intersection.normalize();
    Vector vectorToLight1 = l1.get_position() - P;
    vectorToLight1 = vectorToLight1.normalize();

    double f1;
    if (normal_at_intersection * vectorToLight1 > 0)
    {
        f1 = normal_at_intersection * vectorToLight1;
    }
    else
    {
        f1 = 0;
    }

    float red = l1.get_color().red() * color.red() * f1;
    float green = l1.get_color().green() * color.green() * f1;
    float blue = l1.get_color().blue() * color.blue() * f1;
    const Color shaded_color(red, green, blue, 0);
    return shaded_color;
};

// //Uncomment this for generating output2.ppm
// Color Triangle::shade(const Vector &P, const Light &l1) const
// {
//     //for 2 lights:
//     Vector light2_position = Vector(1, 1, -3);
//     Color light2_color = Color(0.15, 0.35, 0.05, 0);
//     Light l2(light2_position, light2_color);
//     Vector normal_at_intersection = normal;
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
//     float red = (l2.get_color().red() * color.red() * f2 + l1.get_color().red() * color.red() * f1);
//     float green = (l2.get_color().green() * color.green() * f2 + l1.get_color().green() * color.green() * f1);
//     float blue = (l2.get_color().blue() * color.blue() * f2 + l1.get_color().blue() * color.blue() * f1);
//     const Color shaded_color(red, green, blue, 0);
//     return shaded_color;
// };