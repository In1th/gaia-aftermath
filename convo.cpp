#include "include/page.h"
#include "include/format.h"
#include <string>
#include <fstream>
#include <sstream>
#include <deque>

Page *exportID(int id);

int main()
{

    Page *p = exportID(1);

    /*p.symbol = '0';
    p.name = "Test";
    p.text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    p.decision_number = 2;
    p.decisions[0].first = 0;
    p.decisions[0].second = "Nie";
    p.decisions[1].first = 0;
    p.decisions[1].second = "Tak";*/

    p->display();

    return 0;
}

Page *exportID(int id)
{

    std::ifstream f;
    Page *output = new Page();

    std::string name = std::to_string(id);
    f.open("./src/resc/story/" + name + ".dat");
    if (f.is_open())
    {
        std::string line;
        std::deque<std::string> file;
        while(std::getline(f,line))
            file.push_back(line);
        std::string buf_string;
        int buf_int;
        int iterator = 0;
        std::istringstream iss(file.at(iterator));
        iterator++;
        iss >> buf_int;
        if (id == buf_int) {

            output->ID = id;
            iss >> buf_string;
            output->decision_number = std::stoi(buf_string);

            iss >> buf_string;

            if ("1" == buf_string) 
                output->symbol='0';
            else {
                iss >> buf_string;
                output->symbol=*buf_string.c_str();
                output->name = file.at(iterator);
                iterator++;
            }

            output->text=file.at(iterator);
            iterator++;

            for (int i = 0; i < output->decision_number; i++){
                for (int j = 0; j < 4; j++){
                    std::istringstream iss(file.at(iterator));
                    iss >> buf_string;
                    if (buf_string == "!2") {
                        iss >> buf_int;
                        iss >> buf_int;
                        iss >> buf_int;
                        output->decisions[i].first = buf_int;
                        iss >> buf_int;
                    }
                    iterator++;
                }
                output->decisions[i].second = file.at(iterator);
                iterator++;
            }

        }
        else
            print << "ID podane i w pliku się nie zgadzają!" << eol;
        f.close();
    }
    else
        print << "Nie ma" << eol;

    return output;
}