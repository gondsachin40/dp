class range_distinct{
    public:
    range_distinct(){
        
    }
    map<int,int> mp;
    int count = 0;
    void insert(int x){
        mp[x]++;
        if(mp[x] == 1){
            count++;
        }
    }
    
    void remove(int x){
        if(!mp.count(x)) return;
        
        mp[x]--;
        if(mp[x] == 0){
            mp.erase(x);
            count--;
        }
    }
};

void solve(){
    range_distinct mp = range_distinct();
    mp.insert(1);
    mp.insert(2);
    mp.insert(3);
    mp.insert(4);
    mp.insert(1);
    mp.remove(1);
    
    cout<<mp.count<<nl;
    
    mp.remove(1);
    mp.remove(1);
    mp.remove(1);
    mp.remove(1);
    
    cout<<mp.count<<nl;
    
}
