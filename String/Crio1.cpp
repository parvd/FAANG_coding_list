#include <iostream>
using namespace std;

int main()
{
    int m, n, i, j, count = 0;
    cout<<"Enter Rows and Cols : ";
    cin>>m>>n;
    int a[m][n];
    cout<<"Input are : "<<endl;
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(!(a[i][j] == 0 || a[i][j] == 1)) {
                cout<<"Input should be 0s and 1s only"<<endl;
                break;
            } else {
                if(a[i][j] == 1) {
                    if(a[i][j+1] == 1 && a[i+1][j] == 1) {
                        count+= 3;
                    } else {

                        if(a[i][j+1] == 1) {
                            count++;
                        } else if(a[i+1][j] == 1) {
                            count++;
                        }
                    }
                } else {
                    continue;
                }
            }
        }
    }
    cout<<"Count = "<<count<<endl;
    return 0;
}
