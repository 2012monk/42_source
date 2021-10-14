/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:11:09 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/10 21:42:46 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	print_dec_to_hex(unsigned long n, int size)
{
	char	digit;

	digit = '0';
	if (size == 0)
		return ;
	print_dec_to_hex(n / 16, --size);
	if (n % 16 > 9)
		digit += 'a' - '0';
	ft_put_char(digit + (n % 16 % 10));
}

void	safe_print_char(char *str, int length)
{
	if (length == 0)
		return ;
	if (*str == 127 || *str < 32)
		ft_put_char('.');
	else
		ft_put_char(*str);
	safe_print_char(str + 1, length - 1);
}

void	print_ascii_hex(char *str, int size)
{
	print_dec_to_hex((unsigned long) *str, 2);
	if (size % 2 != 0)
		ft_put_char(' ');
	if (size > 1)
		print_ascii_hex(str + 1, size - 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	char	*str;
	int		batch;

	i = (int) size;
	str = (char *) addr;
	batch = size;
	if (size > 16)
		batch = 16;
	while (i > 0)
	{
		print_dec_to_hex((unsigned long)str, 16);
		write(1, &": ", 2);
		print_ascii_hex(str, 16);
		ft_put_char(' ');
		safe_print_char(str, batch);
		ft_put_char('\n');
		str += 16;
		i -= 16;
		if (i < 16)
			batch = i;
	}
}
