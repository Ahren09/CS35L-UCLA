#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h> //header files needed for open, read, write

#define BUFFERSIZE 1024
char buffer[BUFFERSIZE];

int main(void)
{
	int src_fd = 0, des_fd = 1, ret = 0;

	while ((ret = read(src_fd, buffer, BUFFERSIZE)) > 0)
	{
		ret = write(des_fd, buffer, ret);
		if (ret < 0) break;
	}

	if (ret < 0)
	{
		fprintf(stderr, "read or write error\n");
		return -1;
	}

	return 0;	
}
