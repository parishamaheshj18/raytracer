
OBJ = raytracer.o \
		Camera.o\
		Sphere.o \
		Plane.o\
		Triangle.o\
		Light.o \
		Ray.o


CXX = g++ -Wall -g -O2 -std=c++11
INC =  -I ./ -I /usr/local/include/ -I /usr/include/ 


.C.o: 
	$(CXX) -c $(INC) $< -o $@

Rasterrain: $(OBJ)
	$(CXX)  $(OBJ) -o raytrace -Wall -O3 
	


raytracer.o:
	$(CXX)  -c raytracer.cpp $(INC)

clean:
	rm -f raytrace *.d *.o output.ppm


