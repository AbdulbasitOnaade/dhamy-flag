#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - a custom implementation of printf that handles c, s, %, d, and i conversion specifiers
 *
 * @format: the format string
 * @...: the variable arguments
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c, *s;
	int d;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					while (*s != '\0')
					{
						putchar(*s);
						s++;
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					d = va_arg(args, int);
					printf("%d", d);
					count += snprintf(NULL, 0, "%d", d);
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
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

