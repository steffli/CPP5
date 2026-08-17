#include "Bureaucrat.hpp"


int main(){

    try{
        Bureuaucrat Tina("Tina",151);
  
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}