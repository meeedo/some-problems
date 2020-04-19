#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int arr[16]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
    random_shuffle(&arr[0],&arr[16]);

    vector<pair<int , int>> vec;

    int nums[4][4] , num1 , num2 , num3 , num4 , check=0;
    char star[4][4];

    for(int i=0 ; i<4 ; i++) for(int j=0 ; j<4 ; j++) nums[i][j]=arr[i*4+j];
    for(int i=0 ; i<4 ; i++) for(int j=0 ; j<4 ; j++) star[i][j]='*';

    while(check!=16){
        cin >> num1 >> num2 >> num3 >> num4;
        for(int i=0 ; i<vec.size() ; i++){
            if((num1==vec[i].first && num2==vec[i].second) || (num3==vec[i].first && num4==vec[i].second))
                cout << "This Number used before , Please Enter another pair of Numbers " <<endl;
                cin >> num1 >> num2 >> num3 >> num4;
        }
        cout << endl;
        for(int i=0 ; i<4 ; i++){
            for(int j=0 ; j<4 ; j++){
                if((i==num1-1 && j==num2-1) || (i==num3-1 && j==num4-1)){
                        cout << nums[i][j] << " ";
                        if(nums[num1-1][num2-1] == nums[num3-1][num4-1]){
                            star[num1-1][num2-1] = char(nums[num1-1][num2-1]+48);
                            star[num3-1][num4-1] = char(nums[num3-1][num4-1]+48);
                            check+=1;
                            vec.push_back(make_pair(num1,num2));
                            vec.push_back(make_pair(num3,num4));

                        }
                }
                else cout << star[i][j] << " ";
        }
        cout << endl;
        }
        cout << endl << endl;
    }
    return 0;
}
