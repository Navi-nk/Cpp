#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> list(n,0);
    for(int a0 = 0; a0 < m; a0++){
        int a;
        int b;
        int k;
	int temp,diff=0;
        cin >> a >> b >> k;
	diff=b-a;
	temp=a-1;
	while(diff-->= 0)
	{
		list[temp++] += k;
	} 
        
    }
    return 0;
}
