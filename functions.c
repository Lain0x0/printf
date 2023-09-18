#include <stdarg.h>
#include <stdio.h>
/**
 * main - entry point
 *
 * _printf: to prints a data types
 *
 * Return: Always 0 (SUCCESS)
 *
*/
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')

			{
				break;
			}

			else if (*format == 'c')
			{
				int c = va_arg(args, int);
				putchar(c);
				count++;
			}

			else if (*format == 's')

			{
				char *s = va_arg(args, char *);
				if (s)

				{
					while (*s)

					{
						putchar(*s);
						s++;
						count++;
					}
				}

			}

			else if (*format == '%')

			{
				putchar('%');
				count++;
			}

			else

			{
				putchar('%');

				putchar(*format);

				count += 2;
			}
		}

		else

		{
			putchar(*format);

			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}

int main(void)
{
_printf("Hello, %s! The answer is %d%c\n", "world", 42, '%');

return (0);
}
