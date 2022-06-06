class Solution {
public:
   int dis(vector<int> p,vector<int> q){
        return pow((p[0]-q[0]),2) + pow((p[1]-q[1]),2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int a[6];
        a[0]=dis(p1,p2);
        a[1]=dis(p1,p3);
        a[2]=dis(p1,p4);
        a[3]=dis(p2,p3);
        a[4]=dis(p2,p4);
        a[5]=dis(p3,p4);
        sort(a,a+6);
        if(a[0]!=a[1]||a[0]!=a[2]||a[0]!=a[3]||a[1]!=a[2]||a[1]!=a[3]||a[2]!=a[3]||a[4]!=a[5])
            return false;
        if(a[4]!=2*a[0])
            return false;
        if(a[0]==0)
            return false;
        return true;
    }
};