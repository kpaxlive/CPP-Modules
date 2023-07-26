#include "ClapTrap.h"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();

		FragTrap& operator=(const FragTrap &other);

		void attack(const std::string &target);
		void highFivesGuys(void);
};



