#include <iostream>
#include <fstream>

int main() {

    std::fstream file;
    
    int number;
    bool narrator;
    char frakcja;
    std::string nazwa;
    int liczba_opcji;
    std::string tekst;


    file.open("../src/resc/properties");

    file >> number;

    std::cout << "Czy to wypowiedź narratora? (0- nie, 1 - tak): ";
    std::cin >> narrator;

    if (!narrator) {
        std::cout << "Podaj znak frakcji rozmówcy: ";
        std::cin >> frakcja;
        std::cout << "Podaj nazwe rozmówcy: ";
        std::cin >> nazwa;
    }

    return 0;
}