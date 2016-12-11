#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <time.h>
using namespace std;

void exampleBoard(int width, int height, int mines);
void fillNumbers(vector<vector <int> > &field);
void showBoard(vector<vector <int> > &field,vector<vector <bool> > &show);
void guess(vector<vector <int> > &field,vector<vector <bool> > &show, int x, int y);
void update(vector<vector <int> > &field,vector<vector <bool> > &show);
bool explosion = false;
bool victory = false;

int main(int argc, char** argv){
    //Check for 4 arguments:
    if (argc != 4){
        cout << "Correct Usage: ./[binary file] [width] [height] [num of mines]\n" << endl;
        return 0;
    }
    else{
        int width = atoi(argv[1]);
        int height = atoi(argv[2]);
        int mines = atoi(argv[3]);
        
        //Check for invalid parameters:
        if ((width <= 0) || (height <= 0) || (mines <= 0) || (width*height <= mines)){
            cout << "Width, height, and mines must be greater than 0 and mines must be less than the board size." << endl;
            return 0;
        }

        vector<vector<int> > field;
        field.resize(height, vector<int>(width));
        vector<vector<bool> > show;
        show.resize(height, vector<bool>(width,false));
        
        for(int i=0; i<mines; i++){
            srand(time(NULL));
            int randx = rand() % width;
            srand(time(NULL));
            int randy = rand() % height;
            if(field.at(randy).at(randx) == 9){
                i--;
            }
            else{
                cout << i+1 << " bombs placed." << endl;
            }
            field.at(randy).at(randx) = 9;
            
        }
        
        fillNumbers(field);
        bool first = true;

        showBoard(field,show); // this will be in the loop below
        while(!explosion){
            int x;
            int y;
            if(first == true){
                cout << "The top left corner is (0,0)" << endl;
                first = false;
            }
            place:
            cout << "Enter Value [x] [y] : ";
            cin >> x >> y;
            //if (argc != 2){
            //    cout << "Correct Usage: ./[binary file] [width] [height] [num of mines]\n" << endl;
            //    return 0;
        //    }
            if(cin.fail()){
                cout << "Error: invalid input. Please restart the game." << endl;
                return 0;
            }
            if(y > field.size() || x > field.at(0).size()){
                cout << "Selection out of bounds, try again." << endl;
                goto place;
            }
            
            guess(field,show,y,x);
            if(!explosion && !victory){
                update(field,show);
                showBoard(field,show);
                victory = true;
                for(int i=0; i<field.size(); i++){
                    for(int j=0; j<field.at(i).size(); j++){
                        if(field.at(i).at(j) != 9 && !show.at(i).at(j)){
                            victory = false;
                        }
                    }
                }
                if(victory){
                    cout << "YOU WIN!!!" << endl;
                    return 1;
                    
                }
            }
        }

        return 1;
    }
}

void update(vector<vector <int> > &field,vector<vector <bool> > &show){
    bool change = true;
        
    while(change){
        change = false;
        for(int i=0; i<field.size(); i++){
            for(int j=0; j<field.at(i).size(); j++){
               if(field.at(i).at(j) == 0 && show.at(i).at(j)){
                   if(i>0 && !show.at(i-1).at(j)){
                        show.at(i-1).at(j) = true;
                        change = true;
                   }
                   if(i>0 && j<field.at(i).size()-1 && !show.at(i-1).at(j+1)){
                        show.at(i-1).at(j+1) = true;
                        change = true;
                   }
                   if(j<field.at(i).size()-1 && !show.at(i).at(j+1)){
                        show.at(i).at(j+1) = true;
                        change = true;
                   }
                   if(i<field.size()-1 && j<field.at(i).size()-1 && !show.at(i+1).at(j+1)){
                        show.at(i+1).at(j+1) = true;
                        change = true;
                   }
                   if(i<field.size()-1  && !show.at(i+1).at(j)){
                        show.at(i+1).at(j) = true;
                        change = true;
                   }
                   if(i<field.size()-1  && j>0 && !show.at(i+1).at(j-1)){
                        show.at(i+1).at(j-1) = true;
                        change = true;
                   }
                   if(j>0 && !show.at(i).at(j-1)){
                        show.at(i).at(j-1) = true;
                        change = true;
                   }
                   if(i>0 && j>0 && !show.at(i-1).at(j-1)){
                        show.at(i-1).at(j-1) = true;
                        change = true;
                   }
                }
            }
        }
    }
}

void guess(vector<vector <int> > &field,vector<vector <bool> > &show, int x, int y){
    if(field.at(x).at(y) == 9){
        cout << "You lose"<< endl;
        explosion = true;
    }else{
        if(!show.at(x).at(y)){
            show.at(x).at(y) = true;
        }
    }
}

void showBoard(vector<vector<int> > &field, vector<vector<bool> > &show){
    int height = field.size();
    int width = field.at(0).size();
    for(int i=0; i<height*2+1; i++){
        if(i == 0){
            for(int k=0; k<width*2; k++){
                if(k%2==1){
                    cout << "  --";
                }
            }
        }
        else{
            if(i%2==1)
            {
                for(int k=0; k<width; k++){
                    if(k == 0){
                        if(show.at(i/2).at(k)){
                            cout << "| " << field.at(i/2).at(k) << " |";
                        }else{
                            cout << "| " << " " << " |";
                        }
                    }
                    else{
                        if(show.at(i/2).at(k)){
                            cout << " " << field.at(i/2).at(k) << " |";
                        }else{
                            cout << "   |";
                        }
                    }
                }
            }
            else{
                for(int k=0; k<width*2; k++){
                    if(k%2==1){
                        cout << "  --";
                    }
                }
            }
        }
        cout << "\n";
    }
}

void fillNumbers(vector<vector<int> > &field){
    //char c;
    for(int i=0; i<field.size(); i++){
        for(int j=0; j<field.at(i).size(); j++){
           if(field.at(i).at(j) != 9){
               int bombs = 0;
               if(i>0 && field.at(i-1).at(j) == 9){
                    bombs++;
               }
               if(i>0 && j<field.at(i).size()-1 && field.at(i-1).at(j+1) == 9){
                    bombs++;
               }
               if(j<field.at(i).size()-1 && field.at(i).at(j+1) == 9){
                    bombs++;
               }
               if(i<field.size()-1 && j<field.at(i).size()-1 && field.at(i+1).at(j+1) == 9){
                    bombs++;
               }
               if(i<field.size()-1  && field.at(i+1).at(j) == 9){
                    bombs++;
               }
               if(i<field.size()-1  && j>0 && field.at(i+1).at(j-1) == 9){
                    bombs++;
               }
               if(j>0 && field.at(i).at(j-1) == 9){
                    bombs++;
               }
               if(i>0 && j>0 && field.at(i-1).at(j-1) == 9){
                    bombs++;
               }
               field.at(i).at(j) = bombs;
           }
        }
    }
}