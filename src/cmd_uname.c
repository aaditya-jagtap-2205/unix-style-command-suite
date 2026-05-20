#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

#define MAX_BUFF_SIZE 1024

int main()
{
	struct utsname obj;

	if(uname(&obj) < 0){
		perror("err: unable to fetch system information\n");
		return -1;
	}
	
	printf("System Name: %s\n", obj.sysname);
	printf("Node Name  : %s\n", obj.nodename);
	printf("Release    : %s\n", obj.release);
	printf("Version    : %s\n", obj.version);

	return 0;
}
