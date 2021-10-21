/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:29:47 by wollio            #+#    #+#             */
/*   Updated: 2021/10/21 18:56:30 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_verify(t_stack **head_a)
{
	t_stack	*tmp;
	int		previous;

	tmp = *head_a;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
		{
			write(1, "KO\n", 3);
			exit(0);
		}
		previous = tmp->data;
		tmp = tmp->next;
	}
	if (previous > tmp->data)
	{
		write(1, "KO\n", 3);
		exit(0);
	}
}

void	ft_apply(t_stack **head_a, t_stack **head_b, char *buffer)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(buffer, '\n');
	ft_free1(buffer);
	while (arr[i] != '\0')
	{
		if (ft_strlen(arr[i]) == 2)
			read_two(head_a, head_b, arr, i);
		else
			read_one(head_a, head_b, arr, i);
		i++;
	}
	ft_free2(arr);
	ft_verify(head_a);
}

void	ft_instructions(t_stack **head_a, t_stack **head_b, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (check_3_char(buffer, i))
			i += 3;
		else if (check_4_char(buffer, i))
			i += 4;
		else
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	ft_apply(head_a, head_b, buffer);
}

char	*ft_reading(char *buffer, t_stack **head_a)
{
	char	*line;

	line = get_next_line(0);
	buffer = ft_strdup("");
	while (line != NULL)
	{
		ft_append(&buffer, line);
		ft_free1(line);
		line = get_next_line(0);
	}
	if (if_sorted2(head_a))
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	return (buffer);
}
