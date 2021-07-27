
#include <iostream>
#include <unistd.h>
#include <map>

#define DECISION_MAX 4

class Page {

    public:

        int ID;
        char symbol;
        std::string name;
        std::string text;

        int decision_number;
        std::pair<int, std::string> decisions[DECISION_MAX];

        void display();
        inline int choice(int);

        static inline void box(int,int);
        static inline void brackets(void);
        static void wrap_text(std::string, bool delayed = true, void (*nl_function)(void) = NULL);



};