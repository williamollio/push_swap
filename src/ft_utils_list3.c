/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 11:46:17 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 17:18:55 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	lengtha_list_modif(t_stack *n, t_length *length)
{
	int	i;

	i = 0;
	while (n != NULL)
	{
		n = n->next;
		i++;
	}
	if (i % 2 == 0)
		length->even_a = true;
	else
		length->even_a = false;
	return (i);
}

int	lengthb_list_modif(t_stack *n, t_length *length)
{
	int	i;

	i = 0;
	while (n != NULL)
	{
		n = n->next;
		i++;
	}
	if (i % 2 == 0)
		length->even_b = true;
	else
		length->even_b = false;
	return (i);
}

void	ft_insert_pos(t_stack *n)
{
	int	i;

	i = 0;
	while (n != NULL)
	{
		n->pos = i;
		n = n->next;
		i++;
	}
}

static int	ft_markup_index_tool(t_stack *head_a)
{
	t_stack	*temp;
	int		len;
	int		head_a_index;

	len = 1;
	temp = head_a;
	head_a_index = head_a->index;
	while (temp != NULL)
	{
		if (head_a_index + 1 == temp->index)
		{
			len++;
			head_a_index += 1;
		}
		temp = temp->next;
	}
	return (len);
}

int	ft_markup_index(t_stack *head_a, int *index_head1)
{
	t_stack	*temp;
	int		len;
	int		max;
	int		i;

	len = 0;
	max = 0;
	i = 0;
	*index_head1 = 0;
	temp = head_a;
	while (temp != NULL)
	{
		len = ft_markup_index_tool(temp);
		if (len > max)
		{
			max = len;
			*index_head1 = i;
		}
		i++;
		temp = temp->next;
	}
	return (max);
}
