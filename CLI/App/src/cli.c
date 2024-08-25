/*
 * cli.c
 *
 *  Created on: Aug 25, 2024
 *      Author: ki1708
 */

#include "cli.h"
#include "uart.h"

typedef struct
{
  char cmd_str[8]; // 7글자까지 되는 명령어 버퍼를 정의

  // void cmd_func(uint8_t argc, const char **argv); 내가 가져다쓸 함수 원형
  void (*cmd_func) (uint8_t argc, const char **argv); //함수포인터로 변환 하는방법
} cli_cmd_t;

#define CLI_CMD_LIST_MAX 8

static const uint8_t cli_ch = _DEF_CH1;

static char cli_buf[128];
static uint16_t cli_buf_index = 0;

static uint16_t cli_argc = 0;
static char *cli_argv[8]; // cli 인자 포인터 배열

static uint8_t cli_cmd_count = 0;
static cli_cmd_t cli_cmd_func[CLI_CMD_LIST_MAX];

static void cliHelp(uint8_t argc, const char **argv);




bool cliInit (void)
{
  for (int i = 0; i < CLI_CMD_LIST_MAX; i++)
    {
      cli_cmd_func[i].cmd_func = NULL;
    }

  cliAdd("help" , cliHelp);
  return true;
}

bool cliAdd (const char *cmd_str,
	     void (*cmd_func) (uint8_t argc, const char **argv))
{
  if (cli_cmd_count >= CLI_CMD_LIST_MAX)
    return false;

  strncpy (cli_cmd_func[cli_cmd_count].cmd_str, cmd_str, 8);
  cli_cmd_func[cli_cmd_count].cmd_func = cmd_func; // 함수포인터 세팅
  cli_cmd_count++;

  return true;
}

void cliHelp(uint8_t argc, const char **argv)
{
  cliPrintf("----------------------\n");

  for(int i= 0; i<cli_cmd_count; i++)
    {
      cliPrintf("%s\n", cli_cmd_func[i].cmd_str);
    }
  cliPrintf("----------------------\n");
}



void cliPrintf (const char *fmt, ...)
{
  va_list arg;

  va_start(arg, fmt);
  uartVPrintf (cli_ch, fmt, arg);
  va_end(arg);
}

bool cliMain (void)
{
  bool ret = false;
  if (uartAvailable (cli_ch) > 0)
    {
      uint8_t rx_data;
      rx_data = uartRead (cli_ch);
      //uartPrintf(_DEF_CH1, "rx_data : %c \n ",rx_data ); // 프롬프트라고 알리는 출력

      if (rx_data == '\r')
	{
	  cli_buf[cli_buf_index] = 0; // CLI 라인마지막 'r'다음 null값을 주기
	  cli_buf_index = 0;
	  uartPrintf (cli_ch, "\r\n"); // 터미널쪽에 줄바꿈
	  //RUN CMD

	  char *tok;
	  char *str_ptr = cli_buf;
	  cli_argc = 0;

	  while ((tok = strtok_r (str_ptr, " ", &str_ptr)) != NULL)
	    {
	      cli_argv[cli_argc] = tok;
	      cli_argc++;
	    }

	  for (int i = 0; i < cli_cmd_count; i++)
	    {
	      if (strcmp (cli_argv[0], cli_cmd_func[i].cmd_str) == 0)
		{
		  if (cli_cmd_func[i].cmd_func != NULL)
		    {
		      cli_cmd_func[i].cmd_func (cli_argc - 1,
						(const char**) &cli_argv[1]);
		      ret = true;
		      break;
		    }
		}
	    }

//	  if (cli_argc > 0)
//	    {
//	      if (cli_argc == 2 && strcmp (cli_argv[0], "test") == 0)
//		{
//		  int32_t test_data;
//		  test_data = (int32_t) strtoul (cli_argv[1], (char**) NULL, 0);
//		  uartPrintf (cli_ch, "test_data : %d\n", test_data);
//		}
//	    }
//
//
//

	  uartPrintf (cli_ch, "cli# "); // 프롬프트라고 알리는 출력
	}
      else if (cli_buf_index < (128 - 1)) // 버퍼 경계처리 128은 버퍼크기 , -1은 null값 고려
	{
	  cli_buf[cli_buf_index] = rx_data;
	  cli_buf_index++;
	  uartWrite (cli_ch, &rx_data, 1); // 에코
	}

    }

  return ret;
}

