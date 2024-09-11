/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosas-n <drosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:15:36 by drosas-n          #+#    #+#             */
/*   Updated: 2023/09/04 19:30:46 by drosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_prtstring(char *s);
int	ft_decsig(int num);
int	ft_decnosig(unsigned int num);
int	ft_hexadec(unsigned long long n, char c);
int	ft_ptr(unsigned long long n);

#endif
