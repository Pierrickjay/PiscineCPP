/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:31:10 by pjay              #+#    #+#             */
/*   Updated: 2023/03/28 15:02:08 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

using std::string;

class Contact
{
	private:
		string _first_name;
		string _last_name;
		string _nickname;
		string _phone_number;
		string _darkest_secret;

	public:
		void printTest(void);
		void setFirstName(void);
		void setLastName(void);
		void setNickname(void);
		void setPhoneNumber(void);
		void setDarkestSecret(void);
		void printFirstName(void);
		void printLastName(void);
		void printNickname(void);
		void printContact(void);
		void printAllContact(void);
};

#endif
