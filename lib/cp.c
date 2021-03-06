/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: cp lets the user copy the contents from one file to another, if the
given newfile does not exist, it will create it.
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "validation.c"

void cpCLI(char arg[256]){
	char cmdarg[300];
	int twoArgReti = validateTwoArgs(arg);
	pid_t pid;
	char arg1[256];
	char arg2[256];

	pid = fork();
	if (pid == 0){
		if (!twoArgReti){
			strcpy(arg1, strsep(&arg, " "));
			strcpy(arg2, arg);
			execlp("/bin/cp", "cp", arg1, arg2, NULL);
		} else {
			printf("Invalid use of cp\nUsage: cp <old> <new>\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}
}
