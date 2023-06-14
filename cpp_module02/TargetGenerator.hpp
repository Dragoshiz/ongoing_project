#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
#include "ATarget.hpp"
#include <iostream>
#include <map>

class TargetGenerator{
	public:
		TargetGenerator();
		~TargetGenerator();
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);
	private:
		TargetGenerator(TargetGenerator const &);
		TargetGenerator& operator=(TargetGenerator const &);
		std::map<std::string, ATarget*> _targets;
};

#endif