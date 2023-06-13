#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"

Warlock::Warlock(const std::string& name, const std::string& title): _name(name), _title(title){
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void){
	std::cout << getName() << ": My job here is done!" << std::endl;
}

const std::string& Warlock::getName(void)const{
	return _name;
}

const std::string& Warlock::getTitle(void)const{
	return _title;
}

void Warlock::introduce(void)const{
	std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::setTitle(const std::string& title){
	_title = title;
}

void Warlock::learnSpell(ASpell* spell){
	if(spell){
		_warlock_spells[spell->getName()] = spell;
	} 
}

void Warlock::forgetSpell(std::string const spell){
	if(_warlock_spells.find(spell) != _warlock_spells.end())
		_warlock_spells.erase(_warlock_spells.find(spell));
}


void Warlock::launchSpell(std::string const SpellName, ATarget const & target)
{
	if (_warlock_spells.find(SpellName) != _warlock_spells.end())
		_warlock_spells[SpellName]->launch(target);
}
