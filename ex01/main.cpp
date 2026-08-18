#include "Bureaucrat.hpp"


int main(){

    std::cout << "--- Test 1: valid construction + operator<< ---" << std::endl;
    try{
        Bureaucrat Tina("Tina", 2);
        std::cout << Tina << std::endl;
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 2: boundary grades 1 and 150 are VALID ---" << std::endl;
    try{
        Bureaucrat Boss("Boss", 1);
        std::cout << Boss << std::endl;
        Bureaucrat Intern("Intern", 150);
        std::cout << Intern << std::endl;
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 3: grade too low at construction (151) ---" << std::endl;
    try{
        Bureaucrat Lazy("Lazy", 151);
        std::cout << "This line never runs" << std::endl;
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 4: grade too high at construction (0) ---" << std::endl;
    std::cout << "(catching the specific custom exception type here)" << std::endl;
    try{
        Bureaucrat Napoleon("Napoleon", 0);
        std::cout << "This line never runs" << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e){
        std::cout << "Caught specifically: " << e.what() << std::endl;
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 5: increaseGrade overflow at grade 1 ---" << std::endl;
    try{
        Bureaucrat Tina("Tina", 2);
        std::cout << Tina << std::endl;
        Tina.increaseGrade();          // 2 -> 1, fine
        std::cout << Tina << std::endl;
        Tina.increaseGrade();          // 1 -> would be 0, throws
        std::cout << "This line never runs" << std::endl;
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 6: decreaseGrade underflow at grade 150 ---" << std::endl;
    try{
        Bureaucrat Jim("Jim", 150);
        std::cout << Jim << std::endl;
        Jim.decreaseGrade();           // 150 -> would be 151, throws
        std::cout << "This line never runs" << std::endl;
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 7: normal inc/dec within valid range ---" << std::endl;
    try{
        Bureaucrat Tina("Tina", 75);
        Tina.increaseGrade();          // 75 -> 74
        Tina.increaseGrade();          // 74 -> 73
        Tina.decreaseGrade();          // 73 -> 74
        std::cout << Tina << " (expected grade 74)" << std::endl;
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Test 8: copy constructor + assignment operator ---" << std::endl;
    try{
        Bureaucrat Original("Original", 42);
        Bureaucrat Clone(Original);
        std::cout << Clone << std::endl;        // name AND grade copied
        Bureaucrat Assigned("Assigned", 100);
        Assigned = Original;                    // grade copied, name stays (name is const)
        std::cout << Assigned << std::endl;     // "Assigned, bureaucrat grade 42."
    }
    catch (std::exception &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
