#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <apue.h>

char buf1[]="abcdefghijk";
char buf2[]="ABCDEFGHIJK";

int main(int argc,char *argv[])
{
	int fd;
	if((fd=creat("file.hole",FILE_MODE))<0)
	{
		err_sys("creat error");
	}

	if (write(fd, buf1, 11)!=11)
	{
		/* code */
		err_sys("buf1 write error");
	}

	if (lseek(fd, 40, SEEK_SET)==-1)
	{
		/* code */
		err_sys("lseek error");
	}

	if (write(fd, buf2, 11)!=11)
	{
		/* code */
		err_sys("buf2 write error");
	}

	exit(0);
}