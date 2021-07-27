#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//template for matrix addition
template<typename a> vector<vector<a>> operator+(vector<vector<a>>q,vector<vector<a>>w){
    int row = q.size(),col = q[0].size();
    vector<vector<a>>vec;
    for(int i=0;i<row;i++){
        vector<a>v(col);
        for(int j=0;j<col;j++){
            v[j] = q[i][j]+w[i][j];
        }
        vec.push_back(v);
    }    
    return vec;
}
//template for matrix subtraction
template<typename a> vector<vector<a>> operator-(vector<vector<a>>q,vector<vector<a>>w){
    int row = q.size(),col = q[0].size();
    vector<vector<a>>vec;
    for(int i=0;i<row;i++){
        vector<a>v(col);
        for(int j=0;j<col;j++){
            v[j] = q[i][j]-w[i][j];
        }
        vec.push_back(v);
    }    
    return vec;
}
//template for matrix multiplication
template<typename a> vector<vector<a>> operator*(vector<vector<a>>q,vector<vector<a>>w){
    int row1 = q.size(),col1 = q[0].size(),row2 = w.size(), col2 = w[0].size();
    vector<vector<a>>vec;
    for(int i=0;i<row1;i++){
        vector<a>v(col2);
        for(int j=0;j<col2;j++){
            float sum=0;
            for(int k=0;k<col1;k++){
                sum = sum + q[i][k]*w[k][j];
            }
            v[j] = sum;
        }
        vec.push_back(v);
    } 
    return vec;
}
//template for transpose of matrix
template<typename a>
void transpose(vector<vector<a>>&v){
    vector<vector<a>>vv;
    for(int i=0;i<v[0].size();i++){
        vector<a>h(v.size());
        for(int j=0;j<v.size();j++){
            h[j] = v[j][i];
        }
        vv.push_back(h);
    }
    v = vv;
}
//template to check is there any negative element in matrix
template<typename a>
bool isOptimal(vector<vector<a>>v){
    for(vector<a> x:v){
        if(x[0]<0){
            return false;
        }
    }
    return true;
}
//template return deltaJ
template<typename a>
vector<vector<a>> deltaJ(vector<vector<a>>cb,vector<vector<a>>B,vector<vector<a>>A,vector<vector<a>>cj){
    transpose(A);
    transpose(cb);
    vector<vector<a>>delta = (cb*B);
    vector<vector<a>>alpha = delta*A;
    transpose(alpha);
    alpha = alpha-cj;
    return alpha;
}
//template return smallest values index of matrix 
template <typename a>
int MV_index(vector<vector<a>>alpha){
    vector<a>ans;
    for(int i=0;i<alpha.size();i++){
        ans.push_back(alpha[i][0]);
    }
    a min = *min_element(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        if(min == ans[i]){
            return i;
        }
    }
    cout << "found\n";
    return -1;
}
//template return column of matrix of index index
template <typename a>
vector<vector<a>> column(vector<vector<a>>A,int index){
    vector<vector<a>>v ={A[index]};
    transpose(v);
    return v;
}
//return ratio of matrix A and B
template <typename a>
vector<vector<a>> ratio(vector<vector<a>>A,vector<vector<a>>B){
    vector<vector<a>>v;
    for(int i=0;i<A.size();i++){
            if(B[i][0]<=0){
                v.push_back({a(1000000007)});
                continue;
            }
            else{
                v.push_back({(A[i][0])/B[i][0]});
            }
    }
    return v;
}