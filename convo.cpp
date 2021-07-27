#include "include/page.h"
#include "include/format.h"
#include <string>

int main() {

    Page p;
    p.symbol = '0';
    p.name = "Test";
    p.text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    p.decision_number = 2;
    p.decisions[0].first = 0;
    p.decisions[0].second = "Nie";
    p.decisions[1].first = 0;
    p.decisions[1].second = "Tak";


    p.display();
}