#ifndef CILINDER_H_
#define CILINDER_H_

typedef struct Cilinder Cilinder;

Cilinder *Cilinder_Create(double radius, double height);
void Cilinder_Destroy(Cilinder *cilinder);

double Cilinder_Get_Height(const Cilinder *cilinder);
double Cilinder_Get_Radius(const Cilinder *cilinder);

double Cilinder_Get_Area(const Cilinder *cilinder);
double Cilinder_Get_Volume(const Cilinder *cilinder);

#endif /* CILINDER_H_ */
