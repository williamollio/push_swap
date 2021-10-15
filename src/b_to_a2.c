/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:25:16 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 18:12:34 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_r_rr(t_stack *tmpb)
{
	tmpb->ra = 0;
	tmpb->rb = 0;
	tmpb->rr = 0;
	tmpb->rra = 0;
	tmpb->rrb = 0;
	tmpb->rrr = 0;
}

static void	r_or_rra_tool(t_stack *tmpb, int len, int pos, int nbr)
{
	if (pos > len / 2)
	{
		tmpb->mov += ((len / 2) + 1) - (pos - (len / 2)) - nbr;
		tmpb->rra = ((len / 2) + 1) - (pos - (len / 2)) - nbr;
	}
	else
	{
		tmpb->mov += pos + nbr;
		tmpb->ra = pos + nbr;
	}
}

void	r_or_rra(t_stack *tmpb, t_length *length, int pos, int nbr)
{
	if (length->even_a == true)
	{
		if (pos > length->a / 2)
		{
			tmpb->mov += (length->a / 2) - (pos - (length->a / 2)) - nbr;
			tmpb->rra = (length->a / 2) - (pos - (length->a / 2)) - nbr;
		}
		else
		{
			tmpb->mov += pos + nbr;
			tmpb->ra = pos + nbr;
		}
	}
	else
		r_or_rra_tool(tmpb, length->a, pos, nbr);
}

void	r_or_rrb_tool(t_stack *tmpb, int len, int pos)
{
	if (pos > len / 2)
	{
		tmpb->mov += ((len / 2) + 1) - (pos - (len / 2));
		tmpb->rrb = ((len / 2) + 1) - (pos - (len / 2));
	}
	else
	{
		tmpb->mov += pos;
		tmpb->rb = pos;
	}
}

void	r_or_rrb(t_stack *tmpb, t_length *length, int pos)
{
	if (length->b == 1)
		return ;
	if (length->even_b == true)
	{
		if (pos > length->b / 2)
		{
			tmpb->mov += (length->b / 2) - (pos - (length->b / 2));
			tmpb->rrb = (length->b / 2) - (pos - (length->b / 2));
		}
		else
		{
			tmpb->mov += pos;
			tmpb->rb = pos;
		}
	}
	else
		r_or_rrb_tool(tmpb, length->b, pos);
}
