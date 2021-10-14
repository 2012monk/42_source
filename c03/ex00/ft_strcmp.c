/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seounlee <seounlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:15:38 by seounlee          #+#    #+#             */
/*   Updated: 2021/10/12 11:15:40 by seounlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	result;

	result = 0;
	while (*s2 && *s2 == *s1)
	{
		result += *s1++ - *s2++;
	}
	if (*s1)
		result += *s1;
	if (*s2)
		result -= *s2;
	return (result);
}
