class MyCalendarThree {
public:
    map<int,int>m;
    MyCalendarThree() {
        m=map<int,int>();
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int max_sum=0,sum=0;
        for(auto it:m){
            sum+=it.second;
            
            max_sum=max(max_sum,sum);
        }
        return max_sum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */