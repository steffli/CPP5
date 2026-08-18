#include "Form.hpp"


Form::Form() : name("Default"), is_Signed(false), grade_sign(150), grade_exec(50){
    std::cout << "Default Form constructor called." << std::endl;
}

Form::Form(const std::string& name, bool is_Signed, int grade_req, int grade_exec):
             name(name), is_Signed(false), grade_sign(grade_sign), grade_exec(grade_exec)
{
    if (grade_exec < 1)
        throw GradeTooHighException();
    else if (grade_exec > grade_sign || grade_exec > 150)
        throw GradeTooLowException();
    else if (grade_exec < grade_sign)
        is_Signed = true;
    std::cout << "Form " << this->name << " constructor called." << std::endl;
}

Form::Form(const Form &copy):name(copy.name), is_Signed(copy.is_Signed), 
            grade_sign(copy.grade_sign), grade_exec(copy.grade_exec){};

Form& Form::operator=(const Form& copy){
    std::cout << "Form copy assignment " << std::endl;
        if (this != &copy){
            this->is_Signed = copy.is_Signed;
        }
    return *this;
}

Form::~Form(){
    std::cout << this->name << " Form destructor called." << std::endl;
}


void Form::beSigned(const Bureaucrat &bereaucrat){
    if (bereaucrat.getGrade() <= this->grade_sign)
    {
        this->is_Signed = true;
        std::cout << "Bereaucrat " << bereaucrat.getName() << " signed " << this->name << " Form." << std::endl;
    }
    else{
       throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade too low!";
}