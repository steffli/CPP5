#pragma once


#include "Bureaucrat.hpp"
#include <string>


class AForm{
    private:
        const std::string name;
        bool is_Signed;
        const int grade_sign;
        const int grade_exec;
    
    public:
        AForm();
        AForm(const std::string& name, bool is_Signed, const int grade_req, const int grade_exec);
        AForm(const AForm &copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();

        void beSigned(const Bureaucrat &bereaucrat);
        const std::string& getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getIsSigned() const;

        virtual void execute(const Bureaucrat &executor) const = 0;

        class GradeTooHighException : public std::exception{
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception{
            public:
                const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &os, const AForm &AForm);