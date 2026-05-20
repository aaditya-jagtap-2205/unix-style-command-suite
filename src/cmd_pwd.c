#include <stdio.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024

int main()
{
	char buff[MAX_BUFF_SIZE];

	/* sizeof(buff) - 1 because we need to skip '\0' */
	printf("Current directory: %s\n", getcwd(buff, sizeof(buff) - 1));

	return 0;
}
