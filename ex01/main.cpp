/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:13:20 by aguinea           #+#    #+#             */
/*   Updated: 2025/05/13 16:13:16 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <sstream>
# include "phonebook.hpp"
# include "contact.hpp"

static std::string format_field(const std::string& text)
{
    std::ostringstream oss;
    if (text.length() > 10)
    {
        oss << text.substr(0, 9) << '.';
    }
    else
    {
        oss << std::setw(10) << std::setfill(' ') << text;
    }
    return oss.str();
}
int	just_letter(std::string str, int flag)
{
	if(str.empty())
		return 0;
	if(flag == 1)
	{
		for(size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == '-' || str[i] == ' ')
				continue ;
			if(!std::isalpha(str[i]))
				return 0;
		}
	}
	if (flag == 36)
	{
		for(size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
				continue ;
			if(!std::isdigit(str[i]))
				return 0;
		}
	}
	return 1;
}

Contact add_contact(int contact_id, int *cont) 
{
    std::string f_name, l_name, n_name, p_number, secret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, f_name);
	if (f_name == "" || !just_letter(f_name, 1))
		*cont = -1;
    std::cout << "Enter last name: ";
    std::getline(std::cin, l_name);
	if (l_name == "" || !just_letter(l_name, 1))
		*cont = -1;
    std::cout << "Enter nickname: ";
    std::getline(std::cin, n_name);
	if (n_name == "")
		*cont = -1;
    std::cout << "Enter phone number: ";
    std::getline(std::cin, p_number);
	if (p_number == "" || !just_letter(p_number, 36))
		*cont = -1;
    std::cout << "Enter deepest secret: ";
    std::getline(std::cin, secret);
	if (secret == "")
		*cont = -1;
    return Contact(f_name, l_name, n_name, p_number, secret, contact_id + 1);
}

void display_contact(Phonebook *cont)
{
	std::string num;
	Contact *tmp = (*cont).get_list();
	std::string chosen;
	int id = 0;

	if (cont->get_numof() == 0)
	{
		std::cout << "No Contacts yet" << std::endl;
		return ;
	}
	else
	{
		std::cout <<"*-------------------------------------------*" << std::endl;
		std::cout << "*" << format_field("INDEX") << "|"
			<<format_field("FIRSTNAME") << "|"
			<<format_field("LASTNAME") << "|"
			<<format_field("NICKNAME") << "*" <<std::endl;
		std::cout <<"*-------------------------------------------*" << std::endl;
		for (int i = 0; i < cont->get_numof(); i++)
		{
			std::cout << "*         " <<      i + 1     << "|"
			          << format_field(tmp[i].get_fname()) << "|"
			          << format_field(tmp[i].get_lname()) << "|"
			          << format_field(tmp[i].get_nick()) << "*" << std::endl;
		}
		std::cout <<"*-------------------------------------------*" << std::endl;
	}
	std::cout << "Enter contact id: ";
	if (std::getline(std::cin, chosen) == 0)
		return ;
	std::stringstream ss(chosen);
	ss >> id;
	while (chosen == "" || !just_letter(chosen, 36) || (!(id > 0 && id <= cont->get_numof())))
	{
		std::cout << "Invalid id, try again: ";
		if (std::getline(std::cin, chosen) == 0)
			return;
		std::stringstream ss(chosen);
		ss >> id;
	}
	int j = 0;
	while (tmp[j].get_id() != id)
		j++;
	std::cout << "⮞ ID = " << tmp[j].get_id() << std::endl;
	std::cout << "⮞ First Name = "<< tmp[j].get_fname() <<std::endl;
	std::cout << "⮞ Last Name = " << tmp[j].get_lname() <<std::endl;
	std::cout << "⮞ Nickname = " << tmp[j].get_nick() <<std::endl;
	std::cout << "⮞ Phone Number = " << tmp[j].get_phone() <<std::endl;
	std::cout << "⮞ Deepest Secret = " << tmp[j].get_secret() << std::endl;
}

	
int main (int ac, char **av)
{
	Phonebook arr;
	int i = 0;
	int	cont = 0;
	int	k = 0;
	*av = NULL;
	if (ac == 1)
	{
		std::cout << "Commands to use: ADD, SEARCH & EXIT" << std::endl;
		while(3)
		{
			std::string command;
			std::cout << "Enter Command: ";
			if (std::getline(std::cin, command) == 0)
				return 1;
			if (command == "ADD")
			{
				if (i == 8)
					i = 0;
				arr.setContact(i, add_contact(i, &cont));
				while (cont == -1)
				{
					std::cout << "Invalid Contact" << std::endl;
					cont = 0;
					arr.setContact(i, add_contact(i, &cont));
				}
				if (8 > k)
				{
					k++;
					arr.set_numof(k);
				}
				i++;
			}
			else if (command == "SEARCH")
				display_contact(&arr);
			else if(command == "EXIT")
				break ;
		}
	}
	return 0;
}
