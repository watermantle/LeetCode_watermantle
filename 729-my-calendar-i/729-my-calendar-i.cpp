class MyCalendar {
public:
    map<int, int> calendar;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = calendar.lower_bound(start);
        if (next != calendar.end() && next->first < end) return false;
        if (next != calendar.begin() && (--next)->second > start) return false;
        calendar[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */