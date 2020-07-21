#include<iostream>
using namespace std;
#define MAXN 100000
int b[MAXN]={0};

void preprocess(string s){
    int i = 0, j =-1;
    b[0] = -1;
    while(i<s.size()){
        while(j>=0 && s[i]!=s[j])
            j = b[j];
        j++;i++;
        b[i] = j;
    }
}

void kmpsearch(string t, string s){
    int i=0,j=0;
    int n = t.size(), m = s.size();
    while(i<n){
        while(j>=0 && t[i] != s[j])
            j = b[j];
        j++;i++;
        if(j == m){
            printf("Pattern found at position %d\n",i-j);
            j = b[j];
        }
    }
}
int main(){
    string t, s;
    getline(cin,t);
    getline(cin,s);
    preprocess(s);
    kmpsearch(t,s);
    return 0;
}