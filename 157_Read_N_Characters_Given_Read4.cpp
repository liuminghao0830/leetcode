#include<iostream>

using namespace std;

int read4(char *buff);

class Solution{
public:
	int read(char *buf, int n) {
        int res = 0;
        for (int i = 0; i <= n / 4; ++i){
        	int cnt = read4(buf + res);
        	if (cnt == 0) return min(n, res);
        	res += cnt;
        }
        return min(n, res);
    }
};