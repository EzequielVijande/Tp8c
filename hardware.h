

#ifndef HARDWARE_H
#define HARDWARE_H

#include<stdio.h>

//CONSTANTES
#define VALID 1
#define INVALID -1
#define NUMERO_DE_LEDS 8

//LEDS
#define LED0 "4"
#define LED1 "17"
#define LED2 "18"
#define LED3 "22"
#define LED4 "23"
#define LED5 "24"
#define LED6 "25"
#define LED7 "27"

typedef struct
{
	char* num_pin;
	char* value;
	char* output;

}pin_t;

int export_pins(pin_t leds[NUMERO_DE_LEDS]);
//Funcion que recibe un arreglo con los pins y los exporta a todos.
//si hubo un error devuelve un codigo para indicarlo.

int set_ouput(pin_t leds[NUMERO_DE_LEDS]);
//Funcion que recibe un arreglo con lo pins y les da la direccion de output

int set_pin_value(char*,char*);
//Funcion que recibe que pin se desea modificar y si se desea prender o apagar.

int unexport_pins(pin_t leds[NUMERO_DE_LEDS]);
//Funcion que recibe un arregle con los pins y los devuelve al kernel.









#endif //HARDWARE_H
