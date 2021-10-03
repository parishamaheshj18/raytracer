//-------------------------------------------------------
//
//  raytracer.cpp
//
//  Main function for raytracer
//
//  Copyright (c) 2021 Parisha Joshi
//
//
//--------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Color.h"
#include "Vector.h"
#include <cstdio>
#include "Ray.h"
#include "Camera.h"
#include "Light.h"
#include "Sphere.h"
#include "Geometry.h"
#include "Plane.h"
#include "Triangle.h"

using namespace std;

void saveppm(const char *filename, int w, int h, Color *data)
{

    ofstream outfile(filename, ios_base::out);

    outfile << "P3\n"
            << w << " " << h << "\n255\n";
    std::cout << "P3\n"
              << w << " " << h << "\n255\n";
    Color rgb;

    for (int j = 0; j < h; j++)
    {
        for (int i = 0; i < w; i++)
        {
            rgb = data[i + w * j];
            float red = (rgb.red()) * 255.99;
            float green = (rgb.green()) * 255.99;
            float blue = (rgb.blue()) * 255.99;
            outfile << int(red) << " " << int(green) << " " << int(blue) << "\n";
        };
    }
}

int getIndexOfClosestObject(vector<double> geometry_intersections)
{
    //loops through each geometry and checks which object is the closest
    int _smallest_distance_index;

    if (geometry_intersections.size() == 0)
    {
        return -1;
    }

    else if (geometry_intersections.size() == 1)
    {
        if (geometry_intersections.at(0) > 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    else
    {
        //two or more intersections
        double max = 0;
        for (int i = 0; i < geometry_intersections.size(); i++)
        {
            if (geometry_intersections.at(i) > max)
            {
                max = geometry_intersections.at(i);
            }
        }

        if (max > 0)
        {
            for (int i = 0; i < geometry_intersections.size(); i++)
            {
                if (geometry_intersections.at(i) > 0 && geometry_intersections.at(i) < max)
                {
                    max = geometry_intersections.at(i);
                    _smallest_distance_index = i;
                }
            }
            return _smallest_distance_index;
        }

        else
        {
            return -1;
        }
    }
}

Color Trace(const Ray &cam_ray, const vector<Geometry *> &scene_objects, const Light &light1)
{
    cout << "Coloring.. Please wait.." << endl;

    std::vector<double> intersections;
    Color this_pixel_color;
    Color pixel_color;

    for (int index = 0; index < scene_objects.size(); index++)
    {
        intersections.push_back(scene_objects.at(index)->Intersection(cam_ray));
    }

    int index_of_closest_object = getIndexOfClosestObject(intersections);

    if (index_of_closest_object == -1)
    {
        //set black if no intersection
        pixel_color.set(0, 0, 0, 0);
        return pixel_color;
    }
    else
    {
        if (index_of_closest_object == 0 || index_of_closest_object == 6 || index_of_closest_object == 7 || index_of_closest_object == 8 || index_of_closest_object == 9)
        {
            this_pixel_color = scene_objects.at(index_of_closest_object)->shade(cam_ray.get_origin() + (cam_ray.get_direction() * intersections.at(index_of_closest_object)), light1);
        }
        else
        {
            this_pixel_color = scene_objects.at(index_of_closest_object)->shade(cam_ray.get_origin() + (cam_ray.get_direction() * intersections.at(index_of_closest_object)), light1);
        }
        pixel_color.set(this_pixel_color.red(), this_pixel_color.green(), this_pixel_color.blue(), 0);
        return pixel_color;
        //cout << "coloring" << endl;
    }
}

int main(int argc, char *argv[])
{
    cout << "rendering ..." << endl;

    int Nx = 1024; //width
    int Ny = 768;  //height
    int n = Nx * Ny;
    double aspectratio = 1.3333;
    double fov = 90.0;

    Color *pixels = new Color[n];
    Vector X(1, 0, 0);
    Vector Y(0, 1, 0);
    Vector Z(0, 0, 1);
    //Camera
    Vector cam_view(0, 0, 1);
    Vector cam_pos(0, 0, 0);
    Vector cam_up(0, 1, 0);
    Vector cam_right = cam_up ^ cam_view;
    cam_right = cam_right.normalize();
    Camera scene_cam(cam_pos, cam_view, cam_up, cam_right, fov, aspectratio);

    //Lights
    Vector light1_position = Vector(-1, -1, 7);
    Color light1_color = Color(1, 1, 1, 0);
    Light light1(light1_position, light1_color);

    Vector light2_position = Vector(1, 1, -3);
    Color light2_color = Color(0.15, 0.35, 0.05, 0);
    Light light2(light2_position, light2_color);

    //Sphere
    Vector sphere1_center(1.1, 1.25, 7);
    double sphere1_radius = 1;
    Color sphere1_color(0.5, 0.5, 1, 1);
    Sphere sphere_1(sphere1_center, sphere1_radius, sphere1_color);

    //Planes
    Vector plane0_position(0, 2, 0);
    Vector plane0_normal(0, -1, 0);
    Color plane0_color(1, 1, 1, 0);

    Vector plane1_position(0, -2, 0);
    Vector plane1_normal(0, 1, 0);
    Color plane1_color(1, 1, 1, 0);

    Vector plane2_position(-2, 0, 0);
    Vector plane2_normal(1, 0, 0);
    Color plane2_color(1, 0, 0, 0);

    Vector plane3_position(2, 0, 0);
    Vector plane3_normal(-1, 0, 0);
    Color plane3_color(0, 1, 0, 0);

    Vector plane4_position(0, 0, 10);
    Vector plane4_normal(0, 0, -1);
    Color plane4_color(1, 1, 1, 0);

    Plane plane0(plane0_position, plane0_normal, plane0_color);
    Plane plane1(plane1_position, plane1_normal, plane1_color);
    Plane plane2(plane2_position, plane2_normal, plane2_color);
    Plane plane3(plane3_position, plane3_normal, plane3_color);
    Plane plane4(plane4_position, plane4_normal, plane4_color);

    //Triangles
    float c_0 = 0.96078431372, c_1 = 0.4; // conversion from 245/255, 102/255

    Vector vertex0_0(-1.5, 0.6, 5);
    Vector vertex1_0(-1.8, 0.9, 5);
    Vector vertex2_0(-1.7, 0.4, 5);
    Color tri0_color(c_0, c_1, 0, 0);
    Triangle triangle0(vertex0_0, vertex1_0, vertex2_0, tri0_color);

    Vector vertex0_1(-1.8, 0.9, 5);
    Vector vertex1_1(-1.7, 0.4, 5);
    Vector vertex2_1(1.1, 3.25, 3);
    Color tri1_color(c_0, c_1, 0, 0);
    Triangle triangle1(vertex0_1, vertex1_1, vertex2_1, tri1_color);

    Vector vertex0_2(-1.7, 0.4, 5);
    Vector vertex1_2(1.1, 3.25, 3);
    Vector vertex2_2(-1.5, 0.6, 5);
    Color tri2_color(0, c_0, c_1, 0);
    Triangle triangle2(vertex0_2, vertex1_2, vertex2_2, tri2_color);

    Vector vertex0_3(1.1, 3.25, 3);
    Vector vertex1_3(-1.5, 0.6, 5);
    Vector vertex2_3(-1.8, 0.9, 5);
    Color tri3_color(c_1, 0, c_0, 0);
    Triangle triangle3(vertex0_3, vertex1_3, vertex2_3, tri3_color);

    //Add objects to Scene
    vector<Geometry *> scene_objects;
    scene_objects.push_back(dynamic_cast<Geometry *>(&sphere_1));
    scene_objects.push_back(dynamic_cast<Geometry *>(&plane0));
    scene_objects.push_back(dynamic_cast<Geometry *>(&plane1));
    scene_objects.push_back(dynamic_cast<Geometry *>(&plane2));
    scene_objects.push_back(dynamic_cast<Geometry *>(&plane3));
    scene_objects.push_back(dynamic_cast<Geometry *>(&plane4));
    scene_objects.push_back(dynamic_cast<Geometry *>(&triangle0));
    scene_objects.push_back(dynamic_cast<Geometry *>(&triangle1));
    scene_objects.push_back(dynamic_cast<Geometry *>(&triangle2));
    scene_objects.push_back(dynamic_cast<Geometry *>(&triangle3));

    int thispixel;
    double xamnt, yamnt;
    for (int x = 0; x < Nx; x++)
    {

        for (int y = 0; y < Ny; y++)
        {

            thispixel = y * Nx + x;

            if (Nx > Ny)
            {
                //cout << "Nx > Ny" << endl;
                xamnt = ((x + 0.5) / Nx) * aspectratio - (((Nx - Ny) / (double)Ny) / 2);
                yamnt = ((Ny - y) + 0.5) / Ny;
            }
            else if (Ny > Nx)
            {
                xamnt = (x + 0.5) / Nx;
                yamnt = ((((Ny - y) + 0.5) / Ny) / aspectratio) - (((Ny - Nx) / (double)Nx) / 2);
            }
            else
            {
                //cout << "Nx = Ny" << endl;
                //square image
                xamnt = (x + 0.5) / Nx;
                yamnt = ((Ny - y) + 0.5) / Ny;
            }

            Vector cam_ray_origin = scene_cam.get_camera_position();
            Vector cam_ray_direction = scene_cam.view(xamnt, yamnt);
            Ray cam_ray(cam_ray_origin, cam_ray_direction);

            Color this_pixel_color = Trace(cam_ray, scene_objects, light1);

            pixels[thispixel].set(this_pixel_color.red(), this_pixel_color.green(), this_pixel_color.blue(), 0);
        }
    }
    saveppm("output.ppm", Nx, Ny, pixels);
    cout << "Done" << endl;
    return 0;
}
