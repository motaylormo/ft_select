/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cols.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:54:28 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/05 11:54:30 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_cell(t_node *n, t_node *curr, int col_width)
{
	if (n)
	{
		if (n->s == 1)
			ft_dprintf(STDERR_FILENO, SELECTED);
		if (n == curr)
			ft_dprintf(STDERR_FILENO, HIGHLIGHT);
		ft_dprintf(STDERR_FILENO, "%s", n->data);
		ft_dprintf(STDERR_FILENO, COLOR_OFF);
		ft_dprintf(STDERR_FILENO, "%*c", col_width - ft_strlen(n->data), ' ');
	}
	else
		ft_dprintf(STDERR_FILENO, "%*c", col_width, ' ');
}

static void	print_line(t_list *list, t_node **n, int cols, int sum)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		print_cell(*n, list->curr, list->maxlen + MIN_BETWEEN_COLS);
		*n = (sum + i + 1 < list->count) ? (*n)->next : NULL;
		i++;
	}
	ft_dprintf(STDERR_FILENO, "\n");
}

void		print_choices(void)
{
	t_list	*list;
	t_node	*n;
	int		col_width;
	int		cols;
	int		rows;

	list = list_singleton(NULL);
	n = list->first;
	col_width = list->maxlen + MIN_BETWEEN_COLS;
	cols = window_width() / col_width;
	rows = 0;
	while (rows * cols < list->count)
	{
		print_line(list, &n, cols, rows * cols);
		rows++;
	}
	prev_print_rows(col_width * cols, rows);
}
