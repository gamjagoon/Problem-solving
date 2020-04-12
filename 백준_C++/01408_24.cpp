#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	string t1,t2;
	int h1,m1,s1,h2,m2,s2,h3,m3,s3;
	cin>>t1>>t2;
	h1 = atoi(&t1[0]);m1 = atoi(&t1[3]);s1 = atoi(&t1[6]);
	h2 = atoi(&t2[0]);m2 = atoi(&t2[3]);s2 = atoi(&t2[6]);
	if(s1 <= s2){
		s3 = s2 - s1;
		m3 = m2;
	}else{
		s3 = 60 - s1 + s2;
		m3 = m2 - 1;
	}
	if(m1 <= m3){
		m3 = m3 - m1;
		h3 = h2 ;
	}else{
		m3 = 60 - m1 + m3;
		h3 = h2 - 1;
	}
	if(h1 <= h3){
		h3 = h3 - h1;
	}else {
		h3 = 24-h1+h3;
	}
	printf("%02d:%02d:%02d",h3,m3,s3);
	return 0;
}