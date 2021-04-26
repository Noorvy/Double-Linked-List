#include <iostream>
#include "list.h"
#include <array>
///////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    List<std::string> list;
    list.push_back("raz");
    list.push_back("dva");
    list.push_back("tri");

    auto it = List<std::string>::Iterator(list);

    try{
        for(auto i : it){
            std::cout << i << std::endl;
        }
    }
    catch(const std::exception &exept){
        std::cout << exept.what() << std::endl;
    }

    std::cout << it.size() << std::endl;
    list.print_all();
    list.push_back("cheture");
    list.push_back("pyat'");

    std::cout << "add some nodes to list" << std::endl;

    try{
        for(auto i : it) {
            std::cout << i << std::endl;
        }
    }
    catch(const std::exception &exept){
        std::cout << exept.what() << std::endl;
    }

    std::cout << it.size() << std::endl;
    list.print_all();

    list.push_back("shest'");
    list.push_back("sem'");

    std::cout << it.size() << std::endl;


    list.print_all();

    list.push_back("vosem'");
    list.push_back("devayt'");

    std::cout << it.size() << std::endl;
    list.print_all();

    try{
        for(auto i : it) {
            std::cout << i << std::endl;
        }
    }
    catch(const std::exception &exept){
        std::cout << exept.what() << std::endl;
    }

    std::cout << it.size() << std::endl;

    it.begin();
    it++;
    it++;
    it.insert("something");

    try{
        for(auto i : it){
            std::cout << i << std::endl;
        }
    }
    catch(const std::exception &exept){
        std::cout << exept.what() << std::endl;
    }

    std::cout << it.size() << std::endl;

    return 0;
}
