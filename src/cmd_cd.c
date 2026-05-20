#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * NOTE: The directory is changed only for the current calling process
 * and the parent process(shell) does not have any relations with changing
 * the directory of the parent process
 */

int main(int argc, char *argv[])
{
	for(int i = 0; i < 2; i++)
	{
		if(argv[i] == NULL){
			printf("err: insufficient command line arguments\n");
			printf("use: cd <DIR_NAME>\n");
			exit(0);
		}
		if(argc > 2){
			printf("err: too many command line arguments\n");
			exit(0);
		}
	}
	if(chdir(argv[1]) < 0){
		perror("err: directory does not exists\n");
		exit(0);
	}
	return 0;
}
