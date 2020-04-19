#include <bits/stdc++.h>

using namespace std;

int frec1[130] , frec2[130];

int main()
{
    bool check=true;
    string text1 , text2;
    getline(cin , text1);
    getline(cin , text2);

    for(int i=0 ; i<text1.size() ; i++) if(isalpha(text1[i]))frec1[(int)text1[i]]++ ;
    for(int i=0 ; i<text2.size() ; i++) if(isalpha(text2[i])) frec2[(int)text2[i]]++;

    for(int i=0 ; i<130 ; i++){
            if(frec1[i]!=frec2[i]){
                check=false;
                break;
            }}
    (check)? cout << "The Two Sentence are anagrams" << endl : cout << "No";

    return 0;
}
