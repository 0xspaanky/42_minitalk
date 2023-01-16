/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:56:04 by smounafi          #+#    #+#             */
/*   Updated: 2023/01/15 22:07:59 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(long nb);
int	ft_putstr(char *str);
int	ft_printf(const char *str, ...);
int	ft_hexadeconv_toup(unsigned int nb);
int	ft_hexadeconv_tolow(unsigned int nb);
int	ft_adressconv(unsigned long nb);
int	ft_strlen(char *s);
int	ft_atoi(const char *str);
int	ft_isstrdigit(char *str);

#endif
