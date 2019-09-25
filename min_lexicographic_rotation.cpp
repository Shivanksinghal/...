#include<bits/stdc++.h>
using namespace std;
#define MAXN 200010

struct ind{
	int t[3];
};
ind L[MAXN];

int suf[20][MAXN]; 

bool cmp(struct ind a,struct ind b){
	if(a.t[0]==b.t[0]){
	 	if(a.t[1]<b.t[1])return true;
	 	return false;
	}
	if(a.t[0]<b.t[0])return true;
	return false;
	//return a.t[0]==b.t[0] ?(a.t[1]<b.t[1] ?1: 0): (a.t[0]<b.t[0] ?1: 0);	
}

int main()
{
 	string s;
 	cin >> s;
 	int len1 = s.length();
 	string s2 = s + s;
 	//cout << s2 << endl;
 	int len = s2.length();
 	for(int i = 0; i < len; ++i){
 	 	suf[0][i] = s2[i] - 'a';
 	}
 	int step = 1, cnt = 1;
 	while(cnt < len){
 		for(int i = 0; i < len; ++i){
 			L[i].t[0] = suf[step - 1][i];
 			L[i].t[1] = (i + cnt < len) ? suf[step - 1][i + cnt] : -1;
 			L[i].t[2] = i;
 	   	}
 	   	sort(L, L+len, cmp);
 		for(int i = 0; i < len; ++i){
 			if(i == 0){
 			 	suf[step][L[i].t[2]] = 0;
 			 	continue;
 		 	}
 		 	if(L[i - 1].t[0] == L[i].t[0] && L[i - 1].t[1] == L[i].t[1])
 		 		suf[step][L[i].t[2]] = suf[step][L[i - 1].t[2]];
 		 	else
 		 		suf[step][L[i].t[2]] = i; 
 		}
 		++step;
 	 	cnt *= 2;
 	}
 	int min_index = 0, minval = suf[step-1][0];
 	for(int i = 1; i < len1; ++i){
 		if(suf[step-1][i] < minval){
 		 	min_index = i;
	 	}
 	}
 	//for(int i = 0; i < len; ++i){
 	//	cout <<	suf[step-1][i] << " ";
 	//}

   	for(int i = min_index; i < len1 + min_index; ++i){
		cout << s2[i];
	}
	cout << endl;
}