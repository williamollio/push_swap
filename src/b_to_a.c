/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:39:42 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 19:30:29 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_do_it(t_stack **head_a, t_stack **head_b)
{
	t_stack	*min;

	min = get_the_smallest_mov(head_b);
	if (min->mov == 1)
		return ;
	rr_or_rrr(min);
	do_rotate(head_a, head_b, min);
	do_rrotate(head_a, head_b, min);
}

void	push_b_to_a_tool(t_stack **head_a, t_stack **head_b, t_length *length)
{
	t_stack	*tmpa;
	int		pos;

	pos = 0;
	tmpa = *head_a;
	while (tmpa != NULL)
	{
		if (tmpa->index == 0)
		{
			ft_init_r_rr(tmpa);
			r_or_rra(tmpa, length, pos, 0);
			break ;
		}
		pos++;
		tmpa = tmpa->next;
	}
	do_rotate(head_a, head_b, tmpa);
	do_rrotate(head_a, head_b, tmpa);
}

void	push_b_to_a(t_stack **head_a, t_stack **head_b)
{
	t_length	length;

	while (*head_b != NULL)
	{
		ft_calculator(head_a, head_b, &length);
		ft_do_it(head_a, head_b);
		ft_push(head_b, head_a, 'a');
	}
	length.a = lengtha_list_modif(*head_a, &length);
	push_b_to_a_tool(head_a, head_b, &length);
}
