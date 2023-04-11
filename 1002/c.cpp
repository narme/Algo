#include <iostream>
#include <math.h>

using namespace std;

int solve(double x1, double y1, double r1, double x2, double y2, double r2){
    double distanceOfdots = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    
    if(distanceOfdots == 0 && r1 == r2) return -1;
    else if(distanceOfdots == r1 + r2 || distanceOfdots == abs(r1 - r2)) return 1;
    else if(abs(r1 - r2) < distanceOfdots && distanceOfdots < r1 + r2) return 2;
    else if(abs(r1 - r2) > distanceOfdots || distanceOfdots > r1 + r2) return 0;
    
    return 0;
}

int main(){
    int n;
    double x1, y1, r1, x2, y2, r2;
    cin >> n;
    while(n != 0){
        //scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        cout << solve(x1, y1, r1, x2, y2, r2) << "\n";
        n--;
    }
}