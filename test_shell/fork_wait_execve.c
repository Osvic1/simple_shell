#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int i;

	for (i = 0; i < 5; i++)
       	{
	// Create a child process
		int pid = fork();
		if (pid == 0)
	       	{
	   	 // This is the child process
	  	 // Execute the `ls -l /tmp` command
	      		 execl("/bin/ls", "ls", "-l", "/tmp", NULL);
		}
		else
		{
		// This is the parent process
		// Wait for the child process to exit
			waitpid(pid, NULL, 0);
		}
	}
	return 0;
}

