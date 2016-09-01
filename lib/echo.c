/*
START DATE: 23/08/16
LAST MODIFIED: 31/08/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION:
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "validation.c"

void echo(char arg[256]){
	char cmdarg[300];
	int echoReti = validateQuoteArg(arg);
	int pid;
	//echo broken currently, no validating properly
	pid = fork();
	if(pid == 0){
		if(!echoReti){
			execlp("/bin/echo", "echo", arg, NULL);
		} else {
			printf("Invalid use of echo\nUsage: echo \"<comment>\"\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}
}
