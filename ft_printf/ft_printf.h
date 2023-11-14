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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		checktype(char c, va_list arg_ptr, int size);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putpointer(unsigned int nbr, char *base, int count);
int		ft_putstr(char *str);
int		ft_putunsigned(int nb);

#endif
