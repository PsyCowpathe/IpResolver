/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_resolver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirona <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:15:18 by agirona           #+#    #+#             */
/*   Updated: 2020/12/07 14:06:23 by agirona          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		ft_atoi_base(char *str, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		*get_mask(char *str)
{
	char	tmp[9];
	int		i;
	int		c;
	int		*mask;

	i = 0;
	tmp[8] = '\0';
	c = 0;
	if ((mask = malloc(sizeof(int) * 32)) == NULL)
		return (NULL);
	ft_putstr("Mask = ");
	while (c <= 32)
	{
		if (i % 8 == 0 && i != 0)
		{
			ft_putnbr(ft_atoi_base(tmp, "01"));
			if (c <= 24)
				ft_putchar('.');
			i = 0;
		}
		tmp[i++] = (c < ft_atoi(str)) ? '1' : '0';
		mask[c] = (c < ft_atoi(str)) ? 1 : 0;
		c++;
	}
	return (mask);
}

void	get_plage(int *mask, char *ip)
{
	char	tmp[9];
	int		i;
	int		c;

	i = 0;
	c = 0;
	//ft_putchar('\n');
	tmp[8] = '\0';
	ft_putstr("First Ip = ");
	while (ip[i])
	{
		if (mask[i] == 1)
			tmp[c] = ip[i];
		else
			tmp[c] = '0';
		if (c == 7)
		{
			ft_putstr(ft_convert_base(tmp, "01", "0123456789"));
			if (i <= 24)
				ft_putchar('.');
			c = 0;
		}
		else
			c++;
		i++;
	}
	ft_putchar('\n');
	ft_putstr("Last  Ip = ");
	i = 0;
	c = 0;
	while (ip[i])
	{
		if (mask[i] == 1)
			tmp[c] = ip[i];
		else
			tmp[c] = '1';
		if (c == 7)
		{
			ft_putstr(ft_convert_base(tmp, "01", "0123456789"));
			if (i <= 24)
				ft_putchar('.');
			c = 0;
		}
		else
			c++;
		i++;
	}
}

char	*set_zero(char *str)
{
	char	*res;
	int		c;
	int		i;

	i = 0;
	c = 0;
	if ((res = malloc(sizeof(char) * 9)) == NULL)
		return (NULL);
	if (ft_strlen(str) != 8)
	{
		c = 0;
		while (ft_strlen(str) + c != 8)
		{
			res[c] = '0';
			c++;
		}
	}
	while (str[i])
		res[c++] = str[i++];
	res[c] = '\0';
	free(str);
	return (res);
}

void	get_ip(char *ip, int *mask)
{
	int		i;
	char	*ipb;
	int		c;
	char	*tmp;
	char	*tmp2;

	//i = 0;
	//c = -1;
	/*while (i < 32)
	{
		if (++c == 8)
		{
			ft_putchar(' ');
			c = 0;
		}
		ft_putnbr(mask[i++]);
	}*/
	tmp2 = NULL;
	i = 0;
	c = 0;
	//ft_putchar('\n');
	ft_putstr("Ip   = ");
	ft_putendl_fd(ip, 1);
	while (c++ < 4)
	{
		tmp = ft_convert_base(ip + i, "0123456789", "01");
		tmp = set_zero(tmp);
		if (tmp2 != NULL)
			ipb = ft_strjoin(tmp2, tmp);
		else
			ipb = tmp;
		tmp2 = ipb;
		//ft_putstr(tmp);
		//ft_putchar(' ');
		i = i + 4;
	}
	get_plage(mask, ipb);
}

int		main(int argc, char **argv)
{
	int		i;
	int		*mask_bin;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] && argv[1][i] != '/')
			i++;
		mask_bin = get_mask(argv[1] + i + 1);
		ft_putchar('\n');
		get_ip(argv[1], mask_bin);
	}
}
