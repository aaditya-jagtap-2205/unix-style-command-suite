#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("err: insufficient cmd args\n");
	}

	if(rename(argv[1], argv[2]) < 0){
		perror("err");
	}

	return 0;
}
