/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:42:28 by aguinea           #+#    #+#             */
/*   Updated: 2025/05/09 18:02:48 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "phonebook.hpp"
# include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone;
	std::string secret;
	int id;
public:

	 Contact() : first_name(""), last_name(""), nickname(""),
	 phone(""), secret(""), id(-1) {}

	Contact(std::string f_name, std::string l_name, std::string n_name,
        std::string p_number, std::string s, int contact_id)
    : first_name(f_name), last_name(l_name), nickname(n_name),
        phone(p_number), secret(s), id(contact_id) {}

	std::string get_fname(void) {return first_name; }
	std::string get_lname(void) {return last_name; }
	std::string get_nick(void) {return nickname; }
	std::string	get_phone(void) {return phone; }
	std::string get_secret(void) {return secret; }
	void set_id(int n) {id = n; }
	int get_id(void) {return id; }
	std::string get_nick() const { return nickname; }
};

#endif
