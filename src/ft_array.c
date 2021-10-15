/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:39:54 by wollio            #+#    #+#             */
/*   Updated: 2021/10/15 14:20:00 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_put_in_array(t_stack *head_a, int length)
{
	t_stack	*temp;
	int		i;
	int		*arr;

	i = 0;
	temp = head_a;
	arr = malloc(sizeof(int) * length);
	while (i < length && temp != NULL)
	{
		arr[i] = temp->data;
		temp = temp->next;
		i++;
	}
	return (arr);
}

void	swap(int *min, int *i)
{
	int	temp;

	temp = *min;
	*min = *i;
	*i = temp;
}

int	*ft_selection_sort(int *arr, int length)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < length)
	{
		min = i;
		j = i + 1;
		while (j < length)
		{
			if (arr[min] > arr[j])
				min = j;
			j++;
		}
		swap(&arr[min], &arr[i]);
		i++;
	}
	return (arr);
}

int	*ft_array_sorted(t_stack *head_a, int length)
{
	int		*arr;
	int		i;

	i = 0;
	arr = ft_put_in_array(head_a, length);
	arr = ft_selection_sort(arr, length);
	return (arr);
}
