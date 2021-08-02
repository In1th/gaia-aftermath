#include <iostream>
#include <fstream>
#include <vector>

int main()
{

    std::fstream file;
    std::ofstream sfile;

    int number;
    bool narrator;
    std::string frakcja;
    std::string nazwa;
    int liczba_opcji;
    std::string tekst;

    file.open("./resc/properties");

    if (file.is_open())
    {
        file >> number;
        file.close();

        number++;
        std::string nazwa_pliku = std::to_string(number);

        sfile.open("./resc/story/" + nazwa_pliku + ".dat");
        sfile << number << " ";

        std::cout << "Podaj liczbę wyborów postaci (min 1, max 4): ";
        std::cin >> liczba_opcji;
        sfile << liczba_opcji << " ";

        std::cout << "Czy to wypowiedź narratora? (0- nie, 1 - tak): ";
        std::cin >> narrator;
        sfile << narrator << " ";

        if (!narrator)
        {
            std::cout << "Podaj znak frakcji rozmówcy: ";
            std::cin.ignore();
            std::getline(std::cin,frakcja,'\n');
            std::cout << "Podaj nazwe rozmówcy: ";
            std::getline(std::cin,nazwa,'\n');

            sfile << frakcja << "\n" << nazwa << "\n";
        }

        std::cout << "Podaj tekst (bez entera): ";
        std::getline(std::cin, tekst,'\n');

        sfile << tekst << "\n";

        for (int i = 0; i < liczba_opcji; i++) {
            int bufor;

            std::cout << std::endl << "OPCJA DIALOGOWA NUMER "<<i+1<<std::endl;

            sfile << "!1 ";
            std::cout << "Warunek na ukazanie opcji\n";
            std::cout << "Podaj numer warunku do sprawdzenia (0 - 7) ";
            std::cin >> bufor;
            sfile << bufor << " ";
            if (bufor == 0)
                sfile << "0\n";
            else {
                std::cout << "Podaj wartość warunku która musi być spełniona (0 - 99) ";
                std::cin >> bufor;
                if (bufor < 10)
                    sfile << "0" << bufor << "\n";
                else
                    sfile << bufor << "\n";

            }

            sfile << "!2 ";
            std::cout << "Warunek przy wybraniu opcji\n";
            std::cout << "Podaj numer warunku do sprawdzenia (0 - 7) ";
            std::cin >> bufor;
            sfile << bufor << " ";
            if (bufor == 0) {
                sfile << "0 ";
                std::cout << "Podaj numer skryptu, do którego ma przejść gracz: ";
                std::cin >> bufor;  
                if (bufor < 10)
                    sfile << "0" << bufor << " 00\n";
                else
                    sfile << bufor << " 00\n";
            }
            else {
                std::cout << "Podaj wartość warunku która musi być spełniona (0 - 99) ";
                std::cin >> bufor;
                if (bufor < 10)
                    sfile << "0" << bufor << " ";
                else
                    sfile << bufor << " ";
                
                std::cout << "Podaj numer skryptu, do którego ma przejść gracz przy powodzeniu: ";
                std::cin >> bufor;
                sfile << bufor << " ";
                std::cout << "Podaj numer skryptu, do którego ma przejść gracz przy niepowodzeniu: ";
                std::cin >> bufor;
                sfile << bufor << "\n";
            }


                sfile << "!3 ";
                std::cout << "Czy po ma być dany przedmiot po tym wyborze? (0 - nie, 1 - tak) ";
                std::cin >> bufor;
                if (!bufor)
                    sfile << "0 0 00\n";
                else {
                    std::cout << "To jest jeszcze do wdrożenia ~Inith\n";
                    sfile << "0 0 00\n";
                }

                sfile << "!4 ";
                std::cout << "Czy po ma się rozpocząć walka po tym wyborze? (0 - nie, 1 - tak) ";
                std::cin >> bufor;
                if (!bufor)
                    sfile << "0 0 00\n";
                else {
                    std::cout << "To jest jeszcze do wdrożenia ~Inith\n";
                    sfile << "0 0 00\n";
                }

                std::cout << "Podaj teraz tekst wyboru (bez entera): ";
                std::cin.ignore();
                std::getline(std::cin,tekst,'\n');
                sfile << tekst << "\n";
                
            
        }

        sfile << "@\n"; //do przedmiotów
        sfile << "#\n"; //do walki

        file.close();
        sfile.close();
    }
    else
        std::cout << "Nie udało się otworzyć pliku" << std::endl;

    return 0;
}