#include "RNP.hpp"

int main(int ac, char **av) {
    switch (ac) {
        case 2: {
            RNP rnp;
            rnp.parse(av[1]);
            rnp.polish();
            break;
        }
        default:
            cout << "Usage: " << av[0] << " <expression>" << endl;
            break;
    }
    return 0;
}
