/* ===========================================
 * eq.cpp file
 * ===========================================
 * author: Mateusz Kruk
 * e-mail: krukm634@gmail.com
 * last modified: 25.05.2021
 * ===========================================
 * version: 0.1.0-a.1 [backpack]
 * ===========================================
 */

#include "../include/eq.h"
#include "../include/format.h"
#include <sstream>
#include <algorithm> 

template <typename T>
int Stack<T>::size()
{
    return this->stack.size();
}

template <typename T>
void Stack<T>::push(T obj)
{
    this->stack.push_back(obj);
}

template <typename T>
T Stack<T>::at(int index)
{
    return this->stack.at(index);
}

template <typename T>
void Stack<T>::remove(int index)
{
    this->stack.erase(this->stack.begin() + index);
}

template <typename T>
void Stack<T>::insert(T obj, int index)
{
    this->stack.insert(this->stack.begin() + index, obj);
}

template <typename T>
void Stack<T>::swap(int index1, int index2)
{
    T bufor = this->at(index1-1);
    if (index1 > index2) {
        int b = index1;
        index1 = index2;
        index2 = b;
    }
    std::replace(this->stack.begin(),this->stack.end(),bufor,this->at(index2 - 1));
    std::replace(this->stack.begin()+index1,this->stack.end(),this->at(index2 - 1),bufor);
}

void show(Stack<Item::Instance *> s)
{
    int size = s.size();

    print << BOLD << " Numer \u2502 Nazwa przedmiotu"
          << "\033[48G \u2502"
          << " Ilość \u2502 Wartość" << NORMAL << eol;
    print << BOLD << "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2534\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2534\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2534\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500" << NORMAL << eol;

    std::string name, type, quantity;

    if (size == 0)
    {
        print << "Brak . . . " << eol;
    }
    else
    {

        for (int i = 0; i < size; i++)
        {
            s.at(i)->get_attribute(1, name);
            s.at(i)->get_attribute(0, type);
            s.at(i)->get_attribute(2, quantity);
            if (type == "Stackable" || type == "Consumable")
            {

                std::string ilosc;
                s.at(i)->get_attribute(3, ilosc);
                print << BRIGHT_BLACK << "\033[4G" << i + 1 << " " << WHITE << "\033[10G" << name << "\033[52Gx" << ilosc << "\033[59G" << quantity << eol;
            }
            else
                print << BRIGHT_BLACK << "\033[4G" << i + 1 << " " << WHITE << "\033[10G" << name << "\033[52Gx"
                      << "1"
                      << "\033[59G" << quantity << eol;
        }
    }
}

void inspect(Stack<Item::Instance *> s, int index)
{
    s.at(index - 1)->inspect();
}

void i_throw(Stack<item_ptr> &s, int index)
{
    std::string name, o;

    item_ptr to_delete = s.at(index - 1);
    to_delete->get_attribute(1, name);
    print << WARNING
          << " Czy jesteś pewnien usunięcia przedmiotu "
          << BOLD << name << NORMAL
          << " (indeks " << index << ") ? "
          << BOLD << "[" << GREEN << " T" << WHITE << " /" << RED << " n" << WHITE << " ]" << NORMAL ": ";

    std::cin >> o;
    if (o == "T" || o == "t")
    {
        s.remove(index - 1);
        print << SUCCESS <<" Pomyślnie wyrzucono przedmiot!" << eol;
        delete to_delete;
    }
}

void add(Stack<item_ptr> &s)
{

    std::vector<std::string> labels;

    labels.push_back("  > value quantity quantity_cap");
    labels.push_back("  > value quantity quantity_cap effect effect_level duration");
    labels.push_back("  > quantity");
    labels.push_back("  > value armour_type protection");
    labels.push_back("  > value protection effect effect_level duration iswearable istwohended");
    labels.push_back("  > value weapon_type damage istwohanded");
    labels.push_back("  > value weapon_type damage range istwohanded");

    print << BOLD << "1" << NORMAL << " - Stackable" << eol;
    print << BOLD << "2" << NORMAL << " - Consumable" << eol;
    print << BOLD << "3" << NORMAL << " - NonStackable" << eol;
    print << BOLD << "4" << NORMAL << " - Armour" << eol;
    print << BOLD << "5" << NORMAL << " - Defensive_Item" << eol;
    print << BOLD << "6" << NORMAL << " - Melee_Weapon" << eol;
    print << BOLD << "7" << NORMAL << " - Ranged_Weapons" << eol;

    int i;
    print << DEBUG << ": >>> ";
    std::cin >> i;

    std::string attr_str, str, name;

    print << DEBUG << " Wprowadź nazwę, a potem resztę atrybutów zgodnie z instrukcją" << eol;
    print << labels.at(i - 1) << eol;
    print << DEBUG << ": >>> ";

    do
    {
        std::getline(std::cin, name);
    } while (name == "");

    print << DEBUG << ": >>> ";

    do
    {
        std::getline(std::cin, attr_str);
    } while (attr_str == "");

    std::vector<std::string> attrs;

    std::istringstream iss(attr_str);

    while (std::getline(iss, str, ' '))
    {
        attrs.push_back(str.c_str());
    }

    item_ptr ptr;

    switch (i)
    {
    case 1:
        ptr = new Item::Stackable(name,                           //name
                                  std::atof(&attrs.at(0).at(0)),  //value
                                  std::atoi(&attrs.at(1).at(0)),  //quantity
                                  std::atoi(&attrs.at(2).at(0))); //quantity cap
        break;

    case 2:
        ptr = new Item::Consumable(name,                           //name
                                   std::atof(&attrs.at(0).at(0)),  //value
                                   std::atoi(&attrs.at(1).at(0)),  //quantity
                                   std::atoi(&attrs.at(2).at(0)),  //quantity cap
                                   std::atoi(&attrs.at(3).at(0)),  //effect
                                   std::atoi(&attrs.at(4).at(0)),  //effect level
                                   std::atoi(&attrs.at(5).at(0))); //duration
        break;

    case 3:
        ptr = new Item::Non_Stackable(name,                           //name
                                      std::atof(&attrs.at(0).at(0))); //value
        break;

    case 4:
        ptr = new Item::Armour(name,                           //name
                               std::atof(&attrs.at(0).at(0)),  //value
                               std::atoi(&attrs.at(1).at(0)),  //armour type
                               std::atoi(&attrs.at(2).at(0))); //protection
        break;

    case 5:
        ptr = new Item::Defensive_Item(name,                           //name
                                       std::atof(&attrs.at(0).at(0)),  //value
                                       std::atoi(&attrs.at(1).at(0)),  //protection
                                       std::atoi(&attrs.at(2).at(0)),  //effect
                                       std::atoi(&attrs.at(3).at(0)),  //effect level
                                       std::atoi(&attrs.at(4).at(0)),  //duration
                                       std::atoi(&attrs.at(5).at(0)),  //iswearable
                                       std::atoi(&attrs.at(6).at(0))); //istwohanded
        break;

    case 6:
        ptr = new Item::Melee_Weapon(name,                           //name
                                     std::atof(&attrs.at(0).at(0)),  //value
                                     std::atoi(&attrs.at(1).at(0)),  //weapon type
                                     std::atoi(&attrs.at(2).at(0)),  //damage
                                     std::atoi(&attrs.at(3).at(0))); //istwohanded
        break;

    case 7:
        ptr = new Item::Ranged_Weapon(name,                           //name
                                      std::atof(&attrs.at(0).at(0)),  //value
                                      std::atoi(&attrs.at(1).at(0)),  //weapon type
                                      std::atoi(&attrs.at(2).at(0)),  //damage
                                      std::atoi(&attrs.at(3).at(0)),  //range
                                      std::atoi(&attrs.at(4).at(0))); //istwohanded
        break;

    default:
        ptr = NULL;
        break;
    }

    if (ptr != NULL)
        s.push(ptr);
}