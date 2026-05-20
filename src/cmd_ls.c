#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
	DIR           *dp = NULL;
	struct dirent *ptr = NULL;
	struct stat s_obj;
	char dir_name[MAX_BUFFER_SIZE], file_path[MAX_BUFFER_SIZE];

	printf("Enter directory name: \n");
	fgets(dir_name, sizeof(dir_name), stdin);
	dir_name[strcspn(dir_name, "\n")] = 0;

	dp = opendir(dir_name);
	if(dp == NULL){
		perror("err: file or directory does not exits\n");
		exit(0);
	}

	while(ptr = readdir(dp))
	{
		/* Skip . and .. */
		if((strcmp(".", ptr->d_name) == 0) || (strcmp("..", ptr->d_name) == 0)){
			continue;
		}

		printf("%s\n", ptr->d_name);
	}
	closedir(dp);
	return 0;
}
