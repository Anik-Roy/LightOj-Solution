#include <iostream>
using namespace std;

int main()
{
    int t, x1, y1, x2, y2, n, a, b;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        cout << "Case " << i << ":" << endl;
        while(n--) {
            cin >> a >> b;
            if(a < x1 || a > x2 || b < y1 || b > y2) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    return 0;
}

