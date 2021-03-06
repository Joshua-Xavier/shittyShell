/*
START DATE: 23/08/16
LAST MODIFIED: 02/09/16
ARGS: arg - the argument string passed from the main program to validate against
DESCRIPTION: dir will show the contents of the given directory, you can use
relative paths with it and if no argument is given it will print the contents of
the current directory.
*/

#include <stdio.h>
#include <string.h>
#include "validation.c"

void dir(char arg[256]){
	char cmdarg[300];
	int nullArgReti = validateNoArgs(arg);
	int oneArgReti = validateOneArg(arg);
	pid_t pid;

	pid = fork();
	if(pid == 0){
		if (!oneArgReti){
			execlp("/bin/ls", "ls", arg, NULL);
		} else if (!nullArgReti) {
			execlp("/bin/ls", "ls", NULL);
		} else {
			printf("Invalid use of dir\nUsage: dir <OPTIONAL: directory>\n");
		}
		exit(0);
	} else {
		wait(NULL);
	}
}
