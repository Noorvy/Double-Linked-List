#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
class elementList {
public:
        T data;    //Data
        elementList<T> *prev{ nullptr };  //ptr to prewie element
        elementList<T> *next{ nullptr };  //ptr to next element
        explicit elementList(const T& datastr) : data{ datastr } {}
        elementList(){}
        elementList<T> &operator=(const elementList<T> &el){
            this->data = el.data;
            this->prev = el.prev;
            this->next = el.next;
            return *this;
        }
};


template <class T>
class List {
public:
        void push_back(const T& str); //Add node to end of list*чер
        void insert(const T& str, uint32_t index);
        void delete_node(uint32_t index);
        void show_node(uint32_t index);
        void print_all();

        class Iterator
        {
        public:
            const T &front;
            const T &back;
            explicit Iterator(List<T> &list) : front{ list.begin->data }, back{ list.end->data } {
                    beginIt = list.begin; }  //"Привязываемся" к списку
            //Возврат итератора с текущим указателем элемаента на начале
            Iterator begin(){
                if(this->beginIt != nullptr) {
                    currentIt = beginIt;
                    return *this; }
                throw std::runtime_error("List is empty!"); }
            //Возврат итератора с текущим указателем элемаента на конце
            Iterator end() {
                if(this->beginIt != nullptr) {
                    endIt = beginIt;
                    while(endIt->next != nullptr){
                        endIt = endIt->next;}
                    currentIt = endIt;
                    return *this; }
                throw std::runtime_error("List is empty!"); }
            //Перегрузка посфиксного и префиксного инкремента
            Iterator &operator++(int){
                if(currentIt != endIt){
                    this->currentIt = currentIt->next;
                    this->size_iterator++;
                    return *this; }
                throw std::runtime_error("Debug ++(int)"); }
            Iterator &operator ++() {
                if(currentIt->next != nullptr) {
                    currentIt = currentIt->next;
                    size_iterator++;
                    return *this; }
                throw std::runtime_error("Debug ++()"); }
            //Перегрузка посфиксного и префиксного декремента
            Iterator &operator--(int) {
                if(currentIt != beginIt) {
                    this->currentIt = currentIt->prev;
                    size_iterator--; }
                return *this; }
            Iterator &operator--() {
                if(currentIt != beginIt) {
                    this->currentIt = currentIt->prev;
                    size_iterator--; }
                return *this; }
            //Перегрузка оператора вывода
            friend std::ostream &operator<<(std::ostream &out, const Iterator &it){
                if (it.beginIt != nullptr){
                    out << "Iterator current node is: " << it.currentIt->data; }
                return out; }
            //Перегрузка операторов сравнения
           friend bool operator==(const Iterator &it1, const Iterator &it2) {
                return (it1.currentIt->data==it2.currentIt->data); }
           friend bool operator!=(const Iterator &it1, const Iterator &it2) {
                return !(it1.currentIt->data==it2.currentIt->data); }
           //Перегрузка остальных операторов
           Iterator operator*() { return *this; }
           Iterator *operator->() { return this; }

           void print(){ std::cout << "end node of iterator: " << endIt->data << std::endl; }
           //Размер итератора
           size_t size(){
               if(this->beginIt != nullptr){
                   size_iterator = 1;
                   currentIt = beginIt;
                   while(currentIt->next != nullptr){
                       currentIt = currentIt->next;
                       size_iterator++; }
                    return this->size_iterator; }
               throw std::runtime_error("List is empty!"); }
        private:
            size_t size_iterator{ 0 };
            elementList<T> last;
            elementList<T> *currentIt{ nullptr };  //Итератор для перебора элемента списка
            elementList<T> *beginIt{ nullptr };   //Начальный элемент итератора
            elementList<T> *endIt{ nullptr };    //Конечный элемент итератора(следующий после конца списка)
        };

private:
        elementList<T> *begin{ nullptr };
        elementList<T> *end{ nullptr };
        uint32_t count{ 0 }; //count nodes in list
};


template <class T>
void List<T>::push_back(const T& str) {
        if (begin == nullptr) {
                begin = new elementList<T>(str);
                end = begin;
                return;
        }
        auto * newElem = new elementList<T>(str);
        end->next = newElem;
        newElem->prev = end;
        end = newElem;
        count++;
}
//
//[] [] [] [] [] []
//Add node to number of list (index)
template <class T>
void List<T>::insert(const T& str, uint32_t index) {
        if (index > count) {
                throw std::runtime_error("Index is not correct!");
        }
        auto *temp = new elementList<T>(str);
        auto *curPos = begin;
        for (uint32_t i = 0; i < index; ++i) {
                curPos = curPos->next;
        }
        temp->prev = curPos->prev;
        temp->next = curPos;
        ++count;
}

//Delete node
//[] [] [] [] [] []
// []
template <class T>
void List<T>::delete_node(uint32_t index) {
        if (index > count) {
                throw std::runtime_error("Index is not correct!");
        }
        auto *curPos = begin;
        for (uint32_t i = 0; i < index; ++i) {
                curPos = curPos->next;
        }
        if (curPos != end)
        {
                auto *next = curPos->next;
                next->prev = curPos->prev;
        }
        if (curPos != begin)
        {
                auto *prev = curPos->prev;
                prev->next = curPos->next;
        }
        delete curPos;
}

//Show node
template <class T>
void List<T>::show_node(uint32_t index) {
        if (index > count) {
                std::cout << "Warning: Index is not correct!" << std::endl;
                return;
        }
        auto curPos = begin;
        for (uint32_t i = 0; i < index; ++i) {
                curPos = curPos->next;
        }
        std::cout << index << " node is: " << curPos->data << std::endl;
}


template <class T>
void List<T>::print_all() {
                for (auto curPos = begin; curPos != end->next ; curPos = curPos->next) {
                        std::cout << "List node is: " << curPos->data << std::endl;
                }
}


#endif // LIST_H
