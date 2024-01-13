class Solution {
public:
    int lengthOfLIS(vector<int>&a) {
         int n=a.size();
         
        vector<int>LCS(n);
         int size=0;
         
         // 0 WLA indexing use kar rha hu islie   +1 karke return karunga
         LCS[0]=a[0];
           for(int i=1;i<n;i++)
           {
               int  start=0;
               int end=size;
               int index=size+1;
               while(start<=end)
               {
                   int mid=start+(end-start)/2;
                   if(LCS[mid]<a[i])
                     start=mid+1;
                     else if(LCS[mid]==a[i])
                     {
                         index=mid;
                         break;
                     }
                     else
                     {
                         index=mid;
                         end=mid-1;
                     }
               }
               LCS[index]=a[i];
                     size=max(size,index);
           }
           return size+1;
    }
};