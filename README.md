# raytracer

Ray tracer with C++
## 3 Steps to run the code:
```
  $make clean
  $make 
  $./raytrace
```
## Output files

Your output will be stored as output.ppm.
The two outputs which I got in previous runs are saved as output1.ppm and output2.ppm. 
Where output1.ppm is with one pointlight and ouput2.ppm is with two pointlights.

To generate the output2.ppm, Go to Sphere.cpp and Triangle.cpp and uncomment the second shade() definition. 
For this project light two will only affect sphere and triangle so I'm not using a vector. instead just hardcoding the second light with shade definition.

![output](https://user-images.githubusercontent.com/47680537/135742916-ab95b029-cba6-4a08-b093-0f47b66992d3.png)

![output2](https://user-images.githubusercontent.com/47680537/135742924-f4c6b487-d7d0-462c-b907-54cd7b2b14fb.png)

