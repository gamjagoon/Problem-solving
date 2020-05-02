/*  Data : 2020.04.16
 *  Command: g++ -O3 -Ofast w03_sort.cpp -o a.out && ./a.out > out.txt && rm a.out 
 *  Description: Outputs each Sorting algorithm as time-data chart
 * */
#include<iostream>
#include<algorithm>
#include<chrono>
#include<vector>
#include<cstdlib>
#include<random>
#include<iomanip>
using namespace std;
using namespace chrono;


template <typename T>
void Swap(T &a,T &b){
	T tmp = a;a = b;b = tmp;
}

struct Timer{
	high_resolution_clock::time_point st,et;
	~Timer(){};
	void start (){
		st = high_resolution_clock::now();
	}
	double res(){
		et = high_resolution_clock::now();
		return duration<double>(et-st).count()/1000;
	}
};

struct sec{
	double Mil[6];
};

struct Data{
	sec B,S,I,M,Q1,Q2,Q3,H,L;
	void view_data(){
		cout.setf(ios::right);
		cout<<setfill(' ')<<setw(10)<<"|"<<setw(16)<<"Random1000|"<<setw(16)<<"Revers1000|"<<setw(16)<<"Random10000|"<<setw(16)<<"Reverse10000|"<<setw(16)<<"Random100000|"<<setw(16)<<"Reverse100000|"<<endl;
		cout<<fixed;cout.precision(9);
		cout<<setw(10)<<"Bubble|";for(auto i : B.Mil){cout<<setw(15)<<i<<'|';};cout<<endl;
		cout<<setw(10)<<"Insertion|";for(auto i : I.Mil){cout<<setw(15)<<i<<'|';};cout<<endl;
		cout<<setw(10)<<"Merge|";for(auto i : M.Mil){cout<<setw(15)<<i<<'|';};cout<<endl;
		cout<<setw(10)<<"Quick1|";for(auto i : Q1.Mil){cout<<setw(15)<<i<<'|';};cout<<endl;
		cout<<setw(10)<<"Quick2|";for(auto i : Q2.Mil){cout<<setw(15)<<i<<'|';};cout<<endl;
		cout<<setw(10)<<"Quick3|";for(auto i : Q3.Mil){cout<<setw(15)<<i<<'|';};cout<<endl;
		cout<<setw(10)<<"Heap|";for(auto i : H.Mil){cout<<setw(15)<<i<<'|';};cout<<endl;
		cout<<setw(10)<<"Library|";for(auto i : L.Mil){cout<<setw(15)<<i<<'|';};cout<<endl;
	}
};

void bubble(vector<int>&arr){
	int n = arr.size();
	for(int i = 0; i < n; i++){
		int flag = 1;
		for(int j = 0 ; j < n-1; j++){
			if(arr[j] > arr[j+1]){
				flag = 0;
				Swap(arr[j],arr[j+1]);
			}
		}
		if(flag)break;
	}
}

void selection(vector<int>&arr){
	int n = arr.size();
	for(int i = 0; i < n; ++i){
		int idx = i;
		for(int j = i +1; j < n;j++){
			if(arr[j] < arr[idx])idx = j;
		}
		Swap(arr[i],arr[idx]);
	}
}

void insertion(vector<int>&arr){
	int n = arr.size();
	for(int i = 0 ; i < n-1;i++){
		int key = arr[i+1];int j;
		for(j = i;j>=0;j--){
			if(arr[j] > key)arr[j+1] = arr[j];
			else break;
		}
		arr[j+1] = key;
	}
}

void merge(vector<int>&arr,int p,int q,int r){
	int n = arr.size();
	int i = p,j = q+1,k = p;
	vector<int>tmp(n);tmp.push_back(0);
	while(i <= q || j <= r){
		if(i > q)tmp[k++] = arr[j++];
		else if(j > r)tmp[k++] = arr[i++];
		else if(arr[i] <= arr[j])tmp[j++] = arr[i++];
		else tmp[k++] = arr[j++];
	}for(int i = p; i <= r; i++)arr[i] = tmp[i];
}

void mergeSort(vector<int>&arr,int p,int r){
	if(p < r){
		int q = (p+r)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}

void quick_last(vector<int>&arr,int left,int right){
	int i = left,j = right;
	int pivot = arr[right];
	do{
		while(arr[i] < pivot)i++;
		while(i < j && arr[j] > pivot)j--;
		if(i <= j){Swap(arr[i],arr[j]);
		i++;j--;}
	}while(i <= j);
	if(left < j)quick_last(arr,left,j);
	if(i < right)quick_last(arr,i,right);
}

void quick_mid(vector<int>&arr,int left,int right){
	int i = left,j = right;
	int pivot = arr[(i+j)/2];
	do{
		while(arr[i] < pivot)i++;
		while(arr[j] > pivot)j--;
		if(i <= j){Swap(arr[i],arr[j]);
		i++;j--;}
	}while(i <= j);
	if(left < j)quick_mid(arr,left,j);
	if(i < right)quick_mid(arr,i,right);
}

void randompivot(vector<int>&arr,int left,int right){
	int pvt{left + rand()%(right-left+1)};
	swap(arr[(left+right)/2],arr[pvt]);
}

void quick_random(vector<int>&arr,int left,int right){

	int i = left,j = right;
	randompivot(arr,left,right);
	int pivot = arr[(i+j)/2];
	do{
		while(arr[i] < pivot)i++;
		while(arr[j] > pivot)j--;
		if(i <= j){Swap(arr[i],arr[j]);
		i++;j--;}
	}while(i <= j);
	if(left < j)quick_random(arr,left,j);
	if(i < right)quick_random(arr,i,right);
}
void heapify(vector<int>&arr,int i){
	int c = i*2 + 1;int n = arr.size();
	if(c < n && arr[c] < arr[c+1])c++;
	if(arr[i] < arr[c])swap(arr[i],arr[c]);
	if(c <= n / 2)heapify(arr,c);
}

void heapsort(vector<int>&arr){
	int n = arr.size();
	for(int i = n /2;i >= 0;--i){
		heapify(arr,i);
	}
	for(int i = n-1; i >= 0;--i){
		swap(arr[i],arr[0]);
		int root =0,c = 1;
		do{
			c = 2*root+1;
			if(c < i -1 && arr[c] < arr[c+1])c++;
			if(c < i && arr[root] < arr[c]){
				swap(arr[root],arr[c]);
			}
			root = c;
		}while(c < i);
	}
}

void sort_std(vector<int>&arr){
	sort(arr.begin(),arr.end(),[](int a,int b){return a < b;});
}

// constnumber for this program
// N = test cast range 0~1 Acase 2~3 B case 4~5 C case
// A,B,C are the number of data sets
constexpr int N = 6;
constexpr int A = 1000;
constexpr int B = 10000;
constexpr int C = 100000;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int>dis_A(1,A);
	uniform_int_distribution<int>dis_B(1,B);
	uniform_int_distribution<int>dis_C(1,C);
	vector<int>arr[6];
	arr[0].resize(A);arr[1].resize(A);
	arr[2].resize(B);arr[3].resize(B);
	arr[4].resize(C);arr[5].resize(C);
	for(auto& i : arr[0]){i = dis_A(gen);}
	for(int i = A;i >=1;--i){arr[1][A-i]=i;}
	for(auto& i : arr[2]){i = dis_B(gen);}
	for(int i = B;i >=1;--i){arr[3][B-i]=i;}
	for(auto& i : arr[4]){i = dis_C(gen);}
	for(int i = C;i >=1;--i){arr[5][C-i]=i;}
	Data result;
	Timer A;
	for(int i = 0; i < N;i++){
		vector<int>cp(arr[i]);
		A.start();
		bubble(cp);
		result.B.Mil[i] = A.res();
	}
	for(int i = 0; i < N;i++){
		vector<int>cp(arr[i]);
		A.start();
		selection(cp);
		result.S.Mil[i] = A.res();
	}
	for(int i = 0; i < N;i++){
		vector<int>cp(arr[i]);
		A.start();
		insertion(cp);
		result.I.Mil[i] = A.res();
	}
	for(int i = 0; i < N;i++){
		vector<int>cp(arr[i]);
		int end = cp.size()-1;
		A.start();
		mergeSort(cp,0,end);
		result.M.Mil[i] = A.res();
	}	
	for(int i = 0; i < N;i++){
		vector<int>cp(arr[i]);
		int end = cp.size()-1;
		A.start();
		quick_last(cp,0,end);
		result.Q1.Mil[i] = A.res();
	}
	for(int i = 0; i < N;i++){
		vector<int>cp(arr[i]);
		int end = cp.size()-1;
		A.start();
		quick_mid(cp,0,end);
		result.Q2.Mil[i] = A.res();
	}
	for(int i = 0; i < N;i++){
		vector<int>cp(arr[i]);
		int end = cp.size()-1;
		A.start();
		quick_random(cp,0,end);
		result.Q3.Mil[i] = A.res();
	}
	for(int i = 0; i < N;i++){
		vector<int>cp(arr[i]);
		int end = cp.size()-1;
		A.start();
		heapsort(cp);
		result.H.Mil[i] = A.res();
	}
	for(int i = 0; i < N;i++){
		vector<int>cp(arr[i]);
		int end = cp.size()-1;
		A.start();
		sort_std(cp);
		result.L.Mil[i] = A.res();
	}
	result.view_data();
}