/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:38:35 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/06 16:38:36 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	set_maxlen(t_list *list)
{
	t_node	*n;
	int		curr;
	int		max;
	int		countdown;

	max = 0;
	n = list->first;
	countdown = list->count;
	while (countdown--)
	{
		curr = ft_strlen(n->data);
		if (curr > max)
			max = curr;
		n = n->next;
	}
	list->maxlen = max;
}

static void	add_node(t_list *list, char *ptr)
{
	t_node	*n;

	n = ft_memalloc(sizeof(t_node));
	n->data = ptr;
	if (!list->first)
	{
		list->first = n;
		list->count = 1;
		n->next = n;
		n->prev = n;
	}
	else
	{
		list->count++;
		n->next = list->first;
		n->prev = list->first->prev;
		list->first->prev->next = n;
		list->first->prev = n;
	}
}

void		argv_to_list(int argc, char **argv)
{
	t_list	*list;
	int		i;

	list = ft_memalloc(sizeof(t_list));
	i = 0;
	while (i < argc)
		add_node(list, argv[i++]);
	set_maxlen(list);
	list->curr = list->first;
	list_singleton(list);
}

void		delete_node(t_list *list, t_node *n)
{
	if (list && n)
	{
		if (list->count > 1)
		{
			n->prev->next = n->next;
			n->next->prev = n->prev;
			if (n == list->first)
				list->first = n->next;
		}
		else
		{
			n->next = NULL;
			n->prev = NULL;
			list->first = NULL;
		}
		free(n);
		list->count--;
		set_maxlen(list);
	}
	if (list && (list->first == NULL))
		kill(getpid(), SIGINT);
}
