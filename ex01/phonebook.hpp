/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:56:33 by aguinea           #+#    #+#             */
/*   Updated: 2025/05/12 15:17:19 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

class Phonebook
{
private:
	Contact list[8];
	int		num;

public:
	Phonebook() : num(0) {}
	std::string getNick(int index) {return list[index].get_nick();}
	int get_numof() {return num; }
	void	set_numof(int i) { num = i; }
	Contact getnumContact(int index) {return list[index] ;}
	void setContact(int index, const Contact& c) {list[index] = c; }
	Contact *get_list() {return list;}

};
#endif
