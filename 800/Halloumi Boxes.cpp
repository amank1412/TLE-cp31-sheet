
#include <bits/stdc++.h> 

 
using namespace std;

struct st
{
    int num;
    int id_prev;
};

bool f(st &a, st&b) {
    return a.num < b.num;
}

int main() {


    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t;
    cin >> t;
    vector<bool> ans(t);

 	int n, k;

 	st v[101];

    int mx = 0;
	bool need_sort = false;
    for (int i = 0; i < t; i++) {
    	cin >> n >> k;
    	
        mx = 0;
        need_sort = false;

    	for (int j = 0; j < n; j++) {

    		cin >> v[j].num;
            if (v[j].num >= mx) {       
                mx = v[j].num;
            } else {
                need_sort = true;
            }
            v[j].id_prev = j;
    	}

        bool flag = true;
        if (need_sort) {
            sort(v, v + n, f);

            for (int j = 0; j < n; j++) {
                if (abs(v[j].id_prev - j) >= k) {
                    flag = false;
                    break;
                }
            }
        }
    	
        ans[i] = flag;
    }

    for (int i = 0; i < t; i++) {
        cout << (ans[i] ? "YES" : "NO");
        if (i != t - 1)
            cout << endl;
    }
		

	return 0;
}
