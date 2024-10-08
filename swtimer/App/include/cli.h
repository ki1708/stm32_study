/*
 * cli.h
 *
 *  Created on: Aug 25, 2024
 *      Author: ki1708
 */

#ifndef INCLUDE_CLI_H_
#define INCLUDE_CLI_H_

#include "def.h"

bool cliInit (void);
bool cliMain (void);
bool cliAdd (const char *cmd_str,
	     void (*cmd_func) (uint8_t argc, const char **argv));
void cliPrintf(const char *fmt, ...);
bool cliIsStr (const char *p_arg, const char *p_str);
int32_t cliGetData (const char *p_arg);
bool cliKeepLoop(void);

#endif /* INCLUDE_CLI_H_ */
