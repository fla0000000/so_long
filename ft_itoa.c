/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:59:15 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/04/17 15:45:12 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoinmov(char *s1, char *s2)
{
	int		i;
	int		j;
	int		s1len;
	int		s2len;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	s1len = (int)ft_strlen(s1);
	s2len = (int)ft_strlen(s2);
	strjoin = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	while (++i < s1len)
	{
		strjoin[i] = s1[i];
	}
	j = 0;
	while (j < s2len)
	{
		strjoin[i++] = s2[j++];
	}
	strjoin[i] = '\0';
	return (strjoin);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	n_len(int a)
{
	int	i;

	i = 0;
	if (a < 0)
	{
		i++;
		a = -a;
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

char	*init_str(int n)
{
	char	*str;
	int		nlen;

	nlen = n_len(n);
	str = (char *)malloc(sizeof(char) * (nlen + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[nlen] = '\0';
		return (str);
	}
	else
	{
		str[nlen] = 0;
		return (str);
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nlen = n_len(n);
	str = init_str(n);
	if (!str)
		return (NULL);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		str[nlen - 1] = (n % 10) + '0';
		n /= 10;
		nlen--;
	}
	return (str);
}