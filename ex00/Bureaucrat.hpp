#include <string>
#include <iostream>
#include <exception>

class exception{
    public:
        exception();
        exception(const exception&);
        exception& operator=(const exception&);
        virtual ~exception();
        virtual const char* what();
};

class Bureuaucrat : public exception{
    private:
        std::string name;
        int grade;
    public:
        Bureuaucrat();
        Bureuaucrat(int grade);
        Bureuaucrat& operator=(const Bureuaucrat& copy);
        ~Bureuaucrat();

        std::string getName();
        int getGrade();
        void increaseGrade();
        void decreseGrade();
};