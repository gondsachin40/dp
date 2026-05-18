class sparseTreeClass {
public:
    vector<vector<int>> sparseTree;
    bool isMin;
    int n, k;

    sparseTreeClass() {}

    sparseTreeClass(int n, const vector<int>& v, bool isMin) {
        this->n = n;
        this->k = (n > 0) ? (31 - __builtin_clz(n)) : 0;
        this->isMin = isMin;

        this->sparseTree.resize(n, vector<int>(k + 1, 0));

        for (int i = 0; i < n; i++) {
            sparseTree[i][0] = v[i];
        }

        buildSparseTree();
    }

    void buildMinSparseTree() {
        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                int part1 = sparseTree[i][j - 1];
                int part2 = sparseTree[i + (1 << (j - 1))][j - 1];
                sparseTree[i][j] = min(part1, part2);
            }
        }
    }

    void buildMaxSparseTree() {
        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                int part1 = sparseTree[i][j - 1];
                int part2 = sparseTree[i + (1 << (j - 1))][j - 1];
                sparseTree[i][j] = max(part1, part2);
            }
        }
    }

    void buildSparseTree() {
        if (isMin) buildMinSparseTree();
        else buildMaxSparseTree();
    }

    int queryMin(int L, int R) {
        int len = R - L + 1;
        int j = 31 - __builtin_clz(len);
        int part1 = sparseTree[L][j];
        int part2 = sparseTree[R - (1 << j) + 1][j];
        return min(part1, part2);
    }

    int queryMax(int L, int R) {
        int len = R - L + 1;
        int j = 31 - __builtin_clz(len);
        int part1 = sparseTree[L][j];
        int part2 = sparseTree[R - (1 << j) + 1][j];
        return max(part1, part2);
    }

    int query(int L, int R) {
        if (isMin) return queryMin(L, R);
        else return queryMax(L, R);
    }
};
