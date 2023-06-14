#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){}

void TargetGenerator::learnTargetType(ATarget* target){
	if(target){
		_targets[target->getType()] = target;
	}
}

void TargetGenerator::forgetTargetType(std::string const &target){
	if(_targets.find(target) != _targets.end())
		_targets.erase(_targets.find(target));
}

ATarget* TargetGenerator::createTarget(std::string const &target){
	if(_targets.find(target) != _targets.end())
		return _targets[target];
	return NULL;
}