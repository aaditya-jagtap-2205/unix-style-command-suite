#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	for(int i = 0; i < 2; i++)
	{
		if(argv[i] == NULL){
			printf("err: insufficient command line arguments\n");
			printf("use: touch <FILE_NAME>\n");
			exit(0);
		}
		if(argc > 2){
			perror("err: too many command line arguments\n");
			exit(0);
		}
	}

	int fd = 0;
	
	fd = access(argv[1], O_RDONLY);
	if(fd < 0){
		if(creat(argv[1], 0664) < 0){
			perror("err: unable to create the file\n");
			exit(0);
		}
	}
	printf("Succesfully created `%s` file\n", argv[1]);

	return 0;
}
