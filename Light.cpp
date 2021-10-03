//-------------------------------------------------------
//
//  Camera.C
//
//  Camera class
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#include "Light.h"

const Vector &Light::get_position() const
{
    return position;
};
const Color &Light::get_color() const
{
    return color;
};
