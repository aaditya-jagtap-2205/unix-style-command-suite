#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
	for(int i = 0; i < 3; i++)
	{
		if(argv[i] == NULL){
			printf("err: insufficient command line arguments\n");
			printf("use: cp <SOURCE_FILE> <DEST_FILE>\n");
			exit(0);
		}
		if(argc > 3){
			printf("err: copy one file at a time\n");
			exit(0);
		}
	}

	int fd1 = 0, fd2 = 0, buff_len = 0;
	char buff[MAX_BUFFER_SIZE];

	memset(buff, '\0', sizeof(buff));

	/* Open source file */
	fd1 = open(argv[1], O_RDONLY);
	if(fd1 < 0){
		perror("err: no such file or directory\n");
		exit(0);
	}

	/* Read from source file */
	if(read(fd1, buff, sizeof(buff)) < 0){
		perror("err: unable to read source file\n");
		exit(0);
	}
	
	/* Calculate buffer length */
	buff_len = strlen(buff);

	/* Open destination file and create if does not exists already */
	fd2 = open(argv[2], O_WRONLY | O_CREAT, 0664);
	if(fd2 < 0){
		perror("err: unable to write into destination file\n");
		exit(0);
	}

	/* Write into destination file */
	if(write(fd2, buff, buff_len) > 0){
		printf("Succesfully copied %s file\n", argv[1]);
	}

	close(fd1);
	close(fd2);

	return 0;
}
