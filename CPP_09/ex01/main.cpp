#include "RPN.hpp"

int main(int ac, char **av) {
    switch (ac) {
        case 2: {
            try {
                RNP rnp;
                rnp.parse(av[1]);
            }
            catch (const std::exception &except){
                cout << except.what() << endl;
            }
            break;
        }
        default:
            cout << "Usage: " << av[0] << " <expression>" << endl;
            break;
    }
    return 0;
}
