#include "Contact.hpp"
#include <string>
#include <ctime>

Contact::Contact(void)
{
	darkest_secret = "";
	first_name = "";
	last_name = "";
	nickname = "";
	phone_num = "";
}

Contact::Contact(std::string &first, std::string &last,
	std::string &nick, std::string &phone, std::string &secret)
{
	first_name = first;
	last_name = last;
	nickname = nick;
	phone_num = phone;
	darkest_secret = secret;
}

const std::string &Contact::getFirstName(void) const {
	return (this->first_name);
}

const std::string &Contact::getLastName(void) const {
	return (this->last_name);
}

const std::string &Contact::getNickName(void) const {
	return (this->nickname);
}

const std::string &Contact::getPhoneNum(void) const {
	return (this->phone_num);
}

const std::string &Contact::getDarkSecret(void) const {
	return (this->darkest_secret);
}

void Contact::setFirstName(const std::string &str) {
	this->first_name = str;
}

void Contact::setLastName(const std::string &str) {
	this->last_name = str;
}

void Contact::setNickName(const std::string &str) {
	this->nickname = str;
}

void Contact::setPhoneNum(const std::string &str) {
	this->phone_num = str;
}

void Contact::setDarkestSecret(const std::string &str) {
	this->darkest_secret = str;
}
