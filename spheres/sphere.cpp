#include "sphere.h"
#include <math.h>
float Sphere::density = 5;
float Sphere :: calculateVolume();
int main()
{
   Sphere a;
   std::cout << a.density << std::endl;
   return 0;
}

float Sphere :: calculateVolume(bool add)
{
   float vol = 4.0 / 3.0 * M_PI * pow(radius, 3.0);
   volumeTotal += vol;
   return vol;
}
