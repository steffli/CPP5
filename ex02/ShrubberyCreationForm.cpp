#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", false, 145, 137){
    std::cout << "Shrubbery constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, false, 145, 137){
    std::cout << "ShrubberyCreationForm " << this->name << " constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy){
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy){
    std::cout << "ShrubberyCreationForm copy asignment operator called." << std::endl;
    if(this != &copy){
        AForm::operator=(copy);
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm " << this->name << " destructor called." << std::endl;
}