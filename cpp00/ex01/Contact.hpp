#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
private:
	std::string darkest_secret;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_num;
public:
	Contact(void);

	Contact(std::string &first, std::string &last, std::string &nick,
		std::string &phone, std::string &secret);

	const std::string &getFirstName(void) const;
	const std::string &getLastName(void) const;
	const std::string &getNickName(void) const;
	const std::string &getPhoneNum(void) const;
	const std::string &getDarkSecret(void) const;

	void setFirstName(const std::string &str);
	void setLastName(const std::string &str);
	void setNickName(const std::string &str);
	void setPhoneNum(const std::string &str);
	void setDarkestSecret(const std::string &str);
};

#endif
