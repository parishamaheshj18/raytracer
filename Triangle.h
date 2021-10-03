//-------------------------------------------------------
//
//  Triangle.h
//
//  Triangle class with vertices, color and normal
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "Geometry.h"
#include "Vector.h"
#include "Color.h"
#include "Light.h"
#include "Ray.h"

class Triangle : public Geometry
{
public:
    Vector vertex_0;
    Vector vertex_1;
    Vector vertex_2;
    Color color;
    Vector normal;

    Triangle(const Vector &vertex0_ip, const Vector &vertex1_ip, const Vector &vertex2_ip, const Color &color_ip) : vertex_0(vertex0_ip),
                                                                                                                    vertex_1(vertex1_ip),
                                                                                                                    vertex_2(vertex2_ip),
                                                                                                                    color(color_ip)
    {

        normal = (vertex_1 - vertex_0) ^ (vertex_2 - vertex_0);
        normal = normal / normal.magnitude();
        std::cout << normal.X() << normal.Y() << normal.Z() << std::endl;
    }

    virtual float Intersection(const Ray &ray) const override;
    virtual Color get_color() const override;
    virtual Color shade(const Vector &P, const Light &l1) const override;
};
#endif