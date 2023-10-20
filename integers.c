#include <stdlib.h>

char *read_int(int num);
unsigned int absl_val(int);
int buff_len(unsigned int num, unsigned int base);
void corr_buff_val(unsigned int num, unsigned int base,
		       char *buff, int buff_size);

/**
 * read_int - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *read_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = absl_val(num);
	length = buff_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	corr_buff_val(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * absl_val - gets the absolute value of an integer
 * @i: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int absl_val(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * buff_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int buff_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * corr_buff_val - fills buffer with correct numbers up to base 36
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void corr_buff_val(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}