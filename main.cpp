#include <iostream>
#include "list.h"

int main()
{
   List<std::string> list{};
   list.push_back("A");
   list.push_back("B");
   list.print_all();

   List<std::string> init_list{list};
   init_list.print_all();

   auto it = List<std::string>::Iterator(list);
   it++;
   std::cout << "Iterator Plus: " << it << std::endl;
   it--;
   std::cout << "Iterator Minus: " << it << std::endl;

   List<std::string> in_list{"Aa", "Bb", "Cc", "Dd", "Ff", "Gg"};
   std::cout << "Iterator after initializer list: " << std::endl;
   in_list.print_all();

/*
   std::list<std::string> std_list;
   std_list.push_back("raz");
   std_list.push_back("dva");

   std::list<std::string>::iterator std_it = std_list.begin();

   std_it++;
   std::cout << *std_it << std::endl;
*/
   return 0;
}
