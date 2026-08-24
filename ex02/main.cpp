#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <fstream>


int main(){

    std::srand(std::time(NULL));
    std::cout << "--- Test 1: ShrubberyCreationForm, unsigned form ---" << std::endl;
    try{
        ShrubberyCreationForm shrub("garden");
        Bureaucrat Bob("Bob", 1);
        Bob.executeForm(shrub);   // not signed -> FormNotSignedException
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 2: ShrubberyCreationForm, signed + executed, tree printed to console ---" << std::endl;
    try{
        ShrubberyCreationForm shrub("garden");
        Bureaucrat Bob("Bob", 1);
        Bob.signForm(shrub);
        Bob.executeForm(shrub);   // creates garden_shrubbery

        // read the generated file back so the tree is visible on screen
        std::ifstream file("garden_shrubbery");
        if (!file.is_open()){
            std::cout << "Error: could not open garden_shrubbery" << std::endl;
        }
        else{
            std::cout << "--- contents of garden_shrubbery ---" << std::endl;
            std::string line;
            while (std::getline(file, line))
                std::cout << line << std::endl;
            file.close();
        }
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 3: grade too low to execute ---" << std::endl;
    try{
        RobotomyRequestForm robot("R2D2");
        Bureaucrat Intern("Intern", 150);
        Intern.signForm(robot);  // fails to sign (needs 72)
        Intern.executeForm(robot); // fails
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 4: RobotomyRequestForm, 50% chance ---" << std::endl;
    try{
        RobotomyRequestForm robot("R2D2");
        Bureaucrat Boss("Boss", 1);
        Boss.signForm(robot);
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
        Director.signForm(pardon);
        Director.executeForm(pardon);
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 6: low grade can sign but not execute ---" << std::endl;
    try{
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat Clerk("Clerk", 20);   // can sign (25) but not execute (5)
        Clerk.signForm(pardon);
        Clerk.executeForm(pardon);
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 7: grade 140 can sign Shrubbery (needs 145) but cannot execute (needs 137) ---" << std::endl;
    try{
        ShrubberyCreationForm shrub("garden");
        Bureaucrat Peon("Peon", 140);   // 140 <= 145: signs; 140 > 137: cannot execute
        Peon.signForm(shrub);
        shrub.execute(Peon);            // GradeTooLowException caught below
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 8: grade-1 bureaucrat signs and executes all three forms ---" << std::endl;
    try{
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("R2D2");
        PresidentialPardonForm pardon("Ford Prefect");
        Bureaucrat Boss("Boss", 1);
        Boss.signForm(shrub);
        Boss.executeForm(shrub);
        Boss.signForm(robot);
        Boss.executeForm(robot);
        Boss.signForm(pardon);
        Boss.executeForm(pardon);
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
