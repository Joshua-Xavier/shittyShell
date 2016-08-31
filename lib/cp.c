/*
START DATE: 23/08/16
LAST MODIFIED: 31/08/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void cpCLI(char arg[256]){
	char cmdarg[300];
	int twoArgReti = validateTwoArgs(arg);

	if (!twoArgReti){
		strcpy(cmdarg, "cp ");
		strcat(cmdarg, arg);
		system(cmdarg);
	} else {
		printf("Invalid use of cp\nUsage: cp <old> <new>\n");
	}

}
