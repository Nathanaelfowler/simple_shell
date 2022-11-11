#include "main.h"

/**
 * main - create a super simple shell
 * @argc: argument count
 * @argv: argument vectors
 * Return: 0 on success
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char *buffer, *check_exit = "exit";
	char **argvec;
	size_t buffer_size = 10;
	int i, number_of_words = 1, value;
	pid_t pid;

	buffer = malloc(sizeof(char) * buffer_size);
	if (buffer == NULL)
		exit(1);
	printf("$ ");
	/*Use getline to accept commmands*/
	while (getline(&buffer, &buffer_size, stdin) != -1)
	{
		buffer[strcspn(buffer, "\n")] = 0;
		if (strcmp(buffer, check_exit) == 0)
			return (0);
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			/*Use strtok to split the buffer with space as separator*/
			for (i = 0; i < (int)strlen(buffer); i++)
			{
				if (buffer[i] == ' ')
				number_of_words++;
			}
			argvec = split_string(buffer, number_of_words);
			/*Run execve on the command*/
			value = execvp(argvec[0], argvec);
			if (value == -1)
				perror(argv[0]);
		}
		else
		{
			wait(NULL);
			printf("$ ");
		}
	}
	return (0);
}

/**
 * split_string - split a string with strtok
 * @string: the string to be divided
 * @word_number: the number of words in the string
 * Return: an array of the individual words in the string
 */
char **split_string(char *string, int word_number)
{
	/*create divided_string variable*/
	char **divided_string;
	char *splits;
	char *sep;
	int i = 0;

	/*create token variable*/
	divided_string = malloc(sizeof(char *) * word_number);
	if (divided_string == NULL)
		exit(1);
	sep = " ";
	/*use strtok to get first token*/
	splits = strtok(string, sep);
	/*while token isn't equal to NULL*/
	while (splits != NULL)
	{
		/*assign divided string array to token*/
		divided_string[i] = splits;
		/*strtok(NULL)*/
		splits = strtok(NULL, sep);
		i++;
	}
	/*return array*/
	return (divided_string);
}
