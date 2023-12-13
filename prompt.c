#include <shell.h>
#define MAX_INPUT_SIZE 1024

int main() 
{
	char input[MAX_INPUT_SIZE];
	char *args[2];
	int status;
	
	while (1) 
	{
		printf("simple_shell$ ");
		fflush(stdout);

		if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) 
		{
			printf("\n");
			break;
	       	}
		input[strcspn(input, "\n")] = '\0';
		if (strlen(input) == 0) 
		{
			continue;
		}
		args[0] = input;
		args[1] = NULL;
		pid_t pid = fork();
		if (pid < 0) 
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		} 
		else if (pid == 0) 
		{
			(execve(args[0], args, NULL) == -1) 
			{
				perror("Execution failed");
				exit(EXIT_FAILURE);
			}
		} else 
		{
			waitpid(pid, &status, 0);
		}
	}
	return EXIT_SUCCESS;
}
