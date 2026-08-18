#pragma once


#include "Bureaucrat.hpp"
#include <string>


class Form{
    private:
        const std::string name;
        bool is_Signed;
        const int grade_sign;
        const int grade_exec;
    
    public:
        Form();
        Form(const std::string& name, bool is_Signed, const int grade_req, const int grade_exec);
        Form(const Form &copy);
        Form& operator=(const Form& copy);
        ~Form();

        void beSigned(const Bureaucrat &bereaucrat);
        const std::string& getName() const;
        int getSignGrade() const;

        class GradeTooHighException : public std::exception{
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &os, const Form &form);