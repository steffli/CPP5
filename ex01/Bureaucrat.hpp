#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"


class Bureaucrat{
    private:
        const std::string name;
        int grade;

    public:
    //Default Constructor and Destructor, Canonical Form
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& copy);
    ~Bureaucrat();
    
    //public member functions
    const std::string& getName() const;
    int getGrade() const;
    void increaseGrade();
    void decreaseGrade();

    void signForm(const Form &form);

    //Custom exception classes: due to inherihance it just picks the right exception
    class GradeTooHighException : public std::exception{
        public:
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &Bureaucrat);

