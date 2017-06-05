//Modulo que se encarga de todo lo que el programa imprime.

#ifndef OUTPUT_H
#define OUTPUT_H

#include<stdio.h>
#include"const.h"
#include"hardware.h"

void imprimir_instrucciones(void);
//Imprime en pantalla como funciona el programa

void imprimir_formato_equivocado(void);
//Avisa en pantalla que se ingreso un formato invalido y
//que este debe ser ingresado nuevamente.

void imprimir_presionar_tecla(void);
//Imprime que se esta esperando el ingreso de una tecla.

void imprimir_estado_del_puerto(void*, pin_t leds[NUMERO_DE_LEDS]);
//Imprime en pantalla como se encuentra el puerto de 8 bits.



#endif //OUTPUT_H
