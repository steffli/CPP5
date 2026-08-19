#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main(){

    std::cout << "--- Test 1: ShrubberyCreationForm, unsigned form ---" << std::endl;
    try{
        ShrubberyCreationForm shrub("garden");
        Bureaucrat Bob("Bob", 1);
        Bob.executeForm(shrub);   // not signed -> FormNotSignedException
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 2: ShrubberyCreationForm, signed + executed ---" << std::endl;
    try{
        ShrubberyCreationForm shrub("garden");
        Bureaucrat Bob("Bob", 1);
        Bob.signAForm(shrub);
        Bob.executeForm(shrub);   // creates garden_shrubbery
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 3: grade too low to execute ---" << std::endl;
    try{
        RobotomyRequestForm robot("R2D2");
        Bureaucrat Intern("Intern", 150);
        Intern.signAForm(robot);  // fails to sign (needs 72)
        Intern.executeForm(robot); // fails
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 4: RobotomyRequestForm, 50% chance ---" << std::endl;
    try{
        RobotomyRequestForm robot("R2D2");
        Bureaucrat Boss("Boss", 1);
        Boss.signAForm(robot);
        Boss.executeForm(robot);
        Boss.executeForm(robot);
        Boss.executeForm(robot);
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 5: PresidentialPardonForm ---" << std::endl;
    try{
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat Director("Director", 1);
        Director.signAForm(pardon);
        Director.executeForm(pardon);
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 6: low grade can sign but not execute ---" << std::endl;
    try{
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat Clerk("Clerk", 20);   // can sign (25) but not execute (5)
        Clerk.signAForm(pardon);
        Clerk.executeForm(pardon);
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
