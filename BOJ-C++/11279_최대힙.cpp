#include <iostream>
using namespace std;
class Max_heap
{
private:
	int arr[100001];
	int i;
public:
	Max_heap():i(0){}
	void swap(int &a,int &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	void swim(int k)
	{
		while(k > 1 && arr[k/2] < arr[k])
		{
			swap(arr[k / 2], arr[k]);
			k/=2;
		}
	}
	void sink(int k)
	{
		while (2 * k <= i)
		{
			int j = 2*k;
			if((j < i) && (arr[j] < arr[j+1]))
				j++;
			if(arr[k] > arr[j])
				break;
			swap(arr[k], arr[j]);
			k = j;
		}
	}
	void push(int n)
	{
		arr[++i] = n;
		swim(i);
	}
	void pop()
	{
		if (i == 0)
		{
			cout << "0\n";
			return;
		}
		cout << arr[1] << '\n';
		swap(arr[1], arr[i--]);
		sink(1);
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin >> n;
	Max_heap pq;
	int tmp;
	while (n--)
	{
		cin >> tmp;
		if(tmp == 0)
		{
			pq.pop();
		}
		else{
			pq.push(tmp);
		}
	}
}