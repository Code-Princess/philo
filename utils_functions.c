/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:32:26 by llacsivy          #+#    #+#             */
/*   Updated: 2024/08/01 13:52:26 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isspace(int c)
{
	char	cast_c;

	cast_c = (char)c;
	if (cast_c == '\t' || cast_c == '\n' || cast_c == '\v' || cast_c == '\f'\
	|| cast_c == '\r' || cast_c == 32)
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	number *= sign;
	return (number);
}
long	ft_atol(char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	number *= sign;
	return (number);
}
