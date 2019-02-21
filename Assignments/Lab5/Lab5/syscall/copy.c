#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h> //header files needed for open, read, write

#define BUFFERSIZE 1024
char buffer[BUFFERSIZE];

int main(int argc, char * argv[])
{
	int src_fd = 0, des_fd = 0, ret = 0;

	src_fd = open(argv[1], O_RDONLY);
	//new file permission: 640
	des_fd = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR |  S_IRGRP);


	while ((ret = read(src_fd, buffer, BUFFERSIZE)) > 0)
	{
		ret = write(des_fd, buffer, ret);
		if (ret < 0) break;
	}

	close(src_fd);
	close(des_fd);
	
	return 0;	
}
