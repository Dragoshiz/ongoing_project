#include "ATarget.hpp"

ATarget::ATarget(std::string type):_type(type){}

ATarget::~ATarget(){}
ATarget::ATarget(ATarget& obj){
	_type = obj.getType();
}

ATarget& ATarget::operator=(ATarget& obj){
	if (this != &obj){
		_type = obj._type;
	}
	return(*this);
}

const std::string& ATarget::getType(void)const{
	return _type;
}

void ATarget::getHitBySpell(ASpell const & obj)const{
	std::cout << _type << " has been " << obj.getEffects() << "!" << std::endl;
}
