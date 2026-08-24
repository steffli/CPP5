#include "AForm.hpp"

class PresidentialPardonForm{
    private:
        const std::string name;
        int grade;

    public:
    //Default Constructor and Destructor, Canonical AForm
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& name, int grade);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
        ~PresidentialPardonForm();
        
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