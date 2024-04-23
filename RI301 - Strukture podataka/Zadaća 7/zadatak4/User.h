#pragma once
#include <iostream>
#include <string>

class User {
private:
	unsigned int id_;
	std::string firstName_;
	std::string lastName_;

	friend std::istream& operator>>(std::istream&, User&);
	friend std::ostream& operator<<(std::ostream&, const User&);
public:
	User() = default;
	User(int, const std::string&, const std::string&);
	User(const User& second) : id_{ second.id_ }, firstName_{ second.firstName_ }, lastName_{ second.lastName_ } {};
	User(User&&);

	User& operator=(const User&);
	User& operator=(User&&);

	void setFirstName(const std::string&);
	void setFirstName(std::string&&);
	void setLastName(const std::string&);
	void setLastName(std::string&&);
	void setId(unsigned int id) { id_ = id; };

	std::string getFirstName() const { return firstName_; };
	std::string getLastName() const { return lastName_; };
	unsigned int getId() const { return id_; };
};

