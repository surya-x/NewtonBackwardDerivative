#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, i, j;
    cout<<"Enter the number of points = ";
    cin>>n;
    float arr_x[n], arr_y[n][n], point;
    cout<<"\n\tPlease fill the following values =>\n";

    for(i = 0; i < n; i++){
       cout<<"X"<<i+1<<" = ";
        cin>>arr_x[i];
       cout<<"Y"<<i+1<<" = ";
        cin>>arr_y[i][0];
    }

    cout<<"The point of which to find the differentiation = ";
    cin>>point;

    /* CALCULATING INTERPOLATION TABLE */
    for (i=1; i<n; i++)
        for(j=i; j<n; j++)
            arr_y[j][i] = arr_y[j][i-1] - arr_y[j-1][i-1];


    /* TODO: "IMPROVE" - Printing part of the INTERPOLATION TABLE */
    cout<<endl;
    for (i = 0; i < n; i++) {
        cout << setw(5) << arr_x[i]
             << "\t\t";
        cout << setw(5) << arr_y[i][0]
             << "\t\t";
        for (j = 0; j <= i; j++)
            cout << setw(5) << arr_y[i][j]
                 << "\t\t";
        cout << endl;
    }
    cout<<endl;
    /* Printing Ends here */

    /* ----------------------ALGORITHM STARTS HERE -- Calculating [df/dx] -------------------*/
    int new_nth = n - 1;
    float h, ans = 0;
    h = arr_x[1]-arr_x[0];

    /* Calculating the index(out of n) to which our point(the one to calculate) belongs.*/
    for(i=n-1; i>=0; i--){
        if(arr_x[i] == point){
            new_nth = i;
            break;
        }
    }

    /* FORMULA IMPLEMENTATION of finding derivative using newton backward diff. formula */
    /* 
        [df/dx]   => 1/h [ ∇Yn + 1/2*∇Y^2n + 1/3*∇Y^3n + 1/4*∇Y^4n + .....]
        at X = Xn
    */
    for(i=1; i<= new_nth; i++){
        cout<<arr_y[new_nth][i]/i<<"\t\t\t\t";
        ans = ans + (arr_y[new_nth][i]/i);
        cout<<ans<<endl;
    }
    ans /= h;

    /* TODO : IMPROVE : Printing of the output of the program. */
    cout<<"[df/dx] = " ans;

    return 0;
}
