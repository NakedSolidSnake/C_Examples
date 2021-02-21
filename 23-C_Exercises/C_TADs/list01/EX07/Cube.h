#ifndef CUBE_H_
#define CUBE_H_

typedef struct Cube Cube;

Cube *Cube_Create(double side);
void Cube_Destroy(Cube *cube);

double Cube_Get_Side(const Cube *cube);
double Cube_Get_Area(const Cube *cube);
double Cube_Get_Volume(const Cube *cube);

#endif /* CUBE_H_ */
