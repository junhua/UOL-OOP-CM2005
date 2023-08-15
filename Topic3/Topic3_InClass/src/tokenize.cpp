#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Define a function named "tokenize" that takes a string "csvLine" and a character "sep" as input, and returns a vector of strings
std::vector<std::string> tokenize(std::string csvLine, char sep)
{
    // Create an empty vector of strings to store the tokens
    std::vector<std::string> tokens;
    // Declare three variables to keep track of the start and end positions of each token, and the token itself
    signed int start, end;
    std::string token;

    // Find the first non-separator character in the input string
    start = csvLine.find_first_not_of(sep);

    // Loop through the input string, finding each separator character and extracting the token between it and the previous separator
    do
    {
        // Find the next occurrence of the separator character
        end = csvLine.find_first_of(sep, start);

        // If no separator is found or if start == end, break out of the loop
        if (start == csvLine.length() || start == end)
            break;

        // Extract the substring between the current position and the separator
        if (end >= 0)
        {
            token = csvLine.substr(start, end - start);
        }
        else
        {
            token = csvLine.substr(start, csvLine.length() - start);
        }

        // Add the token to the vector of tokens
        tokens.push_back(token);

        // Update the starting position for the next iteration
        start = end + 1;
    } while (end > 0);

    // Return the vector of tokens
    return tokens; 
}

// int main()
// {
//     std::ifstream csvFile{"20200317.csv"};
//     std::string line;
//     std::vector<std::string> tokens;

//     if (csvFile.is_open())
//     {
//         while (std::getline(csvFile, line))
//         {
//             std::cout << "Read line: " << line << std::endl;
//             tokens = tokenize(line, ',');
//             if (tokens.size() != 5)
//             {
//                 std::cout << "Bad line " << std::endl;
//                 continue;
//             }
//             try
//             {
//                 double price = std::stod(tokens[3]);
//                 double amount = std::stod(tokens[4]);
//                 std::cout << price << " : " << amount << std::endl;
//             }
//             catch (std::exception &e)
//             {
//                 std::cout << "Bad float! " << tokens[3] << std::endl;
//                 std::cout << "Bad float! " << tokens[4] << std::endl;
//                 continue;
//             }
//         }
//         csvFile.close();
//     }
//     else
//     {
//         std::cout << "File is not open" << std::endl;
//     }
//     return 0;
// }