//   TOWER OF HANOI

#include<iostream>
using namespace std;

void towerofHanoi(int n, char source, char destination, char helper){

if(n==0)
{
    return;  // base case
}

towerofHanoi(n-1, source, helper, destination);
cout<<"Move from "<<source<<" to "<<destination<<endl;
towerofHanoi(n-1, helper, destination, source);

}

int main(){

     towerofHanoi(3, 'A', 'C', 'B');
    
    return 0;
} 
