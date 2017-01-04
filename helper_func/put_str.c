/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:07:53 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:15:01 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	put_str(char const *s)
{
	while (*s)
		put_char(*s++);
}

void	put_str_e(char const *s)
{
	while (*s)
		put_char(*s++);
	put_char('\n');
}
