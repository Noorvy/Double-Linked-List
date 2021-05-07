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
            explicit Iterator(List<T> &list) {
                currentIt = list.begin;
            }  //"Привязываемся" к списку
            Iterator &operator++(int){
                this->currentIt = currentIt->next;
                return *this; }
            Iterator &operator ++() {
                currentIt = currentIt->next;
                return *this; }
            //Перегрузка посфиксного и префиксного декремента
            Iterator &operator--(int) {
                this->currentIt = currentIt->prev;
                return *this; }
            Iterator &operator--() {
                if(currentIt != nullptr) {
                    this->currentIt = currentIt->prev; }
                return *this; }
            //Перегрузка оператора вывода
            friend std::ostream &operator<<(std::ostream &out, const Iterator &it){
                    out << "Iterator current node is: " << it.currentIt->data;
                return out;}
            //Перегрузка операторов сравнения
           friend bool operator==(const Iterator &it1, const Iterator &it2) {
                return (it1.currentIt->data==it2.currentIt->data); }
           friend bool operator!=(const Iterator &it1, const Iterator &it2) {
                return !(it1.currentIt->data==it2.currentIt->data); }
           //Перегрузка остальных операторов
           Iterator &operator*() { return *this; }
           Iterator *operator->() { return this; }
        //private:
        public:
            elementList<T> *currentIt{ nullptr };  //Итератор для перебора элемента списка
        };

private:
        elementList<T> *begin{ nullptr };
        elementList<T> *end{ nullptr };
        uint32_t count{ 0 }; //count nodes in list
public:
//Copy constructor
        List<T> &operator =(const List<T> &other){
            this->begin = other.begin;
            this->end = other.end;
            this->count = other.count;
        }

        explicit List(const List &other){
            this->begin = other.begin;
            this->count = other.count;
            this->end = other.end;
        }
//Initializer_list constructor
        explicit List(const std::initializer_list<T> &other){
            this->begin = new elementList<T>{};
            auto *curPos = this->begin;

            for (auto i : other){
                curPos->next = new elementList<T>{ };
                curPos->data = i;
                this->end = curPos;
                curPos = curPos->next;
                curPos->prev = this->end;}
        }

        List(){}
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
                end->next = nullptr;
                for (auto curPos = begin; curPos != nullptr ; curPos = curPos->next) {
                        std::cout << "List node is: " << curPos->data << std::endl;
                }
}


#endif // LIST_H
