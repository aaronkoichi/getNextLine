#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{


	int fd = open("test.txt", O_RDONLY);
	char *result1 = get_next_line(fd);
	char *result2 = get_next_line(fd);
	char *result3 = get_next_line(fd);

	printf("%s", result1);
	printf("%s", result2);
	printf("%s", result3);
	free(result1);
	free(result2);
}
