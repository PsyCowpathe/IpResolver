/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:40:07 by agirona           #+#    #+#             */
/*   Updated: 2020/12/07 12:54:52 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
void	ft_putnbr_base(int nb, char *base, char **res, int i);

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_to(char *base_to)
{
	int		i;
	int		d;
	char	c;

	i = 0;
	d = 0;
	while (base_to[i])
	{
		if ((base_to[i] >= 9 && base_to[i] <= 13) || base_to[i] == ' '
		|| base_to[i] == '-' || base_to[i] == '+')
			return (0);
		c = base_to[i];
		d = i + 1;
		while (base_to[d])
		{
			if (base_to[d] == c)
				return (0);
			d++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

int		check_from(char *base_from)
{
	int		i;
	int		d;
	char	c;

	i = 0;
	d = 0;
	while (base_from[i])
	{
		if ((base_from[i] >= 9 && base_from[i] <= 13) || base_from[i] == ' '
		|| base_from[i] == '-' || base_from[i] == '+')
			return (0);
		c = base_from[i];
		d = i + 1;
		while (base_from[d])
		{
			if (base_from[d] == c)
				return (0);
			d++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

char	*ft_rev(char *str)
{
	char	tmp;
	int		i;
	int		end;

	end = ft_strlen(str) - 1;
	i = 0;
	while (i <= end / 2)
	{
		tmp = str[i];
		str[i] = str[end - i];
		str[end - i] = tmp;
		i++;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		tmpres;
	char	*res;
	int		div;
	int		len;

	div = 0;
	res = NULL;
	if (check_from(base_from) == 0)
		return (0);
	if (check_to(base_to) == 0)
		return (0);
	tmpres = ft_atoi_base(nbr, base_from);
	if (!(res = (char *)malloc(sizeof(char) * 33 + 1)))
		return (0);
	ft_putnbr_base(tmpres, base_to, &res, 0);
	if (tmpres < 0)
	{
		len = ft_strlen(res);
		res[len] = '-';
		res[len + 1] = 0;
	}
	res = ft_rev(res);
	return (res);
}
