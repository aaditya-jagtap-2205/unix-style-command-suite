#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	for(int i = 0; i < 2; i++)
	{
		if(argv[i] == NULL){
			printf("err: insufficient command line arguments\n");
			printf("use: unlink <FILE_NAME>\n");
			exit(0);
		}
		if(argc > 2){
			printf("err: too many command line arguments\n");
			exit(0);
		}
	}
	int iRet = 0;

	if(unlink(argv[1]) < 0){
		perror("err");
		exit(0);
	}
	printf("Deleted: `%s`\n", argv[1]);
}
