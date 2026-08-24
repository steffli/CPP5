#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150){
    std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name){

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Bureaucrat " << this->name << " constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
    std::cout << "Bureaucrat copy asignment operator called." << std::endl;
    if(this != &copy){
        this->grade = copy.grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat " << this->name << " destructor called." << std::endl;
}

const std::string& Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::increaseGrade(){
        if (this->grade <= 1)
            throw GradeTooHighException();
        this->grade--;
}

void Bureaucrat::decreaseGrade(){
        if (this->grade >= 150)
            throw GradeTooLowException();
        this->grade++;
}

void Bureaucrat::signForm(AForm &AForm){
    try {
        AForm.beSigned(*this);
        std::cout << this->name << " signed " << AForm.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->name << " couldn't sign " << AForm.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &AForm){
    try {
        AForm.execute(*this);
        std::cout << this->name << " executed " << AForm.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->name << " couldn't execute " << AForm.getName()
                  << " because " << e.what() << std::endl;
    }
}


const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low!";
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat){
    os << Bureaucrat.getName() << ", bureaucrat grade "
         << Bureaucrat.getGrade() << ".";
        return os;
}
