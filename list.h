#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
class elementList {
public:
        T data;    //Data
        elementList<T> *prev{ nullptr };  //ptr to prewie element
        elementList<T> *next{ nullptr };  //ptr to next element
        explicit elementList(const T &datastr) : data{ datastr } {}
        elementList(){}
};


template <class T>
class List {
public:
        class Iterator
        {
        public:
            Iterator (){}
            explicit Iterator(const List<T> &list) {
                currentIt = list.front;
            }
            Iterator &operator++(int){
                if(currentIt->next != nullptr){
                    this->currentIt = currentIt->next;}
                return *this; }
            Iterator &operator ++() {
                if(currentIt->next != nullptr){
                    currentIt = currentIt->next;}
                return *this; }
            //Перегрузка посфиксного и префиксного декремента
            Iterator &operator--(int) {
                this->currentIt = currentIt->prev;
                return *this; }
            Iterator &operator--() {
                this->currentIt = currentIt->prev;
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
           T &operator*() { return this->currentIt->data; }
           T *operator->() { return this->currentIt->data; }

           elementList<T> *currentIt{ nullptr };  //Итератор для перебора элемента списка
        };

private:
        elementList<T> *front{ nullptr };
        elementList<T> *back{ nullptr };
        elementList<T> *empty{ nullptr };
        uint32_t count{ 0 }; //count nodes in list
public:
        void push_back(const T& str); //Add node to end of list*чер
        void erase(Iterator it);
        void print_all();
        void clear();
        void insert(const Iterator &it, const T &value);
        Iterator begin();
        Iterator end();
//Copy constructor
        List<T> &operator =(const List<T> &other){
            if(this != &other){
                this->clear();
                this->back = new elementList<T>{};
                this->back = other.front;
                auto newElem = new elementList<T> {other.front->data};
                newElem->prev = nullptr;
                this->front = new elementList<T>{};
                this->front = newElem;

                while(back->next){
                    newElem->next = new elementList<T> {back->next->data};
                    auto enterim = newElem;
                    newElem = newElem->next;
                    newElem->prev = enterim;
                    back = back->next;}

                back = newElem;
                this->count = other.count;
            }
            return *this;
        }

        explicit List(const List &other){
            this->front = other.front;
            this->count = other.count;
            this->back = other.back;
        }
//Initializer_list constructor
        explicit List(const std::initializer_list<T> &other){
            this->front = new elementList<T>{};
            this->back = new elementList<T>{};
            this->back = this->front;
            auto *curPos = this->front;
            count++;

            for (const auto &i : other){
                curPos->next = new elementList<T>{ };
                curPos->data = i;
                this->back = curPos;
                curPos = curPos->next;
                curPos->prev = this->back;
                count++;}
        }

        List(){}

        ~List(){
            while (front){
                auto next = front->next;
                delete front;
                front = next;}
            delete empty;
        }
};

template <class T>
typename List<T>::Iterator List<T>::begin(){
    Iterator it;
    it.currentIt = this->front;
    return it;
}

template <class T>
typename List<T>::Iterator List<T>::end(){
    Iterator it;
    if (!empty){
        empty = new elementList<T>{};
        it.currentIt = empty;
        back->next = it.currentIt;}
    else{
        it.currentIt = empty;
        back->next = it.currentIt;
    }
    return it;
}

template <class T>
void List<T>::push_back(const T& str) {
        if (front == nullptr) {
                front = new elementList<T>(str);
                back = front;
                count++;
                return;
        }
        auto * newElem = new elementList<T>(str);
        back->next = newElem;
        newElem->prev = back;
        back = newElem;
        count++;
}
//
//[] [] [] [] [] []
template <class T>
void List<T>::insert(const Iterator &it, const T &value){
    if(it.currentIt != nullptr && it.currentIt != this->front){
        //Initializer new element and interim iterator
        auto *newElem = new elementList<T>{value};
        auto interim = it;
        interim.currentIt = it.currentIt->prev;
        //connect new node with other list element
        it.currentIt->prev = newElem;
        interim.currentIt->next = newElem;
        newElem->next = it.currentIt;
        newElem->prev = interim.currentIt;
        this->count++;}
    else if (it.currentIt != nullptr && it.currentIt == this->front){
        auto *newElem = new elementList<T>{value};
        it.currentIt->prev = newElem;
        newElem->next = it.currentIt;
        this->front = newElem;
        this->count++;}
}

//Delete node
//[] [] [] [] [] []
//       []
template <class T>
void List<T>::erase(Iterator it) {
    if(it.currentIt != nullptr){
        if(it.currentIt == this->front){
            this->front = it.currentIt->next;
            this->front->prev = nullptr;
            it.currentIt = nullptr;
            count--;
            return;}
        else if(it.currentIt == this->back){
            this->back = it.currentIt->prev;
            this->back->next = nullptr;
            it.currentIt = nullptr;
            count--;
            return;}
        auto interim = it;
        interim.currentIt = it.currentIt->prev;
        interim.currentIt->next = it.currentIt->next;
        it.currentIt->next->prev = interim.currentIt;
        delete it.currentIt;
        count--;}
}

//Clear list
template <class T>
void List<T>::clear(){
    while (front){
        auto next = front->next;
        delete front;
        front = next;}
    delete empty;
    count = 0;
}


template <class T>
void List<T>::print_all() {
    if(this->front == nullptr){
        std::cout << "List is empty!" << std::endl;
        return;
    }
    back->next = nullptr;
    for (auto curPos = front; curPos != nullptr ; curPos = curPos->next) {
            std::cout << "List node is: " << curPos->data << std::endl;
    }
}


#endif // LIST_H
