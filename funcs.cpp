//https://contest.yandex.ru/contest/29188/problems/A/

#include "funcs.h"
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

void parseVect(std::istream & input,
               std::vector<int > & v,
               int & len){
    input>>len;
    v.resize(len);
    for(int i = 0; i<len;++i){
        input>>v[i];
    }
}

/*! @brief Index of first element, that returns true for given func
 *
 * @tparam Func function pointer, lambda, on given vector should have
 * that form: "___---"
 * @tparam T type of values stored in vector
 * @param v vector to search in, sorted
 * @param func function pointer, lambda, that should accept int as input
 * @param left First index, default 0
 * @param right Last index, default -1 means length of given vector
 * @return index,that you should check again
 */
template<typename Func, typename T>
int indexOfFirst(const std::vector<T> & v, Func func, int left, int right){
    while (left<right){
        int middle = (left+right)/2;
        if(func(v[middle])){
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    return left;
}

/*! @brief Index of last element, that returns true for given func
 *
 * @tparam Func function pointer, lambda, on given vector should have
 * that form: "---____"
 * @tparam T type of values stored in vector
 * @param v vector to search in, sorted
 * @param func function pointer, lambda, that should accept int as input
 * @param left First index, default 0
 * @param right Last index, default -1 means length of given vector
 * @return index,that you should check again
 */
template<typename Func, typename T>
int indexOfLast(const std::vector<T> & v, Func func, int left, int right){
    while (left<right){
        int middle = (left+right+1)/2;
        if(func(v[middle])){
            left = middle;
        } else {
            right = middle -1;
        }
    }
    return left;
}

int numberOfElementsInRange(const std::vector<int> & v, int lenV, int min, int max){
    int iMin = indexOfFirst(v,[&min](int a){return a>=min;},0,lenV);
    if(v[iMin]<min)
        return 0;
    int iMax = indexOfLast(v,[&max](int a){return a<=max;},iMin,lenV);
    if(v[iMax]>max)
        return 0;
    return iMax + 1 - iMin;
}

void parseFile(std::istream & input, std::ostream & output){

    int lenV, lenAns;
    std::vector<int>v, ans;
    parseVect(input,v,lenV);
    std::sort(v.begin(),v.end());

    input >> lenAns;
    ans.resize(lenAns);
    int aMin, aMax, iVMax = lenV-1;
    for(auto & a : ans){
        input>>aMin>>aMax;
        a = numberOfElementsInRange(v,iVMax,aMin,aMax);
    }

    std::copy(ans.begin(), --ans.end(),
              std::ostream_iterator<int>(output, " "));
    output<<ans.back()<<std::endl;
}
