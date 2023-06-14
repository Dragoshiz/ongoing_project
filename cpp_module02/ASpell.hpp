#ifndef ASPELL_HPP
#define ASPELL_HPP
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell{
	public:
	ASpell();
	ASpell(std::string name, std::string effects);
	ASpell(const ASpell&);
	virtual ~ASpell();
	ASpell& operator=(const ASpell&);

	std::string getName(void)const;
	std::string getEffects(void)const;
	virtual ASpell* clone(void)const=0;
	void launch(ATarget const &)const;
	
	protected:
		std::string _name;
		std::string _effects;
};

#endif