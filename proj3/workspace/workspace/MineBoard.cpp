#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "MineBoard.h"
using namespace std;

MineBoard::MineBoard(int width,int height,int mines_n){
    int i=0;
    this->getMine=0;
    this->n_mine_remain=width*height-mines_n;
    this->width=width;
    this->height=height;
    this->mines_n=mines_n;
    srand((unsigned)time(NULL));
    this->Board = new Node*[height];
    for(;i<height;i++){
        this->Board[i] = new Node[width];
    }
    i=0;
    for(;i<mines_n;){
        int oned_index=rand()%(height*width);
        int X=oned_index/width;
        int Y=oned_index%width;
        if(!this->Board[X][Y].isMine()){
            Board[X][Y].setMine();
            i++;
        }
    }
    i=0;
    for(;i<height;i++){
        int j=0;
        
        for(;j<width;j++){
            this->setState(&(this->Board[i][j]),i,j);
            
        }
    }
}

void MineBoard::reSet(){
    int i=0;
    this->getMine=0;
    this->n_mine_remain=this->width*this->height-this->mines_n;
    for(;i<this->height;i++){
        int j=0;
        for(;j<this->width;j++){
            this->Board[i][j].reset();
        }
    }
    i=0;
    for(;i<mines_n;){
        int oned_index=rand()%(height*width);
        int X=oned_index/width;
        int Y=oned_index%width;
        if(!this->Board[X][Y].isMine()){
            Board[X][Y].setMine();
            i++;
        }
    }
    i=0;
    for(;i<height;i++){
        int j=0;
        for(;j<width;j++){
            this->setState(&(this->Board[i][j]),i,j);
        }
    }
}

void MineBoard::setState(Node* n,int x,int y){
    if(!n->isMine()){
        
        if(x>0&&y>0&&x<this->height-1&&y<this->width-1){
            if(this->Board[x-1][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y+1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x-1][y+1].isMine()){n->aroundMinesIncrease();}
        }
        else if(x==0&&y==0){
            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y+1].isMine()){n->aroundMinesIncrease();}
        }
        else if(x==0&&y>0&&y<this->width-1){
            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y+1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}
        }
        else if(x==0&&y==this->width-1){
            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}
        }
        else if(x>0&&x<this->height-1&&y==this->width-1){
            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x-1][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}
        }
        else if(x==this->height-1&&y==this->width-1){
            if(this->Board[x-1][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}
        }
        else if(x==this->height-1&&y>0&&y<this->width-1){
            if(this->Board[x-1][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x-1][y+1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x][y-1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}
        }
        else if(x==this->height-1&&y==0){
            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x-1][y+1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}
        }
        else if(y==0&&x>0&&x<this->height-1){
            if(this->Board[x-1][y].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x-1][y+1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x][y+1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y+1].isMine()){n->aroundMinesIncrease();}
            if(this->Board[x+1][y].isMine()){n->aroundMinesIncrease();}
        }
        else{}
    }
    else{}
}
void MineBoard::showBoard(){
    int i=0;
    for(;i<this->height;i++){
        int j=0;
        for(;j<this->width;j++){
            if(this->Board[i][j].isCover()){
                cout<<"■";
            }
            else{
                if(this->Board[i][j].isMine()){
                    cout<<"*";
                }
                else{
                    if(this->Board[i][j].isSet()){
                        cout<<"□";
                    }
                    else{
                        cout<<this->Board[i][j].getState();
                    }
                }
            }
        }
        cout<<endl;
    }
}
void MineBoard::getCoordinate(){
    cout<<"Please enter an position you want to uncover(format:x y):";
    cin>>this->x>>this->y;
}
void MineBoard::applyChanges(){
    if(this->Board[this->x][this->y].isCover()){
        this->Board[this->x][this->y].setUncover();
        if(this->Board[this->x][this->y].getState()==-1){
            cout<<"getMine"<<endl;
            this->getMine=1;  //lose game
            int i=0;
            for(;i<this->height;i++){
                int j=0;
                for(;j<this->width;j++){
                    if(this->Board[i][j].isMine()){
                        this->Board[i][j].setUncover();
                    }
                }
            }
        }
        else{
            
            this->n_mine_remain--;
            if(this->Board[this->x][this->y].getState()==0){
                this->expandlist.push_back(make_pair(this->x,this->y));
                expand(this->x,this->y);
            }
        }
    }
}
void MineBoard::expandHelper(int x,int y){
    if(!this->Board[x][y].isMine()&&this->Board[x][y].isCover()){
        this->Board[x][y].setUncover();
        this->n_mine_remain--;
        if(this->Board[x][y].getState()==0){
            this->expandlist.push_back(make_pair(x,y));
        }
    }
}
void MineBoard::expand(int x,int y){
    if(x>0&&y>0&&x<this->height-1&&y<this->width-1){
        expandHelper(x-1,y-1);
        expandHelper(x-1,y);
        expandHelper(x-1,y+1);
        expandHelper(x,y-1);
        expandHelper(x,y+1);
        expandHelper(x+1,y-1);
        expandHelper(x+1,y);
        expandHelper(x+1,y+1);
    }
    else if(x==0&&y==0){
        expandHelper(x,y+1);
        expandHelper(x+1,y);
        expandHelper(x+1,y+1);
    }
    else if(x==0&&y>0&&y<this->width-1){
        expandHelper(x,y-1);
        expandHelper(x,y+1);
        expandHelper(x+1,y-1);
        expandHelper(x+1,y);
        expandHelper(x+1,y+1);
    }
    else if(x==0&&y==this->width-1){
        expandHelper(x,y-1);
        expandHelper(x+1,y-1);
        expandHelper(x+1,y);
    }
    else if(x>0&&x<this->height-1&&y==this->width-1){
        expandHelper(x-1,y-1);
        expandHelper(x-1,y);
        expandHelper(x,y-1);
        expandHelper(x+1,y-1);
        expandHelper(x+1,y);
    }
    else if(x==this->height-1&&y==this->width-1){
        expandHelper(x-1,y-1);
        expandHelper(x-1,y);
        expandHelper(x,y-1);
    }
    else if(x==this->height-1&&y>0&&y<this->width-1){
        expandHelper(x-1,y-1);
        expandHelper(x-1,y);
        expandHelper(x-1,y+1);
        expandHelper(x,y-1);
        expandHelper(x,y+1);
    }
    else if(x==this->height-1&&y==0){
        expandHelper(x-1,y);
        expandHelper(x-1,y+1);
        expandHelper(x,y+1);
    }
    else if(y==0&&x>0&&x<this->height-1){
        expandHelper(x-1,y);
        expandHelper(x-1,y+1);
        expandHelper(x,y+1);
        expandHelper(x+1,y);
        expandHelper(x+1,y+1);
    }
    else{}
    while(this->expandlist.size()!=0){
        this->expandlist.erase(this->expandlist.begin());
        expand(this->expandlist[0].first,this->expandlist[0].second);
        
    }
}

bool MineBoard::isfailure(){
    return this->getMine==1;
}
bool MineBoard::isWin(){
    return this->n_mine_remain==0;
}
MineBoard::~MineBoard(){
    int i=0;
    for(;i<height;i++){
        delete [] this->Board[i];
    }
}
