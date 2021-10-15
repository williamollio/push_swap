/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:41:13 by wollio            #+#    #+#             */
/*   Updated: 2021/10/13 10:01:48 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_3_char(char *buffer, int i)
{
	if (buffer[i] == 's'
		&& (buffer[i + 1] == 'a' || buffer[i + 1] == 'b')
		&& buffer[i + 2] == '\n')
		return (1);
	else if (buffer[i] == 'p'
		&& (buffer[i + 1] == 'a' || buffer[i + 1] == 'b')
		&& buffer[i + 2] == '\n')
		return (1);
	else if (buffer[i] == 'r'
		&& (buffer[i + 1] == 'a' || buffer[i + 1] == 'b'
			|| buffer[i + 1] == 'r')
		&& buffer[i + 2] == '\n')
		return (1);
	else
		return (0);
}

int	check_4_char(char *buffer, int i)
{
	if (buffer[i] == 'r'
		&& buffer[i + 1] == 'r' && buffer[i + 2] == 'a'
		&& buffer[i + 3] == '\n')
		return (1);
	else if (buffer[i] == 'r'
		&& buffer[i + 1] == 'r'
		&& buffer[i + 2] == 'b'
		&& buffer[i + 3] == '\n')
		return (1);
	else if (buffer[i] == 'r'
		&& buffer[i + 1] == 'r'
		&& buffer[i + 2] == 'r'
		&& buffer[i + 3] == '\n')
		return (1);
	return (0);
}

void	read_one(t_stack **head_a, t_stack **head_b, char **arr, int i)
{
	int	j;

	j = 0;
	if (arr[i][j] == 'r' && arr[i][j + 1] == 'r' && arr[i][j + 2] == 'a')
		ft_rrotate2(head_a);
	else if (arr[i][j] == 'r' && arr[i][j + 1] == 'r' && arr[i][j + 2] == 'b')
		ft_rrotate2(head_b);
	else if (arr[i][j] == 'r' && arr[i][j + 1] == 'r' && arr[i][j + 2] == 'r')
	{
		ft_rrotate2(head_a);
		ft_rrotate2(head_b);
	}
	return ;
}

void	read_two(t_stack **head_a, t_stack **head_b, char **arr, int i)
{
	int	j;

	j = 0;
	if (arr[i][j] == 's' && arr[i][j + 1] == 'a')
		ft_swap2(head_a);
	else if (arr[i][j] == 's' && arr[i][j + 1] == 'b')
		ft_swap2(head_b);
	else if (arr[i][j] == 'p' && arr[i][j + 1] == 'a')
		ft_push2(head_b, head_a);
	else if (arr[i][j] == 'p' && arr[i][j + 1] == 'b')
		ft_push2(head_a, head_b);
	else if (arr[i][j] == 'r' && arr[i][j + 1] == 'a')
		ft_rotate2(head_a);
	else if (arr[i][j] == 'r' && arr[i][j + 1] == 'b')
		ft_rotate2(head_b);
	else if (arr[i][j] == 'r' && arr[i][j + 1] == 'r')
	{
		ft_rotate2(head_a);
		ft_rotate2(head_b);
	}
}
