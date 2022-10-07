class MyCalendarTwo {
public:
    map<int,int>m;
    MyCalendarTwo() {
        m=map<int,int>();
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int sum=0;
        for(auto it:m){
            sum+=it.second;
            if(sum>2){
                m[start]--;
                m[end]++;
                return false;
            }
            
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */