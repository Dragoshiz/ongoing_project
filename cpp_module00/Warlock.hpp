#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include <string>

class Warlock{
	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		const std::string& getName(void)const;
		const std::string& getTitle(void)const;
		void introduce()const;
		void setTitle(const std::string& title);
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(Warlock&);
		Warlock& operator=(Warlock&);
};

#endif