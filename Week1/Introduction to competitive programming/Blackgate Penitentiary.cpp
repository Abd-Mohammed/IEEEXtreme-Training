#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b){
    return a.second < b.second;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;


    // name height
    vector<pair<string, int>> input(n); // 0-based index

    // 0-based index
    for (int i = 0; i < n; i += 1) {
        cin >> input[i].first >> input[i].second;
    }

    sort(input.begin(), input.end(), compare);

    // height, start index - last index
    // new same height update last index.

    // height key
    // first-last index value
    map<int,pair<int , int>>cnt;
    set<string> row;

    int val = 0;

    for (int i = 0 ; i < n ; i += 1){

        if(cnt.find(input[i].second) != cnt.end()){
            cnt[input[i].second] = {cnt[input[i].second].first,  i + 1};
        }else{
            if(!row.empty()){
                for(string s : row){
                    cout << s << " ";
                }
                cout << cnt[val].first << " " << cnt[val].second << '\n';
                row.clear();
            }
            cnt[input[i].second] = {i + 1,  i + 1};
        }
        row.emplace(input[i].first); // emplace faster than push
        val = input[i].second;// cnt first_last index input[val].first input[val].second 0- 0

        if(i == n - 1 && !row.empty()){
            for(string s : row){
                cout << s << " ";
            }
            cout << cnt[val].first << " " << cnt[val].second << '\n';
            row.clear();
        }
    }


    return 0;
}

