/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:49:27 by afadlane          #+#    #+#             */
/*   Updated: 2022/12/28 17:41:46 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_hexalower(unsigned int n)
{
	unsigned int	a;
	unsigned int	r;
	int				i;

	a = n;
	i = 0;
	if (a == 0)
		i++;
	while (a != 0)
	{
		a = a / 16;
		i++;
	}
	if (n > 15)
		ft_hexalower(n / 16);
	r = n % 16;
	if (r >= 10 && r < 16)
		ft_putchar(r + 87);
	else
		ft_putchar(r + 48);
	return (i);
}

int	ft_hexaupper(unsigned int n)
{
	unsigned int	a;
	unsigned int	r;
	int				i;

	a = n;
	i = 0;
	if (a == 0)
		i++;
	while (a != 0)
	{
		a = a / 16;
		i++;
	}
	if (n > 15)
		ft_hexaupper(n / 16);
	r = n % 16;
	if (r >= 10 && r < 16)
		ft_putchar(r + 55);
	else
		ft_putchar(r + 48);
	return (i);
}

int	ft_ptr(unsigned long n)
{
	unsigned long	a;
	unsigned long	r;
	int				i;

	a = n;
	i = 0;
	if (a == 0)
	i++;
	while (a != 0)
	{
		a = a / 16;
		i++;
	}
	if (n > 15)
		ft_ptr(n / 16);
		r = n % 16;
	if (r >= 10 && r < 16)
		ft_putchar(r + 87);
	else
		ft_putchar(r + 48);
	return (i);
}

static int	ft_lenght(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(long n)
{
	int	len;

	len = ft_lenght(n);
	if (n < 0)
	{
		ft_putchar('-');
		n = -1 * n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (len);
}
