/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <vduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:54:01 by vduong            #+#    #+#             */
/*   Updated: 2018/12/07 10:54:02 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	proc_fork(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	create_process(vm, mod_adr(proc->pc + inst->params[0] % IDX_MOD), 0, 1);
	vm->processes->alive = proc->alive;
	ft_memcpy((void*)vm->processes->r, (void*)proc->r,
			(size_t)REG_NUMBER * sizeof(int));
	vm->processes->carry = proc->carry;
	vm->processes->alive = proc->alive;
}

void	proc_lfork(t_vm *vm, t_proc *proc, t_instruction *inst)
{
	create_process(vm, mod_adr(proc->pc + inst->params[0]), 0, 1);
	vm->processes->alive = proc->alive;
	ft_memcpy((void*)vm->processes->r, (void*)proc->r,
			(size_t)REG_NUMBER * sizeof(int));
	vm->processes->carry = proc->carry;
	vm->processes->alive = proc->alive;
}
