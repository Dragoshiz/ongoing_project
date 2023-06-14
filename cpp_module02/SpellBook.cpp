#include "SpellBook.hpp"


void SpellBook::learnSpell(ASpell* spell){
	if(spell){
		_spells[spell->getName()] = spell;
	} 
}

void SpellBook::forgetSpell(std::string const &spell){
	if(_spells.find(spell) != _spells.end())
		_spells.erase(_spells.find(spell));
}

ASpell* SpellBook::createSpell(std::string const &spell){
	if(_spells.find(spell) != _spells.end())
		return _spells[spell];
	return NULL;
}