#include <vector>
#include <iostream>
#include <unordered_map>
#include <math.h>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

template<typename T>
void vectorD2(vector<vector<T>> &v, const T **arr, int row, int col) {
    for(int i = 0; i < row; i ++) {
        vector<T> tmp;
        for(int j = 0; j < col; j ++) {
            tmp.push_back(arr[i][j]);
        }
        v.push_back(tmp);
    }
}

template<typename T>
void vectorD1(vector<T> &v, T arr[], int len) {
    for(int i = 0; i < len; i ++) {
        v.push_back(arr[i]);
    }
}