
#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: This program must takes 1 argument, the path\n";
		return (1);
	}

	try
	{
		BitcoinExchange btc(BITCOIN_EXCHANGE_DATABASE_PATH);
		//btc.printDatabase();
		btc.executeExchangeRate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << '\n';
	}
	

}
