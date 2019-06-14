/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_edit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:25:22 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/06 10:25:23 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	termcaps_delete(void)
{
	int	lines;

	lines = prev_print_rows(0, 0);
	while (lines--)
	{
		ft_putstr_fd(tgoto(tgetstr("up", NULL), -1, 0), STDERR_FILENO);
		ft_putstr_fd(tgetstr("dl", NULL), STDERR_FILENO);
	}
}
