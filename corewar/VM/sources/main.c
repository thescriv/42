/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:26:21 by vduong            #+#    #+#             */
/*   Updated: 2018/12/10 18:44:02 by aetchego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	display_winner(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n", vm->winner + 1,
		vm->players[vm->winner].header.prog_name);
}

void	introduction(t_vm *vm)
{
	int i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < vm->num_players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
		vm->players[i].header.prog_size, vm->players[i].header.prog_name,
		vm->players[i].header.comment);
	}
}

int		main(int argc, char **argv)
{
	t_vm	vm;

	setlocale(LC_ALL, "");
	parse(argc, argv, &vm);
	init_vm(&vm);
	introduction(&vm);
	loop(&vm);
	display_winner(&vm);
	return (0);
}
