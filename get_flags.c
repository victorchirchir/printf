#include "main.h"

/**
 * get_f - caluclates active flags
 * @format:formatted string
 * @i:parameter passed
 * Return:flags
 */
int get_f(const char *format, int *i)
{
	int j, k, f = 0;
	const char FLAGS_C[] = {'-', '+', '0'. '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; FLAGS_C[j] != '\0'; j++)
		{
			if (format[k] == FLAGS_C[j])
			{
				f |= FLAGS_ARR[j];
				break;
			}
		}
		if (FLAGS_C[j] == 0)
		{
			break;
		}
	}
	*i = k - 1;
	return (f);
}
