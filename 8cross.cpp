#include <iostream>
using namespace std;

bool ok(int arr[], int c){
    int a[8][5] = {
        {-1},
        {0, -1},
        {0, -1},
        {0, 1, 2, -1},
        {0, 1, 3, -1},
        {1, 4, -1},
        {2, 3, 4, -1},
        {3, 4, 5, 6, -1}
    };
    for(int i = 0; i < c; i++)
    {
        if(arr[i] == arr[c])
        {
            return false;
        }
    }
    for(int i = 0; a[c][i] != -1; i++)
    {
        if(abs(arr[c] - arr[a[c][i]]) == 1)
        {
            return false;
        }
    }
    return true;
}


void print(int arr[], int numSol){
    cout << "Solution " << numSol << endl;
    cout << " " << arr[0] << arr[1] << endl;
    cout << arr[2] << arr[3] << arr[4] << arr[5] << endl;
    cout << " " << arr[6] << arr[7] << endl;
    cout << "-------------------------------------" << endl;
}

int main() {
    int q[8], c = 0, counter = 0;
    q[0] = 1;
    while(c != -1)
    {
        c++;
        if(c == 8)
        {
            counter++;
            print(q, counter);
            c--;
        }
        else
        {
            q[c] = 0;
        }
        while(q[c] < 9)
        {
            q[c]++;
            if(q[c] == 9)
            {
                c--;
                if(c == -1)
                {
                    return 0;
                }
            }
            else if(ok(q, c))
            {
                break;
            }
        }
    }    
}
