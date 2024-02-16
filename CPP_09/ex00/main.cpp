#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    switch (ac) {
        case 2: {
            BitcoinExchange exchange;
            exchange.readData(av[1]);
            exchange.printData();
            break;
        }
        default:
            cout << "Usage: " << av[0] << " <filename>" << endl;
    }
}



