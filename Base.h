#pragma once
#include <string>
#include <iostream>
// 

class Printable {
	virtual std::string get_string() = 0;
	friend std::ostream & operator<< (std::ostream & os, Printable & pr) {
		os << pr.get_string();
		return os;
	}
};

class Named : public virtual Printable {
public:
	Named(std::string const & name): m_name(name){}
	std::string const & get_name() const {
		return m_name;
	}
private:
	std::string m_name;
};
