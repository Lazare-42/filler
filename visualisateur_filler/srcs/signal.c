#include <signal.h>
#include "../includes/filler.h"

/*
void (*signal(int sig, void(*func)(int)))(int)
{

}
*/

void	sig_handler(int i)
{
	printf("%d\n", i);
}

int  main()
{
	for (int i = 1; i <= 31 ; i++)
	{
		signal(i, sig_handler);
	}
	while (1)
	{
	}
}
