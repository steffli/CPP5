#pragma once

#include <string>
#include <iostream>
#include <exception>


class Bureuaucrat{
    private:
        const std::string name;
        int grade;

    public:
    //Default Constructor and Destructor, Canonical Form
    Bureuaucrat();
    Bureuaucrat(const std::string& name, int grade);
    Bureuaucrat(const Bureuaucrat& copy);
    Bureuaucrat& operator=(const Bureuaucrat& copy);
    ~Bureuaucrat();
    
    //public member functions
    std::string getName();
    int getGrade();
    void increaseGrade();
    void decreaseGrade();

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

std::ostream &operator<<(std::ostream &os, const Bureuaucrat &bureuaucrat);

