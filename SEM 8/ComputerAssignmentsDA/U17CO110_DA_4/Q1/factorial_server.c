/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "factorial.h"

int *factorial_1_svc(int *argp, struct svc_req *rqstp)
{
	static int result = 1;
	int i = 1, temp = 1;
	for (i = 1; i <= *argp; i++)
		temp = temp * i;
	printf("Factorial(%d)is called\n", i - 1);
	result = temp;
	return &result;
}