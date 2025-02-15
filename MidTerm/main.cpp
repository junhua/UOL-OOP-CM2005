#include <iostream>
#include <string>

int main()
{

    std::string plot;

    plot += "7 |      |                      \n";
    plot += "6 |      |       |\n";
    plot += "5 |   ++++++   ------\n";
    plot += "4 |   +    +   -    -\n";
    plot += "3 |   +    +   ------  \n";
    plot += "2 |   ++++++     |\n";
    plot += "1 |      |\n";
    plot += "0 |\n";
    plot += " -------------------------------\n";
    plot += "         1       2       \n";

    std::cout << plot << std::endl;

    return 0;
}


// void print_plot();
// void print_lineplot();
// void print_plot(){


// std::cout << "10 |                                                   " << std::endl;
// std::cout << " 9 |        |                                 |        " << std::endl;
// std::cout << " 8 |        |                                ---       " << std::endl;
// std::cout << " 7 |       +++                               ---       " << std::endl;
// std::cout << " 6 |       +++               |               ---       " << std::endl;
// std::cout << " 5 |       +++               |                |        " << std::endl;
// std::cout << " 4 |        |               ---               |        " << std::endl;
// std::cout << " 3 |        |               ---               |        " << std::endl;
// std::cout << " 2 |        |                |                |        " << std::endl;
// std::cout << " 1 |                         |                         " << std::endl;
// std::cout << "-------------------------------------------------------" << std::endl;
// std::cout << "        1980/01           1980/02          1980/03     " << std::endl;
// }

// void print_lineplot(){

// std::cout << "10 |                                                   " << std::endl;
// std::cout << " 9 |                                        ----       " << std::endl;
// std::cout << " 8 |                                      --           " << std::endl;
// std::cout << " 7 |                            --      --             " << std::endl;
// std::cout << " 6 |          --              --  --  --               " << std::endl;
// std::cout << " 5 |        --  --          --      --                 " << std::endl;
// std::cout << " 4 |      --      --      --                           " << std::endl;
// std::cout << " 3 |                --  --                             " << std::endl;
// std::cout << " 2 |                  --                               " << std::endl;
// std::cout << " 1 |                                                   " << std::endl;
// std::cout << "-------------------------------------------------------" << std::endl;
// std::cout << "        1980/01           1980/02          1980/03     " << std::endl;
// }


// int main(){
//     // print_plot();
//     // print_lineplot();
//     return 0;
// }