/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:04:28 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/15 16:00:23 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Counts the number of %, hence the number of arguments
// Prints string until % is encountered
// Call the approriate funciton to print the argument
// Keep track of the number of printed characters
// And voilà! 

#include "ft_printf.h"

int	get_arg_nb(const char *str)
{
	int		i;
	int		j;
	int		arg_nb;
	char	*converter;

	i = 0;
	arg_nb = 0;
	converter = "cspdiuxX";
	while (str[i])
	{
		j = 0;
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				i++;
			else
				while (converter[j])
					if (str[i + 1] == converter[j++])
						arg_nb++;
		}
		i++;
	}
	return (arg_nb);
}

int	n_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_fd_u(unsigned int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd('0' + n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
}

int	n_len_u(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		arg_nb;
	int		len;
	int		i;
	char	*s;
	int		d;
	unsigned int	u;
	int		x;

	arg_nb = get_arg_nb(format);
	len = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				ft_putchar_fd(va_arg(args, int), 1);
				len++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				s = va_arg(args, char *);
				ft_putstr_fd(s, 1);
				len += ft_strlen(s);
				i++;
			}
			else if (format[i + 1] == 'p')
			{
				// stuff
			}
			else if (format[i + 1] == 'd')
			{
				d = va_arg(args, int);
				ft_putnbr_fd(d, 1);
				len += n_len(d);
				i++;
			}
			else if (format[i + 1] == 'i')
			{
				d = va_arg(args, int);
				ft_putnbr_fd(d, 1);
				len += n_len(d);
				i++;
			}
			else if (format[i + 1] == 'u')
			{
				u = va_arg(args, int);
				ft_putnbr_fd_u(u, 1);
				len += n_len_u(u);
				i++;
			}
			else if (format[i + 1] == 'x')
			{
				x = va_arg(args, int);
			}
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
