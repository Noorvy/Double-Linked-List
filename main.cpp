#include <iostream>
#include "list.h"
#include <list>

int main()
{
   List<std::string> list{};
   list.push_back("A");
   list.push_back("B");
   list.print_all();

   List<std::string> init_list{list};
   init_list.print_all();

   auto it = List<std::string>::Iterator(list);
   it++;    //Проверил арифметику итераторов
   std::cout << "Iterator Plus: " << it << std::endl;
   it--;
   std::cout << "Iterator Minus: " << it << std::endl;

   //Проверил list_inicialization
   List<std::string> in_list{"Aa", "Bb", "Cc", "Dd", "Ff", "Gg"};
   std::cout << "Iterator after initializer list: " << std::endl;
   in_list.print_all();

   auto second_it = List<std::string>::Iterator(in_list);
   std::cout << second_it << std::endl;
   second_it++;
   second_it++;

   std::cout << second_it << std::endl;
   //Проверка insert
   in_list.insert(second_it, "insert_value");
   in_list.print_all();
   second_it++;

   //Проверка удаления значения по итератору
   in_list.erase(second_it);
   std::cout << "\n";


   in_list.clear(); //Проверка чистки списка (список весь пустой, проверил через отладчик))
   in_list.print_all();

   list.push_back("Tri");
   list.push_back("Chetyre");
   it++;
   list.erase(it); //Удаление по итератору после инкремента итератора

   in_list = list; //Проверка перегрузки оператора присваивания

   second_it = in_list.begin(); //Проверка возвращаемого итератора на 1-й элемент списка
   second_it++;
   std::cout << second_it << std::endl;
   //Проверка методов после оператора копирования
   in_list.insert(second_it, "new value!");
   in_list.erase(second_it);
   list.print_all();
   std::cout << "\n";
   in_list.print_all();

   //Проверка возращаемого итератора на конец списка
   second_it = in_list.end();
   std::cout << second_it << std::endl;

   return 0;
}
