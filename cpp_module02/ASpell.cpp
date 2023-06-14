#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::~ASpell(){}
ASpell::ASpell(std::string name, std::string effects):_name(name), _effects(effects){
};

ASpell::ASpell(const ASpell& obj){
	_name = obj.getName();
	_effects = obj.getName();
}

ASpell& ASpell::operator=(const ASpell& obj){
	if (this != &obj){
		_name = obj.getName();
		_effects = obj.getName();
	}
	return *this;
}

std::string ASpell::getName(void)const{
	return _name;
}

std::string ASpell::getEffects(void)const{
	return _effects;
}

void ASpell::launch(ATarget const & obj)const{
	obj.getHitBySpell(*this);
}
