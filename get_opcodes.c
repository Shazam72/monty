#include "monty.h"

/**
 * get_opcodes - get right opcode function
 * @opc: provided opcode
 * Return: right function ptr else NULL
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i = 0;

	for (; op_funcs[i].opcode; i++)
		if (_strcmp(op_funcs[i].opcode, opc) == 0)
			break;
	return (op_funcs[i].f);
}
