#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"


class Warlock{
	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock();

		const std::string& getName(void)const;
		const std::string& getTitle(void)const;
		void introduce()const;
		void setTitle(const std::string& title);
		void learnSpell(ASpell*);
		void forgetSpell(std::string const spell);
		void launchSpell(std::string const SpellName, const ATarget & target);
	private:
		SpellBook* _spellBook;
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(Warlock&);
		Warlock& operator=(Warlock&);
};


#endif