#include "monty.h"
#include "lists.h"

/**
 * empty_all - memory handler
 * @all: flag to indicate what to free
 */
void empty_all(int all)
{
	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		empty_everything(data.words);
		data.words = NULL;
	}

	if (all)
	{
		if (data.stack)
		{
			empty_dll(data.stack);
			data.stack = NULL;
		}
		if (data.fptr)
		{
			fclose(data.fptr);
			data.fptr = NULL;
		}
	}
}
