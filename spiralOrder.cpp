vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> res;
    int r = A.size();
    int c = A[0].size();
    int t = 0;
    int b = r - 1;
    int l = 0;
    int right = c - 1;
    int dir = 0;
    
    LOOP:while(t <= b && l <= right){
        if(dir == 0){
            for(int i = l; i <= right; i++){
                res.push_back(A[t][i]);
            }
            dir = 1;
            t++;
            goto LOOP;
        }
        else if(dir == 1){
            for(int i = t; i <= b; i++){
                res.push_back(A[i][right]);
            }
            right--;
            dir = 2;
            goto LOOP;
        }
        else if(dir == 2){
            for(int i = right; i >= l; i--){
                res.push_back(A[b][i]);
            }
            b--;
            dir = 3;
            goto LOOP;
        }
        else if(dir == 3){
            for(int i = b; i >= t; i--){
                res.push_back(A[i][l]);
            }
            l++;
            dir = 0;
            goto LOOP;
        }
    }
    return res;
}
