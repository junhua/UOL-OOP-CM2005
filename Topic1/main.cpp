#include <iostream>

void print_plot();
void print_lineplot();
void print_plot(){

std::cout << "10 |                                                   " << std::endl;
std::cout << " 9 |        |                                 |        " << std::endl;
std::cout << " 8 |        |                                ---       " << std::endl;
std::cout << " 7 |       +++                               ---       " << std::endl;
std::cout << " 6 |       +++               |               ---       " << std::endl;
std::cout << " 5 |       +++               |                |        " << std::endl;
std::cout << " 4 |        |               ---               |        " << std::endl;
std::cout << " 3 |        |               ---               |        " << std::endl;
std::cout << " 2 |        |                |                |        " << std::endl;
std::cout << " 1 |                         |                         " << std::endl;
std::cout << "-------------------------------------------------------" << std::endl;
std::cout << "        1980/01           1980/02          1980/03     " << std::endl;
}

void print_lineplot(){

std::cout << "10 |                                                   " << std::endl;
std::cout << " 9 |                                                   " << std::endl;
std::cout << " 8 |                                                   " << std::endl;
std::cout << " 7 |                                                   " << std::endl;
std::cout << " 6 |          --              --                       " << std::endl;
std::cout << " 5 |        --  --          --                         " << std::endl;
std::cout << " 4 |      --      --      --                           " << std::endl;
std::cout << " 3 |                --  --                             " << std::endl;
std::cout << " 2 |                  --                               " << std::endl;
std::cout << " 1 |                                                   " << std::endl;
std::cout << "-------------------------------------------------------" << std::endl;
std::cout << "        1980/01           1980/02          1980/03     " << std::endl;
}

int main(){
    print_plot();
    return 0;
}