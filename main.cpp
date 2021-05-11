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

   auto second_it = List<std::string>::Iterator(in_list);
   std::cout << second_it << std::endl;
   second_it++;
   second_it++;

   std::cout << second_it << std::endl;
   in_list.insert(second_it, "insert_value");
   in_list.print_all();
   second_it++;
   in_list.erase(second_it);
   std::cout << "\n";


   in_list.clear();
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
