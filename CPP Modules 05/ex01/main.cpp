#include "Bureaucrat.h"
#include "Form.h"

int main()
{
	try{
		Bureaucrat bureaucrat("Furkan", 1);
		Form form("Marriage Contrat", 1, 5);
		//std::cout << form << std::endl;
		bureaucrat.signForm(form);
		//std::cout << form << std::endl;
	}
	catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}