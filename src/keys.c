/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:58:29 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/06 15:58:31 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	right arrow
**	left arrow
**	backspace key
**	delete key
**	esc key
**	spacebar
**	return key
*/

static const t_key	g_keys[] = {
	(t_key){"\e[C", key_right},
	(t_key){"\e[D", key_left},
	(t_key){"\e[3~", key_delete},
	(t_key){"\x7f", key_delete},
	(t_key){"\e", key_esc},
	(t_key){" ", key_select},
	(t_key){"\n", key_return},
	(t_key){(NULL), 0}
};

static int	get_key(void)
{
	char	buf[KEY_SEQ_BUF_SIZE + 1];
	int		i;

	ft_bzero(buf, KEY_SEQ_BUF_SIZE + 1);
	while (read(0, buf, KEY_SEQ_BUF_SIZE))
	{
		i = 0;
		while (g_keys[i].seq)
		{
			if (ft_strequ(buf, g_keys[i].seq))
				return (g_keys[i].enumcode);
			i++;
		}
		ft_bzero(buf, KEY_SEQ_BUF_SIZE);
	}
	return (-1);
}

/*
**	"list of choices sent back will be separated by a space."
*/

static void	validate_selection(t_list *list)
{
	t_node	*n;
	int		countdown;

	termcaps_delete();
	n = list->first;
	countdown = list->count;
	while (countdown--)
	{
		if (n->s == 1)
		{
			if (!(countdown == list->count - 1))
				ft_printf(" ");
			ft_printf("%s", n->data);
		}
		n = n->next;
	}
	terminal_restore();
	exit(0);
}

int			handle_key(void)
{
	t_list	*list;
	int		key;

	list = list_singleton(NULL);
	key = get_key();
	if (key == key_left)
		list->curr = list->curr->prev;
	if (key == key_right)
		list->curr = list->curr->next;
	if (key == key_select)
	{
		list->curr->s = (list->curr->s == 0) ? 1 : 0;
		list->curr = list->curr->next;
	}
	if (key == key_esc)
		kill(getpid(), SIGINT);
	if (key == key_return)
		validate_selection(list);
	if (key == key_delete)
	{
		list->curr = list->curr->next;
		delete_node(list, list->curr->prev);
	}
	return (1);
}
