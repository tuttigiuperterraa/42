/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:23:42 by gcosenza          #+#    #+#             */
/*   Updated: 2024/03/01 08:15:54 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *s)
{
	while (*s != '\0')
		write(1, s++, 1);
}

int	check_param(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] < '.' || str[i] == '/' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	handle_signs(char *str, int *i, int *neg)
{
	if (str[*i] == '-')
		*neg = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}

double	atod(char *str)
{
	double	result;
	double	decimal;
	int		neg;
	int		i;

	i = 0;
	result = 0;
	decimal = 0;
	neg = 1;
	handle_signs(str, &i, &neg);
	if (!check_param(str, i))
		exit (write(1, "Only numbers accepted as params.\n", 33));
	while (str[i] && str[i] != '.')
		result = result * 10 + (double)(str[i++] - 48);
	if (str[i] == '.')
	{
		i++;
		while (str[i])
			decimal = decimal * 10 + (double)(str[i++] - 48);
	}
	while (decimal >= 1)
		decimal /= 10;
	return ((result + decimal) * neg);
}
