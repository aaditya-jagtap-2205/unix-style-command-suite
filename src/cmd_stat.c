#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	for(int i = 0; i < 2; i++)
	{
		if(argv[i] == NULL){
			printf("err: insufficient command line arguments\n");
			printf("use: stat <FILE_NAME>\n");
			exit(0);
		}
		if(argc > 2){
			printf("err: too many command line arguments\n");
			exit(0);
		}
	}
	struct stat s_obj;
	
	if(stat(argv[1], &s_obj) < 0)
	{
		perror("err: no such file or directory\n");
		exit(0);
	}

	printf("File         : %s\n", argv[1]);
	printf("Inode Number : %ld\n", s_obj.st_ino);
	printf("Link Count   : %ld\n", s_obj.st_nlink);
	printf("File Size    : %ld\n", s_obj.st_size);

	return 0;
}
