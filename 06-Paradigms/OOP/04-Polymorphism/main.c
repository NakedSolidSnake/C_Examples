#include <stdio.h>
#include <stdlib.h>

typedef void (*make_noise)(void);

typedef enum 
{
    ANIMAL_VACA,
    ANIMAL_CACHORRO,
    ANIMAL_GATO
}eAnimal;

// tipo genérico
typedef struct {
  eAnimal animal;
  const char *sound;    
} Animal;


void emit_sound(Animal *animal)
{
    printf("Animal : %d, sound %s\n", animal->animal, animal->sound);
}

int main(void) {

  Animal animals[] = 
  {
      {.animal = ANIMAL_VACA, .sound  = "muuu! muuu!"},
      {.animal = ANIMAL_CACHORRO, .sound = "au! au!"},
      {.animal = ANIMAL_GATO, .sound = "miau! miau!"}
  };


  for(int i = 0; i < 3; i++){
      emit_sound(&animals[i]);
  }

  return 0;
}
