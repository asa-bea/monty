#include "monty.h"

/**
  * arguments_validation - this check the number of CLA
  * @argc: The number of CLA
  * return: 0 on success
  */

void arguments_validation(int argc)
{
	if (argc == 2)
		return;

	dprintf(2,
