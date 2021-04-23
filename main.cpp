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

    it.begin();
    try{
        for(auto i : it){
            std::cout << i << std::endl;
        }
       //std::cout << it << std::endl;
    }
    catch(const std::exception &exept){
        std::cout << exept.what() << std::endl;
    }

    it.print();
    list.print_all();
    list.push_back("cheture");
    list.push_back("pyat'");

    std::cout << "add some nodes to list" << std::endl;
    it.end();
    it.print();
    try{
        for(auto i : it) {
            std::cout << i << std::endl;
        }
    }
    catch(const std::exception &exept){
        std::cout << exept.what() << std::endl;
    }


    return 0;
}
