/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosenza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:12:19 by gcosenza          #+#    #+#             */
/*   Updated: 2023/10/23 17:35:50 by gcosenza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		checktype(char c, va_list arg_ptr);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putpointer(unsigned int nbr, char *base, int count);
int		ft_putstr(char *str);
int		ft_putunsigned(int nb);

#endif
