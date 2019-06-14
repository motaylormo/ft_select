/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 15:18:09 by mtaylor           #+#    #+#             */
/*   Updated: 2019/06/01 15:18:11 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_select(int argc, char **argv)
{
	argv_to_list(argc, argv);
	print_choices();
	while (handle_key())
	{
		termcaps_delete();
		print_choices();
	}
}

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf(USAGE);
		return (0);
	}
	terminal_restore();
	terminal_setup();
	ft_select(argc - 1, argv + 1);
	terminal_restore();
}
