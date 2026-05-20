#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

void display_permission(mode_t m)
{
	char arr[11] = "-----------";

	if(S_ISDIR(m)) arr[0] = 'd';
	if(S_ISLNK(m)) arr[0] = 'l';

	/* Regular file permissions */
	if(m & S_IRUSR) arr[1] = 'r';
	if(m & S_IWUSR) arr[2] = 'w';
	if(m & S_IXUSR) arr[3] = 'x';

	if(m & S_IRGRP) arr[4] = 'r';
	if(m & S_IWGRP) arr[5] = 'w';
	if(m & S_IXGRP) arr[6] = 'x';

	if(m & S_IROTH) arr[7] = 'r';
	if(m & S_IWOTH) arr[8] = 'w';
	if(m & S_IXOTH) arr[9] = 'x';

	arr[10] = '\0';

	printf("File Permission : %s\n", arr);

}

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
	display_permission(s_obj.st_mode);

	return 0;
}
