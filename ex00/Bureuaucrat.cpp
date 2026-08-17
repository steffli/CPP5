#include "Bureaucrat.hpp"

Bureuaucrat::Bureuaucrat() : name("Default"), grade(150){
    std::cout << "Default constructor called." << std::endl;
}

Bureuaucrat::Bureuaucrat(const std::string& name, int grade) : name(name){

    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Bureaucrat " << this->name << " constructor called." << std::endl;
}

Bureuaucrat::Bureuaucrat(const Bureuaucrat& copy) : name(copy.name), grade(copy.grade){};

Bureuaucrat& Bureuaucrat::operator=(const Bureuaucrat& copy){
    std::cout << "Bureuaucrat copy asignment operator called." << std::endl;
    if(this != &copy){
        this->grade = copy.grade;
    }
    return *this;
}
Bureuaucrat::~Bureuaucrat(){
    std::cout << "Bureuaucrat destructor called." << std::endl;
}

const std::string& Bureuaucrat::getName() const{
    return this->name;
}

int Bureuaucrat::getGrade() const{
    return this->grade;
}

void Bureuaucrat::increaseGrade(){
        if (this->grade <= 1)
            throw GradeTooHighException();
        this->grade--;
}

void Bureuaucrat::decreaseGrade(){
        if (this->grade >= 150)
            throw GradeTooLowException();
        this->grade++;
}


const char* Bureuaucrat::GradeTooHighException::what() const throw(){
    return "Grade too high!";
}

const char* Bureuaucrat::GradeTooLowException::what() const throw(){
    return "Grade too low!";
}


std::ostream &operator<<(std::ostream &os, const Bureuaucrat &bureuaucrat){
    os << bureuaucrat.getName() << ", bureucrat grade "
         << bureuaucrat.getGrade() << ".";
        return os;
}