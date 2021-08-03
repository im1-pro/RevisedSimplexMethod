#include <iostream>
#include <vector>
#include <algorithm>
#include "dependencies.h"
using namespace std;


int main(){

    vector<vector<float>>A,B,b,cb,cj,xb;   
    
     //inputing A ie constrant matrix {{2,1},{1,2}}
    cout << "Enter order of matrix then matrix of constrant\n";
    input(A);
    //inputing B ie variable that we introduce in constrant matrix {{1,0},{0,1}}
    cout << "Enter order of matrix then matrix of introduced variable in constraint\n";
    input(B);
    //inputing b ie initial solution matrix {{4},{6}}
    cout << "Enter order of matrix then initial solution matrix\n";
    input(b);
    //inputing cb ie variable introduce in constraint coefficient in objective function cj {{0},{0}}
    cout << "Enter order of matrix then matrix of constrant\n";
    input(cb);
    //inputing cj ie objective function constants; {{4},{3}}
    cout << "Enter order of matrix then matrix of objective function constant\n";
    input(cj);
    
    xb = B*b;
    for(int i=0;i<3;i++){
        if(isOptimal(deltaJ(cb,B,A,cj))){
           cout << "success\n";
        }
        else{
            int min_index = MV_index(deltaJ(cb,B,A,cj));
            vector<vector<float>>x = column(A,min_index);
            
            x = B*x;
            int min_index2 = MV_index(ratio(xb,x));
            

            swap(B[0],B[min_index2]);
            swap(x[0],x[min_index2]);

            for(int j=0;j<x.size();j++){
                if(j==0){
                    for(int k=0;k<B[0].size();k++){
                        B[j][k] = B[j][k]/x[j][0];
                    }
                }
                else{
                    
                    for(int k=0;k<B[0].size();k++){
                        B[j][k] = B[j][k] - x[j][0]*B[0][k];
                    }
                }
            }
            swap(B[0],B[min_index2]);
            swap(x[0],x[min_index2]);
            cb[min_index2][0] = cj[min_index][0];
            xb = B*b;
            for(vector<float>x: xb){
                for(float y:x){
                    cout << y << " ";
                }
                cout << endl;
            }
            
            
            

            
        }
    }

 

}