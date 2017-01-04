/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:09:23 by amarquez          #+#    #+#             */
/*   Updated: 2016/11/17 13:18:20 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		print_dir_name(char *str)
{
	put_str(CYAN);
	put_str(str);
	put_str_e(": "RESET);
}

void		cmd_nf(char *str)
{
	put_str(RED"ft_ls error: command '");
	put_str(str);
	put_str("' not found"RESET);
	put_char('\n');
}
