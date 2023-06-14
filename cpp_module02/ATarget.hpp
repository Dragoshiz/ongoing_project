#ifndef ATARGET_HPP
#define ATARGET_HPP
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget{
	public:
	ATarget(std::string type);
	ATarget(ATarget&);
	virtual ~ATarget();
	ATarget& operator=(ATarget&);

	const std::string& getType(void)const;
	virtual ATarget* clone(void)const=0;
	void getHitBySpell(ASpell const &) const;
	private:
		std::string _type;
};

#endif