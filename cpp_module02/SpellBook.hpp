#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP
#include "ASpell.hpp"
#include <map>

class SpellBook{
	public:
		SpellBook(){};
		~SpellBook(){};
		void learnSpell(ASpell *);
		void forgetSpell(std::string const &);
		ASpell* createSpell(std::string const &);
	private:
		SpellBook(SpellBook const &);
		SpellBook& operator=(SpellBook const &);
		std::map<std::string, ASpell* > _spells; 

};

#endif