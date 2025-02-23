#include <iostream>

int main() {
    // Program-level variable
    int x = 5;
    std::cout << "Outside any block: x = " << x << std::endl;

    {
        // First nested block
        int y = 10;
        std::cout << "Inside first block: x = " << x << ", y = " << y << std::endl;
        
        {
            // Second nested block
            int z = 15;
            std::cout << "Inside second block: x = " << x << ", y = " << y << ", z = " << z << std::endl;
        } // z goes out of scope here
        
        std::cout << "Back to first block: x = " << x << ", y = " << y << std::endl;
    } // y goes out of scope here

    std::cout << "Back to main scope: x = " << x << std::endl;
    
    return 0;
}
