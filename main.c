#include<fcntl.h>
#include<stdio.h>
#include"get_next_line.h"

int main(int ac, char *av[])
{
	int fd = open (av[1], O_RDONLY);
	char *str;
	(void)ac;
	while ((str = get_next_line(fd))){
		printf("%s", str);
		free(str);
	}
	close (fd);
}
