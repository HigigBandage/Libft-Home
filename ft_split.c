/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinn <dfinn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:05:12 by marvin            #+#    #+#             */
/*   Updated: 2022/10/24 17:50:55 by dfinn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, int size)
{
	while (size >= 0)
	{
		free(str[size]);
		size--;
	}
	free(str);
	return (NULL);
}

static int	ft_chek_null_word(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
	{
		i++;
	}
	return (i);
}

static int	ft_nb_word(char *str, char sep)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*str)
	{
		while (*str && *str == sep)
		{
			str++;
		}
		i = ft_chek_null_word(str, sep);
		str += i;
		if (i)
		{
			word++;
		}
	}
	return (word);
}

static char	*ft_strcpy(char *src, int n)
{
	char	*dest;

	dest = (char *)malloc((n + 1) * sizeof(char));
	if (!dest)
	{
		return (NULL);
	}
	dest[n] = '\0';
	n--;
	while (n >= 0)
	{
		dest[n] = src[n];
		n--;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	size = ft_nb_word((char *)s, c);
	tab = (char **)malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s && *s == c)
			s++;
		n = ft_chek_null_word((char *)s, c);
		tab[i] = ft_strcpy((char *)s, n);
		if (!tab[i])
			return (ft_free(tab, i));
		s += n;
		i++;
	}
	tab[size] = 0;
	return (tab);
}
