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

  if(argc == 1 && cliIsStr(argv[0],"test"))
    {
      cliPrintf("infoCli run\n"); // 인자까지 정상이면 정상작동
      ret = true ;
    }


  if(argc == 2  && cliIsStr (argv[0], "print"))
    {
      uint8_t count ;
      count = (uint8_t)cliGetData(argv[1]);
      for(int i = 0 ; i < count ; i++)
	{
	  cliPrintf("print %d / %d\n " , i +1 , count);
	}

      ret = true;
    }

  if(argc == 1 && cliIsStr(argv[0], "adc"))
    {
      uint32_t data ;
      while(cliKeepLoop())
	{
	      data = adcReadVoltage(_DEF_CH1);
	      cliPrintf("adc_voltage : %d\n",data );
	      delay(100);
	}
      ret = true;
    }






  if (ret == false)
    {
      cliPrintf("write -> info test\n");
      cliPrintf("write -> info print 0~10\n");
      cliPrintf("write -> info adc\n");
    }
}







