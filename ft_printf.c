/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhodos-s <jhodos-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:39:41 by jhodos-s          #+#    #+#             */
/*   Updated: 2025/07/12 19:00:42 by jhodos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(char fs, va_list args)
{
	int	count;

	count = 0;
	if (fs == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (fs == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (fs == 'd' || fs == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (fs == 'u')
		count += ft_putuint(va_arg(args, unsigned int));
	else if (fs == '%')
		count += ft_putchar('%');
	else if (fs == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (fs == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (fs == 'p')
		count += ft_putptr(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			count += ft_specifier(*(++format), args);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
/*
int	main()
{
	unsigned int	teste2 = -4;  
	int	teste = -42;
	int x = 42;
	int *ptr = &x;
	void *null_ptr = NULL;
	char *str = NULL;
	int pt;
	int ft;



	pt = 0;
	ft = 0;
	ft = ft_printf("MY INT_MAX %d. INT_MIN %d\n", INT_MAX, INT_MIN);
	pt = printf("OR INT_MAX %d. INT_MIN %d\n", INT_MAX, INT_MIN);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	ft = ft_printf("MY INT_MAX %i. INT_MIN %i\n", INT_MAX, INT_MIN);
	pt = printf("OR INT_MAX %i. INT_MIN %i\n", INT_MAX, INT_MIN);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	ft = ft_printf("MY INT_MAX %u. INT_MIN %u\n", INT_MAX, INT_MIN);
	pt = printf("OR INT_MAX %u. INT_MIN %u\n", INT_MAX, INT_MIN);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR char c %c\n", 65);
	ft = ft_printf("MY char c %c\n", 65);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR str s %s\n", "string");
	ft = ft_printf("MY str s %s\n", "string");
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR NULL str s %s\n", str);
	ft = ft_printf("MY NULL str s %s\n", str);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR nbr d %d\n", teste);
	ft = ft_printf("MY nbr d %d\n", teste);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR nbr i %i\n", teste);
	ft = ft_printf("MY nbr i %i\n", teste);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR INT_MIN nbr i %i\n", INT_MIN);
	ft = ft_printf("MY INT_MIN nbr i %i\n", INT_MIN);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR uint_max %u\n", teste2);
	ft = ft_printf("MY uint_max %u\n", teste2);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR %%\n");
	ft = ft_printf("MY %%\n");
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR p %p\n", ptr);
	ft = ft_printf("MY p %p\n", ptr);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("OR Endereco NULL: %p\n", null_ptr);
	ft = ft_printf("MY Endereco NULL: %p\n", null_ptr);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("Hexadecimal minusculo: %x\n", x);
	ft = ft_printf("Hexadecimal minusculo: %x\n", x);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("Hexadecimal maiusculo: %X\n", x);
	ft = ft_printf("Hexadecimal maiusculo: %X\n", x);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("Zero: %x\n", 0);
	ft = ft_printf("Zero: %x\n", 0);
	ft_printf("OR = %d MY = %d\n", pt, ft);
	ft_printf("\n");

	pt = printf("Max unsigned int: %x\n", 4294967295u);
	ft = ft_printf("Max unsigned int: %x\n", 4294967295u);
	ft_printf("OR = %d MY = %d\n", pt, ft);

	return (0);
}
*/
