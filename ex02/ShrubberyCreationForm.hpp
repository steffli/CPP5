#include "AForm.hpp"


class ShrubberyCreationForm{
    private:
        const std::string name;
        int grade;

    public:
    //Default Constructor and Destructor, Canonical AForm
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& name, int grade);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm();
        
        //public member functions
        const std::string& getName() const;
        int getGrade() const;
        void increaseGrade();
        void decreaseGrade();

        void signAForm(AForm &AForm);
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