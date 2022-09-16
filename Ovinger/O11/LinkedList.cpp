#include "LinkedList.h"

std::ostream & operator<<(std::ostream & os, const LinkedList::Node & node){
    std::string val = node.getValue();
    os<<val; 
    return os;
}

LinkedList::Node* LinkedList::LinkedList::insert(Node* pos, const std::string& value){
    if(pos == head.get()){
        Node thisNode{value, move(head), nullptr};
        pos->prev = &thisNode;
        return pos->prev;
    }
    else{
        Node* prev = pos->getPrev();
        prev->next = std::make_unique<Node>(value, std::move(prev->next), prev);
        pos->prev = prev->getNext();
        return pos->prev;
    }
}

LinkedList::Node* LinkedList::LinkedList::remove(Node* pos){
    if(pos == tail){
        pos->prev->next = nullptr;
        return nullptr;
    }
    else if(pos==head.get()){
        head = move(pos->next);
        head->prev = nullptr;
        return head.get();
    }
    else{
        pos->next->prev = pos->prev;
        pos->prev->next = move(pos->next);
        return pos->prev->getNext();
    }

}

LinkedList::Node* LinkedList::LinkedList::find(const std::string& value){
    Node* pos = head.get();
    std::string posString = pos->getValue();
    while(posString!=value){
        pos = pos->getNext();
        if (pos == nullptr){
            return nullptr;
        }
        else{
            posString = pos->getValue();
        }
    }
    return pos;
}

void LinkedList::LinkedList::remove(const std::string& value){
    Node* pos = find(value);
    if (pos != nullptr){
        remove(pos);
    }
}

std::ostream& LinkedList::operator<<(std::ostream& os, const LinkedList& list){
    Node* pos = list.head.get();
    if (pos!=nullptr){
        std::cout<< pos->getValue();
    }
    while(pos->getNext()!=nullptr){
        pos = pos->getNext();
        std::cout<<", "<<pos->getValue();
    }
    std::cout<<"\n";
    return os; 
}