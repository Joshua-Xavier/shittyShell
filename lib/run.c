/*
START DATE: 25/08/16
LAST MODIFIED: 31/08/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void run(char arg[256]){
	char cmdarg[300];
	int oneArgReti = validateOneArg(arg);

	if (!oneArgReti){
		strcpy(cmdarg, "./");
		strcat(cmdarg, arg);
		system(cmdarg);
	} else {
		printf("Invalid use of run\nUsage: run <program>\n");
	}
}
