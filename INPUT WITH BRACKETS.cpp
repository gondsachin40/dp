#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define vi vector < int >
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define me(a, x) memset(a, x, sizeof(a)) 
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl;
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    string t;
    cin.ignore();
    getline(cin , t);
    string s1 = "";
    string s2 = "";
    int i = 0;
    while(i < sz(s)){
        if(s[i] == ',')
        break;
        s1 += s[i];
        i++;
    }
    i++;
    while(i < sz(s)){
        s2 += s[i];
        i++;
    }
    int n = stoi(s1);
    int p = stoi(s2);
    string st = "";
    vector<string> tt;
    for(int i = 0;i<sz(t);i++)
    {
        if(t[i] == '[' || t[i] == ']' || t[i] == ','){
            if(st != " ")
            tt.push_back(st);
            st = "";
        }else{
            st += t[i];
        }
    }
    tt.erase(tt.begin());
    tt.erase(tt.begin());
    vi a;
    for(string x : tt){
        st = "";
        for(char c : x){
            if(c != ' ')
            st += c;
            
        }
        if(st.empty() == false)
        {
            a.push_back(stoi(st));
        }
    }
    // print(a);
    i = 0;
    vector<pair<int,int>> pp;
    while(i < sz(a)){
        pp.push_back({a[i] , a[i + 1]});
        i += 2;
    }
    cout<<n<<" "<<p<<endl;
    for(auto &[u , v] : pp){
        cout<<u<<" "<<v<<endl;
    }
    // print(a);
}
int main(){
//  ios_base::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
 int t = 1;
 // cin >> t;
 while(t--)
 solve();
 return 0;
}
/*
3,2
[[1, 0], [2, 1]]

4,4
[[0, 1], [1, 2], [2, 3], [3, 0]]
  */
