#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define vi vector < int >
#define sz(a) ((int) (a).size())
#define ll long long 
#define ull unsigned long long
#define me(a, x) memset(a, x, sizeof(a)) 
#define pb emplace_back
#define all(a) (a).begin(),(a).end()
#define print(a) for(auto x : a) cout << x << " " ; cout<< endl
#define scan(a) for (auto &x:a)cin>>x;
#define ld __float128
using namespace std;
vector<vector<int>>sparse_tree;




// class sparseTreeClass{
//     public:
//     vector<vector<int>>sparseTree;
//     vector<int>v;
//     bool isMin;
//     int n,k;
//     sparseTreeClass (int n,vector<int>&v,bool isMin){
//         this->k = log2(n);
//         this->n = n;
//         this->v = v;
//         (this.sparseTree).resize(n,vector<int>(k+1,0));
//         this->isMin = isMin;
//         buildSparseTree();
//     }
//     void buildMinSparseTree(){
//         for (int i = 0;i < n;i++){
//             sparseTree[i][0] = v[i];
//         }
//         for (int j = 1;j <= k;j++){
//             for (int i = 0;i + (1 << j ) -1< n;i++){
//                 int part1 = sparseTree[i][j-1],
//                 part2 = sparseTree[i + (1 << (j - 1) )][j-1];
//                 sparseTree[i][j] = min(part1,part2);
//             }
//         }
//     }
//     void buildMaxSparseTree(){
//         for (int i = 0;i < n;i++){
//             sparseTree[i][0] = v[i];
//         }
        
//         for (int j = 1;j <= k;j++){
//             for (int i = 0;i + (1 << j) - 1 < n;i++){
//                 int part1 = sparseTree[i][j-1],
//                 part2 = sparseTree[i + (1 << (j-1))][j-1];
//                 //par1 and part 2 overlap each other for example 7 will be divied into 0 to 4 and 4 to 7 inclusive 
//                 sparseTree[i][j] = max(part1,part2);
//             }
//         }
//     }
//     void buildSparseTree(){
//         if (isMin)
//             buildMinSparseTree();
//         else 
//             buildMaxSparseTree();
//     }
//     int queryMin(int &L ,int &R){
//         int j = log2(R - L + 1);
//         int part1 = sparseTree[L][j],
//         part2 = sparseTree[R - ( 1 << j) + 1][j];// we add 1 here because R is inclusive
//        return min(part1,part2); 
//     }
//     int queryMax(int &L,int &R) {
//         int j = log2(R-L + 1);// maximum power of 2 that could be reached before size of subarray
//         int part1 = sparseTree[L][j],
//         part2 = sparseTree[R - (1 << j) + 1][j];
//         return max(part1,part2);
//     }
//     int query(int &L,int &R){
//         if (isMin)return queryMin(L,R);
//         else return queryMax(L,R);
//     }
// };









int n,k;

void build_tree(vector<int>&v,vector<vector<int>>&sparse_tree){
    //firstly we fill first column with given
    for (int i = 0;i < n;i++){
       sparse_tree[i][0] = v[i]; 
    }
    //then we will fill second column till last column
    for (int j = 1; (1<<j) <= n;j++){
        for (int i = 0; (i + (1 << j) - 1 )< n;i++){
            //for filling j column we left set and right set 
            //the left set example if we take 4 index with pow 2
        //its left part will be previous[i][j-1] were j-1 means half of current power 
        // on the right part it will use previous[i + len ][j-1]because we have to 
        //previous row right part we are using  1<<j
            int left = sparse_tree[i][j-1];
            int right = sparse_tree[i+(1<<(j-1))][j-1];
            sparse_tree[i][j] = min(left,right);
        }
    }
}

int query(vector<vector<int>> & sparse_tree,int L,int R){
    // to get the maximum power of 2 which is less than size of array
    int j = (int)log2(R - L + 1);
    int left = sparse_tree[L][j];
    int right =sparse_tree[R - (1 << j)+ 1][j];
    return min(left,right);
}

int main(){
 ios_base::sync_with_stdio(false),cin.tie(0);
 cout.tie(0);
 vector<int>v = {7 ,2 ,3 ,0 ,5 ,10 ,3 ,12 ,18};
 n = v.size();
 k = log2(n);
 //for the maximum column side of sparse table
 //we are using log to the base 2 to find minimum column size for sparse_tree
 
 sparse_tree.resize(n,vector<int>(k,0));
 build_tree(v,sparse_tree);
 cout<<query(sparse_tree,0,2); 
 return 0;
}
