#include "monty.h"

bus_t *arguments = NULL;

/**
* main - monty code interpreter
* @argc: The number of command line arguments
* @argv: A pointer to an array containing CLA
* @arguments: arguments taken
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	size_t n = 0;


	arguments_validation(argc);
	arguments_init();
	get_file(argv[1]);

	while (getline(&arguments->comment, &n, arguments->file) != -1)
	{
		arguments->line_number += 1;
		to_tokenize_comment();
		to_get_instruction();
		to_run_instruction();
		to_free_tokens();
	}

	close_file();
	free_arguments();


	return (0);
}
