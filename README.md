# raytracer

Ray tracer with C++
## 3 Steps to run the code:
```
  $make clean
  $make 
  $./raytrace
```
## Shading
For this code I am using Lambertian shading. I will add more examples of other kinds of shadings if I get time.

## Output files

Your output will be stored as output.ppm.
The two outputs which I got in previous runs are saved as output1.ppm and output2.ppm. 
Where output1.ppm is with one pointlight and ouput2.ppm is with two pointlights.

To generate the output2.ppm, Go to Sphere.cpp and Triangle.cpp and uncomment the second shade() definition. 
For this project light two will only affect sphere and triangle so I'm not using a vector. instead just hardcoding the second light with shade definition.


## Output with One light

<img width="1018" alt="Screen Shot 2021-10-03 at 02 37 23" src="https://user-images.githubusercontent.com/47680537/135742992-9dacbd00-246c-496e-8011-e0266ab6e3b4.png">

## Output with Two lights

<img width="1019" alt="Screen Shot 2021-10-03 at 02 37 42" src="https://user-images.githubusercontent.com/47680537/135742995-e3e97838-bb69-4406-9392-205a6585d4c8.png">
