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
	Named(std::string name): m_name(name){}
	std::string get_name() const {
		return m_name;
	}
	virtual std::string get_string() = 0;
private:
	std::string m_name;
};
