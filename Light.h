//-------------------------------------------------------
//
//  Light.h
//
//  Point light with position and color
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#ifndef __LIGHT_H__
#define __LIGHT_H__

#include <math.h>
#include <vector>
#include <iostream>
#include <limits>
#include "Vector.h"
#include "Color.h"
class Ray;

class Light
{
public:
    Light();
    Light(const Vector &position_ip, const Color &color_ip) : position(position_ip),
                                                              color(color_ip){};

    const Vector &get_position() const;
    const Color &get_color() const;

    Vector position;
    Color color; // RGB color components
};
#endif