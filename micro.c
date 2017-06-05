
//Titulo: Micro
//
//Programa que simula un puerto de 8 bits, cada bit representa un LED.
//El programa permite ingresar por teclado si se desea prender todos
//los LED, apagar todos, que parpadien, o prender un solo LED.
//
//Fecha:24/05/17	Autores: Ariel Martorell, Carolin Diemer, Ezequiel Vijande, Juan Schinocca.



#include"output.h"
#include"input.h"
#include"const.h"
#include"bitmask.h"
#include"hardware.h"

void parpadear(void*, pin_t leds[NUMERO_DE_LEDS]);
//Funcion que hace parpadear a los LED del puerto A.


typedef struct  //definicion de un puerto de 16 bits 
{
	char porta;
	char portb;
	
}portd_t;








int main(void)
{
	int valido= VALIDO;
	char tecla;
	portd_t portd;

	
	pin_t leds[NUMERO_DE_LEDS]=
	{
		{LED0,"/sys/class/gpio/gpio4/value","/sys/class/gpio/gpio4/direction"}, //incializa el arreglo de pins
		{LED1,"/sys/class/gpio/gpio17/value","/sys/class/gpio/gpio17/direction"},
		{LED2,"/sys/class/gpio/gpio18/value","/sys/class/gpio/gpio18/direction"},
		{LED3,"/sys/class/gpio/gpio22/value","/sys/class/gpio/gpio22/direction"},
		{LED4,"/sys/class/gpio/gpio23/value","/sys/class/gpio/gpio23/direction"},
		{LED5,"/sys/class/gpio/gpio24/value","/sys/class/gpio/gpio24/direction"},
		{LED6,"/sys/class/gpio/gpio25/value","/sys/class/gpio/gpio25/direction"},
		{LED7,"/sys/class/gpio/gpio27/value","/sys/class/gpio/gpio27/direction"},
	};

		if( (export_pins(leds))==INVALID ) //se exportan todos los pins
		{
			return INVALID;	//si no se logro exportar los pins termina el programa.
		}

		if( (set_ouput(leds))==INVALID ) //pone la direccion de los pins como output
		{
			unexport_pins(leds); //devuelve los pins al kernel.
			return INVALID;
		}




	

	imprimir_instrucciones();

	while(valido)
	{
		imprimir_estado_del_puerto((void*) (&(portd.porta)), leds ); //imprime el estado del puerto A
		imprimir_presionar_tecla();
		tecla= get_input();
		valido= validacion_input(tecla);

		while(!valido) //si la tecla ingresada no es valida avisa en pantalla
						//y da la oportunidad de reingrsar otra tecla
		{
			imprimir_formato_equivocado();
			tecla= get_input();
			valido= validacion_input(tecla);
		}

		switch(tecla)
		{
			case PRENDER:
				mask_on((void*) (&(portd.porta)) , ON, PORTA);
				break;
		

			case APAGAR:
				mask_off((void*) (&(portd.porta)) , ON, PORTA );
				break;

			case PARPADEAR:
				parpadear( (void*)(&(portd.porta)), leds);

				break;

			case TERMINAR:
				valido=INVALIDO;

				break;
		
			default: 
				bitset( (void*)(&(portd.porta)), (int)(tecla-'0') ); //Prende el numero de bit ingresado.
		}
	}
	

	unexport_pins(leds); //devuelve los pins al kernel.
	return 0;
	
	
}

void parpadear(void* port, pin_t leds[NUMERO_DE_LEDS])
{
	int i;
	char* p_porta = (char*)port;
	for(i=0; i<TIEMPO_PARPADEANDO; i++)
		{
			*p_porta= ON;
			imprimir_estado_del_puerto((void*)p_porta, leds);
			sleep(UN_SEGUNDO);
			*p_porta= OFF;
			imprimir_estado_del_puerto((void*)p_porta, leds);
			sleep(UN_SEGUNDO);
		}

}




