#pragma once

#include <string>
#include <iostream>
#include <exception>

class AForm;


class Bureaucrat{
    private:
        const std::string name;
        int grade;

    public:
    //Default Constructor and Destructor, Canonical AForm
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

        void signForm(AForm &AForm);
        void executeForm(const AForm &AForm);

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



