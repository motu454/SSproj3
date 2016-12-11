#include <iostream>
#include <cstdlib>
#include "node.h"
#include "MineBoard.h"
using namespace std;


int main(int argc, char** argv){
    int width=atoi(argv[1]);
    int height=atoi(argv[2]);
    int mines_n=atoi(argv[3]);
    if(argc!=4||(width*height)<=mines_n) {cout<<"Wrong arguments!"<<endl;return 0;}
    char again='y';
    cout<<"initiation begin!"<<endl;
    MineBoard M(width,height,mines_n); //initialize Board
    cout<<"initiation complete!"<<endl;
    M.showBoard();
    while(again=='y'){
        while(!M.isfailure()&&!M.isWin()){
            M.getCoordinate(); //the coordinate need to uncover
            M.applyChanges();
            M.showBoard();
        }
        if(M.isfailure()){cout<<"You lose!"<<endl;}
        if(M.isWin()){cout<<"You win!"<<endl;}
        cout<<"Want new game?(y/n)"<<" ";
        cin>>again;
        if(again=='y'){
            M.reSet();
            M.showBoard();
        }
    }
    return 0;
}