#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "SpellBook.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"
Warlock::Warlock(const std::string& name, const std::string& title): _name(name), _title(title){
	std::cout << _name << ": This looks like another boring day." << std::endl;
	_spellBook = new SpellBook();;
}

Warlock::~Warlock(void){
	std::cout << getName() << ": My job here is done!" << std::endl;
	delete _spellBook;
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
	_spellBook->learnSpell(spell);
}

void Warlock::forgetSpell(std::string const spell){
	_spellBook->forgetSpell(spell);
}


void Warlock::launchSpell(std::string const SpellName, ATarget const & target)
{
	ASpell* magik = _spellBook->createSpell(SpellName);
	magik->launch(target);
}
