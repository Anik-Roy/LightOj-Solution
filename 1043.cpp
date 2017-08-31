#include <bits/stdc++.h>
using namespace std;

double ab, bc, ca, _ratio;

double check(double ad)
{
    double ae = (ad * ca) / ab, de = (ad * bc) / ab;
    double s1 = (ad + de + ae) / 2.0;
    double s2 = (ab + bc + ca) / 2.0;

    double area1 = sqrt(s1 * (s1 - ad) * (s1 - de) * (s1 - ae));
    double area2 = sqrt(s2 * (s2 - ab) * (s2 - bc) * (s2 - ca));

    double trapiziumArea = fabs(area2 - area1);

    double _rat = area1 / trapiziumArea;

    return _rat;
}

int main()
{
    int t, cs = 0;
    scanf("%d", &t);

    while(t--) {
        scanf("%lf %lf %lf %lf", &ab, &bc, &ca, &_ratio);
        double low = 0.0, high = ab, mid, ans;

        for(int i = 1; i <= 100; i++) {
            mid = (low + high) / 2.0;
            ans = mid;

            if(check(mid) > _ratio)
                high = mid;

            else
                low = mid;
        }

        printf("Case %d: %.10lf\n", ++cs, ans);
    }
}
