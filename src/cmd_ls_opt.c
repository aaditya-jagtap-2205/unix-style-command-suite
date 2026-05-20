#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024

void call_ls()
{
	DIR           *dp = NULL;
	struct dirent *ptr = NULL;
	struct stat s_obj;
	char dir_name[MAX_BUFFER_SIZE], fullpath[MAX_BUFFER_SIZE];

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


	}
	closedir(dp);
}

void call_ls_opt(const char *option)
{
	if(strcmp(option, "-i") == 0){
		DIR           *dp = NULL;
		struct dirent *ptr = NULL;
		struct stat s_obj;
		char dir_name[MAX_BUFFER_SIZE], fullpath[MAX_BUFFER_SIZE];

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

			if(stat(fullpath, &s_obj)){
				printf("%ld %s\n", s_obj.st_ino, ptr->d_name);
			}
		}
		closedir(dp);
	}
}

int main(int argc, char *argv[])
{
	for(int i = 0; i < argc; i++){
		if(argc == 1){
			call_ls();
		}
		if(argc == 2){
			call_ls_opt(argv[1]);
			exit(0);
		}
	}
	return 0;
}
