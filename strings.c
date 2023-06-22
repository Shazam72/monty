#include "monty.h"
/**
 * _strcmp - compares two strings
 * @s1: first operand
 * @s2: second operand
 * Return: 0 if s1 = s2
 *         else 1 if s1 > s2
 *         else -1 if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _sch - search for a char inside a provided string
 * @s: string to search in
 * @c: char to search for
 * Return: 1 if founded else 0
 */
int _sch(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strtoky - tokenize a string based on a delimiter
 * @s: string to tokenize
 * @d: delimiter
 * Return: left part of the string with delimiter as divider
 */
char *_strtoky(char *s, char *d)
{
	static char *final;
	int i = 0, j = 0;

	if (!s)
		s = final;
	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			final = s + i + 1;
			*final = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			final = s + i + 1;
			*final = '\0';
			final++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
