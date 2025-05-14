/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:39:13 by aguinea           #+#    #+#             */
/*   Updated: 2025/05/08 13:04:03 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <algorithm>


int	main(int ac, char **av)
{
	int i = 1;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac == 2)
	{
		std::string arg = av[1];
		if (arg == "shhhhh... I think the students are asleep...")
		{
			std::transform(arg.begin(), arg.end(), arg.begin(), ::toupper);
			std::cout << arg << std::endl;
		}
	}
	else if (ac == 4)
	{
		for (i = 1; i < 4; i++)
		{
			std::string str = av[i];
			if(!((str == "Damnit" && i == 1) ||( str == " ! " && i == 2)
				|| (str == "Sorry students, I thought this thing was off." && i == 3)))
				break ;
		}
		if (i == 4)
		{
			for(int j = 1; j < 4; j++)
			{
				std::string str1 = av[j];
				std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
				std::cout << str1;
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
