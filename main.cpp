
#include "include/includes.h"

#include <vector>
#include <sstream>
#include <string>
#include <unistd.h>

const bool test_version = true;

void eq(Stack<item_ptr> &s, std::vector<std::string> option);

const std::string player = "gracz";

bool koniec = false;

int main(int argc, char *argv[]) {

    Stack<item_ptr> ekwipunek{};
Item::Consumable("Jabłko",1.5,10,1);


    ekwipunek.push(new Item::Consumable("Jabłko",1.5,10,1));

    system("clear");

    std::string opcja;

    std::vector<std::string> command{};

    std::string s;

    print << "By wyświetlić listę komend wpisz \"eq help\" " << eol;
    print << "exit - wyjdź" << eol;

    while (!koniec) {


        print << BOLD << BLUE << player << NORMAL << WHITE << ": >>> ";

        opcja = "";

    
        do {
        std::getline(std::cin, opcja);
        } while(opcja == "");

        std::istringstream iss(opcja);

        while(std::getline(iss,s, ' ')) {
            command.push_back(s.c_str());
        }

        if (command.at(0) == "eq")
            eq(ekwipunek,command);

        else if (command.at(0) == "exit")
            koniec = true;

        else 
            print << ERROR <<" Niewłaściwa komenda!" << eol;

        command.clear();

    }

}

void eq(Stack<item_ptr> &s,std::vector<std::string> option) {

    std::string command;

    if (option.size() == 1)
        command = "help";
    else
        command = option.at(1);
    

    if (command == "help") {
        print << EKWIPUNEK <<" opcje "; line(29);
        print << BOLD<<"eq show"<<NORMAL<<" - pokaż ekwipunek" << eol;
        print << BOLD<< "eq inspect"<<NORMAL<<" <index> - inspektuj przedmiot" << eol;
        print << BOLD<<"eq swap"<<NORMAL<<" <index1> <index2> - zamień przedmioty" << eol;
        print << BOLD<<"eq throw"<<NORMAL<<" <index> - wyrzuć przedmiot" << eol;
        if (test_version) {
            print << DEBUG << " POLECENIA DEWELOPERSKIE" << eol;
            print << BOLD<<"eq size"<<NORMAL<<" - wypisz wielkość ekwipunku" << eol;
            print << BOLD<<"eq pickup"<<NORMAL<<" - podnieś przedmiot" << eol;
        }
    }

    else if (command == "show")
        show(s);

    else if (command == "inspect") {
        if (option.size() < 3)
            print << ERROR << ": Brak argumentu index! Wpisz \"eq help\" by wypisać listę komend" << eol;        
        else
            inspect(s,std::atoi(&option.at(2).at(0)));
    }

    else if (command == "swap") {
        if (option.size() < 3 || std::atoi(&option.at(2).at(0)) > s.size())
            print << ERROR << ": Nieprawidłowy argument index1! Wpisz \"eq help\" by wypisać listę komend" << eol; 
        else if (option.size() < 4 || std::atoi(&option.at(3).at(0)) > s.size())
            print << ERROR << ": Nieprawidłowy argument index2! Wpisz \"eq help\" by wypisać listę komend" << eol; 
        else 
            s.swap(std::atoi(&option.at(2).at(0)),std::atoi(&option.at(3).at(0)));      

    }


    else if (command == "throw") {
        if (option.size() < 3 || std::atoi(&option.at(2).at(0)) > s.size())
            print << ERROR << ": Nieprawidłowy argument index! Wpisz \"eq help\" by wypisać listę komend" << eol;     
        else 
            i_throw(s,std::atoi(&option.at(2).at(0)));
        
    }

    else if (command == "size")
        print << DEBUG << " " << s.size() << eol;

    else if (command == "pickup")
        add(s);

    else
        print << ERROR << ": Niewłaściwa komenda! Wpisz \"eq help\" by wypisać listę komend" << eol;        

}