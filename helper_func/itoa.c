/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:05:09 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/16 17:03:49 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (0);
}

static int	intlen(int n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*convert(char *s, int i, int n)
{
	int		num;

	num = n;
	if (get_sign(n) < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	if (n == 0)
	{
		s[i++] = 0 + '0';
		s[i] = '\0';
		return (s);
	}
	while (i > 0)
	{
		if (get_sign(num) == 0)
			s[--i] = (n % 10) + '0';
		else
			s[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = intlen(n);
	s = (char *)malloc(len + 1);
	s = convert(s, len, n);
	s[len + 1] = '\0';
	return (s);
}
