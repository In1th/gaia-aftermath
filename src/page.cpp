
#include "../include/page.h"
#include "../include/format.h"

#include <cmath>

volatile bool isSkipped = false;

void Page::display() {

    int name_l = name.length(), text_l = text.length();

    int i;

    if (this -> symbol != '0'){

        //HEAD
        print << UL_CORNER;
        sline(3);
        print << UR_CORNER;

        print << UL_CORNER;
        sline(NAME_CHAR_LIMIT+2);
        print << UR_CORNER << eol;

        print << V_LINE << " ";
        print << BOLD << BLUE << this->symbol << NORMAL << WHITE;
        print << " " << V_LINE << V_LINE << " ";
        print << BOLD << this->name << NORMAL;
        print << "\033[39G" << V_LINE << eol;

        print << LL_CORNER;
        sline(3);
        print << LR_CORNER;
        print << LL_CORNER;
        sline(NAME_CHAR_LIMIT+2);
        print << LR_CORNER<<eol;
    }

    //DIALUOGE
    this -> box(text_l/(BOX_CHAR_LIMIT) + 1, BOX_CHAR_LIMIT);

    for (int j = 0; j < text_l/(BOX_CHAR_LIMIT)+1; j++)
        print << "\033[F";

    print << "\033[3G";

    this -> wrap_text(this->text);

    print << eol << eol;

    //DECISIONS

    print << UL_CORNER;
    sline(BOX_CHAR_LIMIT+2);
    print << UR_CORNER<<eol;

    for (i = 0; i < this->decision_number;i++) {
        
        std::string number = BOLD+std::to_string(i+1)+")"+NORMAL+" ";

        this -> wrap_text(number+this -> decisions[i].second, false, this -> brackets);
        print << eol;
    
    }

    print << LL_CORNER;
    sline(BOX_CHAR_LIMIT+2);
    print << LR_CORNER<<eol;

    for (i = 0; i < this->decision_number-1;i++)
        print << eol; 
}

int Page::choice(int decided_number)
    {return this->decisions[decided_number-1].first;}       

void Page::box(int height, int width) {
    print << UL_CORNER;
    sline(width+2);
    print << UR_CORNER<<eol;

    for (int i = 0; i < height; i++){
        print << V_LINE;
        printf("\033[%dG",BOX_CHAR_LIMIT+4);
        print << V_LINE << eol;
    }

    print << LL_CORNER;
    sline(width+2);
    print << LR_CORNER;
}

void Page::brackets(void) {
    print << V_LINE << "\033[3G";
    printf("\033[%dG",BOX_CHAR_LIMIT+4);
    print << V_LINE << "\033[3G";
}

void Page::wrap_text(std::string text, bool delayed, void (*nl_function)(void)) {
    int pos = 0,
        abs_pos = 0;
    bool newline = true;

    for (char& c: text) {
        if (nl_function != NULL && newline) {
            nl_function();
            newline = false;
        }
        if (c != ' ' || pos != 0)
            print << c << std::flush;

        pos++;
        abs_pos++;

        if (pos == BOX_CHAR_LIMIT) {

            std::string word = "";

            if (text.at(abs_pos) != ' ') {
                int k = 1;
                while(text.at(abs_pos - k) != ' ') {
                    word = text.at(abs_pos - k) + word;
                    k++;
                    printf("\033[%dG",4+pos-k);
                    print << " " << std::flush;
                }
            }

            pos = word.length();
            print << eol << "\033[3G" << word;
            newline = true;
        }

        if (delayed & !isSkipped) 
            usleep(20000);
    }

    isSkipped = false;
}