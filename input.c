#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	pid = fork();
	printf("Before\n");

	if (pid == -1)
		return (-1);

	if (pid == 0)
	{
		while (1)
		{
			int val = execve(argv[0], argv, NULL);
			if (val == -1)
				perror("Error");
		}
	}
	else
	{
		printf("Done\n");
	}
	return (0);
}
