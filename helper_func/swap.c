/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:03:22 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/16 17:03:08 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	swap_s(struct s_filelist **a, struct s_filelist **b)
{
	struct s_filelist *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_d(char **a, char **b)
{
	char			*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap(char *a, char *b)
{
	char			temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
