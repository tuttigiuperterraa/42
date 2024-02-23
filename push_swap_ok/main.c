/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <aconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:11:23 by aconti            #+#    #+#             */
/*   Updated: 2024/02/20 16:53:49 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(long int *arr, int n)
{
	int i;
	
	i = 1;
	while (i < n)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *stack = NULL;
	t_stack *b = NULL;

	// b = malloc(sizeof(t_stack));
	// if (!b)
	// 	return (0);	
	int n = count_num(argv);
	long int nums[n];
	ft_atoi(argv, nums);
	if (ft_check(nums, n) == 0 || argc < 2)
		return(write(1, "Error", 5));
	if (n == 1 || is_sorted(nums, n))
		return (0);
	array_to_stack(nums, n, &stack);
	sort(&stack, &b, n);
	return (0);
}