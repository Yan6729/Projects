/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** MyCat
*/

#include <fstream>
#include <string>
#include <iostream>
#include <vector>

class  MyCat
{
    public:
        std::vector<std::string> args;
        int number;
        
        int readFile (std::string file) {
            std::string content;
            std::ifstream inputFile(file);

            if (!inputFile.is_open()) {
                std::cerr << "MyCat: " << file << ": No such file or directory" << std::endl;
                return 84;
            }
            while (std::getline (inputFile, content))
            {
                std::cout << content << std::endl;
            }

            inputFile.close();
            return 0;
        }

        int readMultiFile(void)
        {
            int retour = 0;

            for (int a = 1; a < (number); a++) {
                if (readFile(args[a]) == 84)
                   retour = 84;
            }
            return retour;
        }
        MyCat(std::vector<std::string> tab, int ac) : args(tab), number(ac) {};
        ~MyCat() {};
};

void readEntry(void)
{
    std::string line;

    while (getline(std::cin, line)) {
        std::cout << line << std::endl;
    }
}

int main(int ac, char **av)
{
    std::vector<std::string> args;

    if (ac == 1)
        readEntry();
    for (int a = 0; a < ac; a++)
        args.push_back(av[a]);
    
    MyCat file(args, ac);
    return file.readMultiFile();
}