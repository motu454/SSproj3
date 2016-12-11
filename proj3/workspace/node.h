#ifndef _NODE_H__
#define _NODE_H__
#include <iostream>
using namespace std;

class Node{
    private:
        bool cover;  //0 represent covered 1 represent uncovered
        int state; //-1 represent mine 0 represent no ajacent mine positive number means number of mines around

    public:
        Node(); //initialize the node with cover=0 and state=0

        bool isCover();   //return cover==0
        void aroundMinesIncrease();  //state++
        void setMine();  //state=-1
        bool isMine();   //return state==-1
        bool isSet();   //return state==0
        void reset();   // cover=0 and state=0
        int getState();
        void setUncover();
        ~Node();
};



#endif