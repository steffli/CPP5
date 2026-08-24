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

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const{
    if(!this->is_Signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > grade_exec)
        throw AForm::GradeTooLowException();
    std::string filename = this->getName() + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open " << filename << std::endl;
        return ;
    }
    file << "  /\\" << std::endl;
    file << " /  \\" << std::endl;
    file << "/____\\" << std::endl;
    file << "  ||" << std::endl;
    file.close();
    std::cout << "Shrubbery written to " << filename << std::endl;
}