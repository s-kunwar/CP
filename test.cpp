class Solution {
public:
    int trap(vector<int>& height) {
        int maxlevel=0;
        int len=height.size();
        vector<int>water(len,0);
        for(int i:height){if(i>maxlevel) maxlevel=i;}

        for(int i=1;i<=maxlevel;i++){
            int l=-1,r=-1;
            for(int ind=0;ind<len;ind++){
                if(l==-1 && height[ind]>=i) l=ind;
                else if(height[ind]>=i) r=ind;
            }
            for(int ind=l+1;ind<r;ind++) if(height[ind]<i) water[ind]++;
            
        }
        int sum=0;
        for(int ans:water) sum+=ans;

        return sum;
    }
};