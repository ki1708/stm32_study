/*
 * ap.c
 *
 *  Created on: Aug 2, 2024
 *      Author: ki1708
 */

#include "ap.h"

static void infoCli(uint8_t argc , const char **argv);



void apInit (void)
{
  cliInit ();
  adcInit ();
  uartInit ();

  cliAdd("info", infoCli);
}

void apMain (void)
{
  uint32_t pre_time;
  pre_time = millis ();

  while (1)
    {
      if (millis () - pre_time >= 500)
	{
	  pre_time = millis ();
	  HAL_GPIO_TogglePin (LD3_GPIO_Port, LD3_Pin);
	}

      cliMain();
    }
}


void infoCli(uint8_t argc , const char **argv)
{
  bool ret = false ;

  if(argc == 1 && strcmp(argv[0],"test") == 0 )
    {
      cliPrintf("infoCli run\n"); // 인자까지 정상이면 정상작동
      ret = true ;
    }


  if (ret == false)
    {
      cliPrintf("write -> info test\n");
    }
}







