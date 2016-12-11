#ifndef _MINEMAP_H__
#define _MINEMAP_H__
#include <iostream>
#include <string>
#include <vector>
#include "node.h"
using namespace std;


class MineBoard{
  private:
      int width;
      int height;
      int mines_n;
      int x;
      int y;
      int getMine;
      int n_mine_remain;
      Node** Board;
      vector<pair<int,int> > expandlist;
      void expand(int x,int y);
      void setState(Node* n,int x,int y);
      void expandHelper(int x,int y);

  public:
      MineBoard(int width,int height,int mines_n);
      void showBoard();
      void getCoordinate();
      void applyChanges();
      bool isfailure();
      bool isWin();
      void reSet();
      ~MineBoard();
};



#endif