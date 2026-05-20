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
			printf("use: cat <FILE_NAME>\n");
			exit(0);
		}
		if(argc > 2){
			perror("err: too many command line arguments\n");
			exit(0);
		}
	}

	int fd = 0;
	char buff[1024];

	memset(buff, '\0', sizeof(buff));

	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		perror("err: no such file or directory\n");
		exit(0);
	}

	if(read(fd, buff, sizeof(buff)) > 0)
	{
		printf("%s", buff);
	}

	close(fd);
	
	return 0;
}
