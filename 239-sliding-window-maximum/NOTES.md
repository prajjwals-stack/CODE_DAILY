Lets start with simple brute force solution,

We will simply traverse the array and in each window we will find the maximum and push it into a vector and return the vector.

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=k-1;
        vector<int>v;
        while(j<nums.size()){
            int maxi=nums[i];                               //initialising maximum with first element  
            for(int p=i+1;p<=j;p++){
                maxi=max(maxi,nums[p]);            // finding the maximum in each window of size k 
            }
            v.push_back(maxi);   //pushing maximum  of each window into vector 
            i++;
            j++;
            
        }
        return v; 
    }

This approach is extremely simple and easy to understand but the problem is the time complexity of this approach is O(N^2).
To reduce the time complexity we will use sliding window approach and also we need a data structure in which insertion and deletion is possible from both ends, so either we can use a double ended queue (DEQUE) or a doubly linkedlist based data structure (LIST available in c++ stl).

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int i=0,j=0;
        vector<int>v;
        if(k>nums.size()){                             //boundary condition when given Window size is greater then size if the array the we will return the maximum element in the array
            v.push_back(*max(nums.begin(),nums.end()));
        }
        list<int>q;             
        while(j<nums.size()){                //traverse until j reach the size of array
            if(q.empty()){
                q.push_back(nums[j]);    //if list is empty we will push from back into the list
             }
            else{
                while(!q.empty() && q.back()<nums[j]){   //if the exisitng element in the list is less then nums[j] we will pop the element 
                    q.pop_back();
                }
                q.push_back(nums[j]);
            }
            if(j-i+1<k){       //increment j until we hit the window size
                j++;
            }
            else if(j-i+1==k){
            v.push_back(q.front());
            if(q.front()==nums[i]){     // if the elemnt is out of bound the remove it from the list 
                q.pop_front();
            }
            i++;        //slide the window 
            j++;
            }
            
            
        }
        return v;
    }
Time complexity of this approach -O(N)
