#include <iostream>
#include "node.h"
using namespace std;

Node::Node(){      //initialize the node with cover=0 and state=0
    this->cover=0;
    this->state=0;
} 
Node::~Node(){}
bool Node::isCover(){  //return cover==0
    return this->cover==0;
}   
void Node::aroundMinesIncrease(){
    this->state++;
}  //state++
void Node::setMine(){  //state=-1
    this->state=-1;
}
bool Node::isMine(){   //return state==-1
    return this->state==-1;
}
bool Node::isSet(){   //return state==0
    return this->state==0;
}
void Node::reset(){   // cover=0 and state=0
    this->cover=0;
    this->state=0;
}
int Node::getState(){
    return this->state;
}
void Node::setUncover(){
    this->cover=1;
}