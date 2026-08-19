#include "AForm.hpp"


AForm::AForm() : name("Default"), is_Signed(false), grade_sign(150), grade_exec(50){
    std::cout << "Default AForm constructor called." << std::endl;
}

AForm::AForm(const std::string& name, bool is_Signed, int grade_req, int grade_exec):
             name(name), is_Signed(false), grade_sign(grade_req), grade_exec(grade_exec)
{
    if (grade_exec < 1)
        throw GradeTooHighException();
    else if (grade_exec > grade_sign || grade_exec > 150)
        throw GradeTooLowException();
    else if (grade_exec < grade_sign)
        is_Signed = true;
    std::cout << "AForm " << this->name << " constructor called." << std::endl;
}

AForm::AForm(const AForm &copy):name(copy.name), is_Signed(copy.is_Signed), 
            grade_sign(copy.grade_sign), grade_exec(copy.grade_exec){};

AForm& AForm::operator=(const AForm& copy){
    std::cout << "AForm copy assignment " << std::endl;
        if (this != &copy){
            this->is_Signed = copy.is_Signed;
        }
    return *this;
}

AForm::~AForm(){
    std::cout << this->name << " AForm destructor called." << std::endl;
}


int AForm::getSignGrade() const{
    return this->grade_sign;
}

int AForm::getExecGrade() const{
    return this->grade_exec;
}

bool AForm::getIsSigned() const{
    return this->is_Signed;
}

const std::string& AForm::getName() const{
    return this->name;
}

void AForm::beSigned(const Bureaucrat &bereaucrat){
    if (bereaucrat.getGrade() <= this->grade_sign)
    {
        this->is_Signed = true;
    }
    else{
       throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "Form not signed!";
}