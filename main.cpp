/* ===========================================
 * main.cpp file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 25.05.2021
 * ===========================================
 * version: 0.1.0-a.1 [backpack]
 * ===========================================
 */

//include all header files
#include "include/includes.h"

#include <sstream>

//eq commands handling
void eq(Stack<item_ptr> &bufor, std::vector<std::string> option); //[TODO] move it to the other file (F00001)

const bool test_version = true;
const std::string version = "v0.1.0-a.1";
const std::string player = "gracz"; //[TODO] player name input (F00002)

bool koniec = false;

int main(int argc, char *argv[]) {

    Stack<item_ptr> ekwipunek{};

    //item example
    Item::Consumable("Jabłko",1.5,10,1);
    ekwipunek.push(new Item::Consumable("Jabłko",1.5,10,1));

    print << CLEAR;

    std::string option;
    std::vector<std::string> command{};
    std::string bufor;

    print << BOLD << MAGENTA << version << WHITE << NORMAL << eol;
    print << "By wyświetlić listę komend wpisz \"eq help\" " << eol;
    print << "exit - wyjdź" << eol;

    while (!koniec) { //game loop

        print << BOLD << BLUE << player << NORMAL << WHITE << ": >>> ";

        option = "";

        //get command line and split it into separate strings
    
        do {
        std::getline(std::cin, option);
        } while(option == "");

        std::istringstream iss(option);

        while(std::getline(iss,bufor, ' ')) {
            command.push_back(bufor.c_str());
        }

        if (command.at(0) == "eq") //recognize eq command lines
            eq(ekwipunek,command);

        else if (command.at(0) == "exit") //recognize exit command
            koniec = true;

        else  //error handling
            print << ERROR <<" Niewłaściwa komenda!" << eol;

        command.clear();

    }

}

void eq(Stack<item_ptr> &bufor,std::vector<std::string> option) {

    std::string command;

    if (option.size() == 1) //if no 2nd command, assign it to help
        command = "help";
        
    else
        command = option.at(1);
    

    if (command == "help") { // eq help command
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


    else if (command == "show") //eq show command
        show(bufor);


    else if (command == "inspect") { // eq inspect command
        if (option.size() < 3)
            print << ERROR << ": Brak argumentu index! Wpisz \"eq help\" by wypisać listę komend" << eol;    

        else
            inspect(bufor,std::atoi(&option.at(2).at(0)));
    }


    else if (command == "swap") { //eq swap command
        if (option.size() < 3 || std::atoi(&option.at(2).at(0)) > bufor.size())
            print << ERROR << ": Nieprawidłowy argument index1! Wpisz \"eq help\" by wypisać listę komend" << eol; 

        else if (option.size() < 4 || std::atoi(&option.at(3).at(0)) > bufor.size())
            print << ERROR << ": Nieprawidłowy argument index2! Wpisz \"eq help\" by wypisać listę komend" << eol; 

        else 
            bufor.swap(std::atoi(&option.at(2).at(0)),std::atoi(&option.at(3).at(0)));      

    }


    else if (command == "throw") { //eq throw command
        if (option.size() < 3 || std::atoi(&option.at(2).at(0)) > bufor.size())
            print << ERROR << ": Nieprawidłowy argument index! Wpisz \"eq help\" by wypisać listę komend" << eol;     
        else 
            i_throw(bufor,std::atoi(&option.at(2).at(0)));
        
    }


    else if (command == "size") //eq size command
        print << DEBUG << " " << bufor.size() << eol;


    else if (command == "pickup") //eq pickup command
        add(bufor);


    else //error handling
        print << ERROR << ": Niewłaściwa komenda! Wpisz \"eq help\" by wypisać listę komend" << eol;        

}