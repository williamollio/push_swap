/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:51:00 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 19:00:02 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr_or_rrr(t_stack *tmp)
{
	while (tmp->ra && tmp->rb)
	{
		tmp->ra--;
		tmp->rb--;
		tmp->rr++;
	}
	while (tmp->rra && tmp->rrb)
	{
		tmp->rra--;
		tmp->rrb--;
		tmp->rrr++;
	}
}

void	do_rotate(t_stack **head_a, t_stack **head_b, t_stack *min)
{
	while (min->ra)
	{
		ft_rotate(head_a, 'a');
		min->ra--;
	}
	while (min->rb)
	{
		ft_rotate(head_b, 'b');
		min->rb--;
	}
	while (min->rr)
	{
		ft_rotate(head_a, 'r');
		ft_rotate(head_b, 'c');
		min->rr--;
	}
}

void	do_rrotate(t_stack **head_a, t_stack **head_b, t_stack *min)
{
	while (min->rra)
	{
		ft_rrotate(head_a, 'a');
		min->rra--;
	}
	while (min->rrb)
	{
		ft_rrotate(head_b, 'b');
		min->rrb--;
	}
	while (min->rrr)
	{
		ft_rrotate(head_a, 'r');
		ft_rrotate(head_b, 'c');
		min->rrr--;
	}
}
