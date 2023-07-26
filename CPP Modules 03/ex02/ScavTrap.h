#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
	public:
		//constructors destructor and copy assignment operator;
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap &other);
		
		//ScavTrap's features;
		void attack(const std::string& target);
		void guardGate();
};

