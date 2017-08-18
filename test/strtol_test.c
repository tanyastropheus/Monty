#include "monty.h"

int main(int ac, char *av)
{
	const char *s;
	char *end;
	long int num;

	(void)(ac);
	num = strtol(av[1], &end, 10);
	if (*end)
		printf("not convertable to a number");
	else
		printf("number: %ld\n", num);
}
