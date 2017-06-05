#include<stdio.h>
#include"hardware.h"








int export_pins(pin_t leds[NUMERO_DE_LEDS])
{
	FILE *export_handler;
	int valid= VALID;
	int i;

	for(i=0; (i<NUMERO_DE_LEDS)&&(valid!=INVALID);i++)
	{
		if( (export_handler= fopen("/sys/class/gpio/export","w"))==NULL )
		{
			valid=INVALID;
		}
		if( (fputs(leds[i].num_pin,export_handler))==INVALID)
		{
			valid=INVALID;
		}
		fclose(export_handler);

	}

	return valid;

}

int set_ouput(pin_t leds[NUMERO_DE_LEDS])
{
	FILE *direction_handler;
	int valid= VALID;
	int i;
	for(i=0; (i<NUMERO_DE_LEDS)&&(valid!=INVALID);i++)
	{
		if( (direction_handler= fopen(leds[i].output, "w"))== NULL )
		{
			valid=INVALID;
		}

		if( (fputs("out",direction_handler))==INVALID )
		{
			valid=INVALID;
		}
		
		fclose(direction_handler);
	}

	return valid;
}

int set_pin_value(char*led,char* value)
{
	FILE *value_handler;
	int valid= VALID;

	if( (value_handler= fopen(led, "w"))== NULL )
	{
		valid=INVALID;
	}
	if( (fputs(value, value_handler))== INVALID )
	{
		valid=INVALID;
	}
	fclose(value_handler);
	
	return valid;
}

int unexport_pins(pin_t leds[NUMERO_DE_LEDS])
{
	FILE * unexport_handler;
	int valid= VALID;
	int i;

	for(i=0; (i<NUMERO_DE_LEDS)&&(valid!=INVALID);i++)
	{
		if( (unexport_handler= fopen("/sys/class/gpio/unexport","w"))==NULL )
		{
			valid=INVALID;
		}
		if( (fputs(leds[i].num_pin,unexport_handler))==INVALID)
		{
			valid=INVALID;
		}
		fclose(unexport_handler);

	}

	return valid;


}







