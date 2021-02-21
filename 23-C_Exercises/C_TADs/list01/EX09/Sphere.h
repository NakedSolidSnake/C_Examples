#ifndef SPHERE_H_
#define SPHERE_H_

typedef struct Sphere Sphere;

Sphere *Sphere_Create(double radius);
void Sphere_Destroy(Sphere *sphere);

double Sphere_Get_Radius(const Sphere *sphere);
double Sphere_Get_Area(const Sphere *sphere);
double Sphere_Get_Volume(const Sphere *sphere);

#endif /* SPHERE_H_ */
