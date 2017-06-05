
#include"output.h"


#define PRENDIDO "1"
#define APAGADO "0"


void imprimir_instrucciones(void)
{
	printf("Este programa es una simulacion de un puerto de 8 bits\n");
	printf("en el cual cada bit representa un LED.\n");
	printf(" Cada LED puede tener dos estado posibles, apagado (0),\n");
	printf("o prendido (1).\n");
	printf("Se permite elegir entre las siguientes opciones por teclado:\n");
	printf("-Un numero del 0 al 7 que representa el LED que desea prender\n");
	printf("-La letra 'b' para que todos los LED parpadien.\n");
	printf("-La letra 'c' para apagar todos los LED.\n");
	printf("-La letra 's' para prender todos los LED\n");
	printf("-La tecla Esc para terminar el programa.\n");
}


void imprimir_presionar_tecla(void)
{
	printf("\nPor favor ingresar una tecla...\n");

}

void imprimir_formato_equivocado(void)
{
	printf("\nEl formato ingresado es invalido, recuerde que las\n");
	printf("entradas permitidas son 'b', 'c', 's', Esc o un\n");
	printf("numero del 0 al 7.\n");
	printf("Por favor ingresar nuevamente una opcion.\n");
}


void imprimir_estado_del_puerto(void* p_port, pin_t leds[NUMERO_DE_LEDS])
{
	int i;
	printf("\nEstado del puerto:\n ");
	char mascara= 0X80; //mascara con solo el bit7 prendido.
	char port= *((char*)p_port);

	for(i=0; i<=BIT7; i++) //imprime la representacion en binario del puerto.
	{
		if(port&mascara)
		{
			printf(PRENDIDO);
			set_pin_value(leds[7-i].value,PRENDIDO);
			
		}
		else
		{
			printf(APAGADO);
			set_pin_value(leds[7-i].value,APAGADO);
		}
		port<<=1;
		
	}
	printf("\n");
	
}











