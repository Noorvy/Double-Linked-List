#include <iostream>
#include "list.h"
#include <array>
///////////////////////////////////////////////////////////////////////////////////////////
//Global commit
///////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    List<std::string> list;
    list.push_back("raz");
    list.push_back("dva");
    list.push_back("tri");

    List<std::string> lst;
    lst.push_back("raz");

    auto it = List<std::string>::Iterator(list);
    auto itr = List<std::string>::Iterator(lst);

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

    return 0;
}
