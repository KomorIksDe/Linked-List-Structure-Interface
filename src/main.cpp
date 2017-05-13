#include <iostream>
#include <conio.h>
#include <windows.h>
#include "LinkedList.h"

struct MainMenu {
    LinkedList<int> foo;

    void showList() {
        if(foo.empty())
            return;

        for(int i = 0; i < foo.size(); i++)
            std::cout<<foo[i]<<" ";
    }

    void showMainMenu() {
        system("cls");

        std::cout<<"L I S T"<<std::endl;
        std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
        showList();
        std::cout<<std::endl<<"-------------------------------------------------------------------------------"<<std::endl;
        std::cout<<"Current size: "<<foo.size()<<std::endl;
        std::cout<<"Empty: ";

        if(foo.empty())
            std::cout<<"Yes"<<std::endl<<std::endl;
        else
            std::cout<<"No"<<std::endl<<std::endl;

        std::cout<<"What do you want to do with it?"<<std::endl;
        std::cout<<"[1].push_back()"<<std::endl;
        std::cout<<"[2].push_front()"<<std::endl;
        std::cout<<"[3].insert()"<<std::endl;
        std::cout<<"[4].erase()"<<std::endl;
        std::cout<<"[5].pop_back()"<<std::endl;
        std::cout<<"[6].pop_front()"<<std::endl;
        std::cout<<"[7].Exit"<<std::endl;

        getUserInput();
    }

    void pushBackCase() {
        int number;

        std::cout<<"What do you want to push back (integer): ";
        std::cin>>number;
        foo.push_back(number);
        std::cout<<"Success"<<std::endl;
        //Sleep(1000);
    }

    void pushFrontCase() {
        int number;

        std::cout<<"What do you want to push front (integer): ";
        std::cin>>number;
        foo.push_front(number);
        std::cout<<"Success"<<std::endl;
        Sleep(1000);
    }

    void insertCase() {
        int number;
        int index;

        std::cout<<"What do you want to insert (integer): ";
        std::cin>>number;
        std::cout<<"What index do you want it to be in: ";
        std::cin>>index;

        if(!foo.insert(index, number))
            std::cout<<"There's no such an index!"<<std::endl;
        else
            std::cout<<"Success"<<std::endl;

        Sleep(1000);
    }

    void eraseCase() {
        int index;

        std::cout<<"Which index do you want to erase: ";
        std::cin>>index;

        if(!foo.erase(index))
            std::cout<<"There's no such an index!"<<std::endl;
        else
            std::cout<<"Success"<<std::endl;

        Sleep(1000);
    }

    void popBackCase() {
        if(!foo.pop_back())
            std::cout<<"There's nothing to pop!"<<std::endl;
        else
            std::cout<<"Success"<<std::endl;

        Sleep(1000);
    }

    void popFrontCase() {
        if(!foo.pop_front())
            std::cout<<"There's nothing to pop!"<<std::endl;
        else
            std::cout<<"Success"<<std::endl;

        Sleep(1000);
    }

    void getUserInput() {
        char choice = getch();

        std::cout<<std::endl;

        switch(choice) {
        case '1':
            pushBackCase();
            break;

        case '2':
            pushFrontCase();
            break;

        case '3':
            insertCase();
            break;

        case '4':
            eraseCase();
            break;

        case '5':
            popBackCase();
            break;

        case '6':
            popFrontCase();
            break;

        case '7':
            exit(1);
            break;

        default:
            std::cout<<"There's no such an option!"<<std::endl;
            Sleep(1000);
            break;
        }
    }
};

int main() {
    MainMenu menu;

    while(true) {
        menu.showMainMenu();
    }

    return 0;
}
