#include <iostream>
#include <cstring>
#define maxb 200000
using namespace std;

int T,f_hash,s_hash,N,idx;
int id[maxb];
int sz[maxb];
int hashtable[maxb];
string namelist[maxb];

int hashcode(string &str)
{
	int hash = 0;
	for(int i = 0; i < 3;++i)
	{
		if(str[i] == 0)return hash;
		hash *= 26;
		hash += str[i];
	}
	return hash%maxb;
}

int add_hashtable(int hash, string&str)
{
	while(1)
	{
		if(hashtable[hash] == -1)
		{
			hashtable[hash] =  idx;
			id[idx] = idx;
			namelist[idx] = str;
			sz[idx++] = 1;
			return hash;
		}
		else if(namelist[hashtable[hash]] == str){
			return hash;
		}
		hash = (hash + 1) % maxb;
	}
}

int root(int p){
	if(id[p] == p){
		return p;
	}
	else{
		return id[p] = root(id[p]);
	}
}
void make_union(int p,int q)
{
	int idx_1 = hashtable[p];
	int idx_2 = hashtable[q];
	int r_1 = root(idx_1);
	int r_2 = root(idx_2);
	if(r_1 == r_2)return;
	id[r_2] = r_1;
	sz[r_1] += sz[r_2];
}



void input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(int i = 0; i < maxb ; ++i)
	{
		namelist[i].clear();
		id[i] = -1;
		hashtable[i] = -1;
	}
	idx = 0;
	while(N--)
	{
		string A,B;
		cin>>A>>B;
		f_hash = add_hashtable(hashcode(A),A);
		s_hash = add_hashtable(hashcode(B),B);
		make_union(f_hash,s_hash);
		cout<<sz[id[hashtable[f_hash]]]<<'\n';
	}
}

int main()
{
	cin>>T;
	while(T--)
	{
		input();
	}
	return 0;
}