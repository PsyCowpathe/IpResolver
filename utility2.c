/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:40:29 by agirona           #+#    #+#             */
/*   Updated: 2020/12/06 17:40:33 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str);

void	ft_putnbr_base(int nbr, char *base, char **res, int i)
{
	long int	nb;
	int			div;

	nb = nbr;
	div = ft_strlen(base);
	if (nb < 0)
		nb *= -1;
	res[0][i] = base[nb % div];
	res[0][i + 1] = 0;
	if (nb / div > 0)
		ft_putnbr_base(nb / div, base, res, i + 1);
}

int		check(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

int		ft_base_conv(char *str, char *base, int neg)
{
	int		mult;
	int		nbindex;
	int		res;
	int		i;

	res = 0;
	i = 0;
	mult = ft_strlen(base);
	while (str[i])
	{
		if ((nbindex = check(base, str[i])) == -1)
			return (res * neg);
		res = res * mult + nbindex;
		i++;
	}
	return (res * neg);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		count;
	int		neg;

	count = 0;
	i = 0;
	while (str[i] == '\r' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\t' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	neg = (count % 2 == 0) ? 1 : -1;
	return (ft_base_conv(&str[i], base, neg));
}
