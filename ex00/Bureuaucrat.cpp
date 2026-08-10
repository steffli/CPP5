#include "Bureaucrat.hpp"

Bureuaucrat::Bureuaucrat(){
    std::cout << "Default constructor called." << std::endl;
}


        // Bureuaucrat();
        // Bureuaucrat(int grade);
Bureuaucrat& Bureuaucrat::operator=(const Bureuaucrat& copy){
    std::cout << "Bureuaucrat copy asignment operator called." << std::endl;
    if(this != &copy){
        this->name = copy.name;
        this->grade = copy.grade;
    }
}
Bureuaucrat::~Bureuaucrat(){
    std::cout << "Bureuaucrat destructor called." << std::endl;
}

        // std::string getName();
        // int getGrade();
        // void increaseGrade();
        // void decreseGrade();