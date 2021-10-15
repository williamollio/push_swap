/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:06:42 by wollio            #+#    #+#             */
/*   Updated: 2021/10/12 17:18:14 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	length_list(t_stack *n)
{
	int	i;

	i = 0;
	while (n != NULL)
	{
		n = n->next;
		i++;
	}
	return (i);
}

void	ft_insert_index(t_stack **head_a, int *arr, int length)
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (i < length)
	{
		temp = *head_a;
		while (temp != NULL)
		{
			if (arr[i] == temp->data)
			{
				temp->index = i;
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
}

static int	ft_markup_tool(int *index_head, int *i, int *len, t_stack *head_a)
{
	t_stack	*temp;
	int		max;

	max = 1;
	temp = head_a;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			*len += 1;
		else
		{
			if (*len > max)
			{
				max = *len;
				*index_head = *(i) - *(len);
			}
			*len = 1;
		}
		*i += 1;
		temp = temp->next;
	}
	return (max);
}

int	ft_markup(t_stack *head_a, int *index_head)
{
	int		len;
	int		max;
	int		i;

	*index_head = 0;
	i = 1;
	len = 1;
	max = ft_markup_tool(index_head, &i, &len, head_a);
	if (len > max)
	{
		max = len;
		*index_head = i - len;
	}
	return (max);
}
