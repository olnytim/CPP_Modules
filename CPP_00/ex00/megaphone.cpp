#include <iostream>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else {
        for (int i = 1; i < ac; ++i) {
            for (int j = 0; av[i][j]; ++j) {
                char c = av[i][j];
                if (c >= 'a' && c <= 'z') {
                    c = c - 'a' + 'A';
                }
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }
    return (0);
}