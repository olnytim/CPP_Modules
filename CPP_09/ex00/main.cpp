#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    switch (ac) {
        case 2: {
            try {
                BitcoinExchange exchange;
                exchange.readData(av[1]);
                exchange.printData();
                break;
            }
            catch (const std::exception &except) {
                cout << except.what() << endl;
            }
            break;
        }
        default:
            cout << "Usage: " << av[0] << " <filename>" << endl;
    }
}



