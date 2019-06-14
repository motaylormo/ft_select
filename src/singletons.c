/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:53:43 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/13 13:53:44 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			window_width(void)
{
	struct winsize	argp;

	ioctl(0, TIOCGWINSZ, &argp);
	return (argp.ws_col);
}

t_list		*list_singleton(t_list *arg)
{
	static t_list	*singleton = NULL;

	if (arg)
		singleton = arg;
	return (singleton);
}

static int	ceiling_div(int a, int b)
{
	int sum;

	if (b == 0)
		return (1);
	sum = a / b;
	if (a % b != 0)
		sum++;
	return (sum);
}

int			prev_print_rows(int width, int rows)
{
	static int	prev_width;
	static int	prev_rows;

	if (width && rows)
	{
		prev_width = width;
		prev_rows = rows;
	}
	return (ceiling_div(prev_width, window_width()) * prev_rows);
}
