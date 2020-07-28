#include <iostream>

using namespace std;

int main () {
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int det = a*e - b*d;
	int x = e*c - f*b;
	int y = a * f - d * c;
	cout<<x/det<<" "<<y/det;
}
