#include"input.h"



char get_input(void);
//funcion que busca el caracter ingresado por el input
//y devuelve cual es dicho caracter.

int validacion_input(char);
//recibe el caracter ingresado por input y se fija
//si la misma es un a tecla de ingreso valida.



char get_input(void)
{
	char c=0;
    nonblock(NB_ENABLE);
    while(!c)
    {
        
        c=kbhit();
        if (c!=0)
        {
            c=fgetc(stdin);
        }
    }
    nonblock(NB_DISABLE);

	return c;

}

int validacion_input(char caracter)
{
	if( (caracter>='0')&&(caracter<='7') )
	{
		return VALIDO;	
	}
	else if( (caracter==TERMINAR)||(caracter==APAGAR)||(caracter==PRENDER)||(caracter==PARPADEAR) )
	{
		return VALIDO;
	}
	else
	{
		return INVALIDO;
	}


}


