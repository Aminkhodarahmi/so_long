/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:29:05 by akhodara          #+#    #+#             */
/*   Updated: 2023/05/23 19:40:58 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_min_itoa(char *p, long nb, int end)
{
	int	i;

	i = end - 1;
	if (nb == 0)
		p[0] = '0';
	if (nb < 0)
	{
		p[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		p[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	p[end] = '\0';
	return (p);
}

static int	ft_count_digit2(int n)
{
	int		digit;
	long	nb;

	nb = n;
	digit = 0;
	if (nb == 0)
		return (digit + 1);
	if (nb < 0)
	{
		nb *= -1;
		digit++;
	}
	while (nb != 0)
	{
		digit++;
		nb /= 10;
	}
	return (digit);
}

char	*ft_itoa2(int n)
{
	char	*p;
	long	nb;
	int		end;

	nb = n;
	end = ft_count_digit2(nb);
	p = (char *)malloc(end + 1);
	if (!p)
		return (0);
	return (ft_min_itoa(p, nb, end));
}
