// My Calendar I

class MyCalendar {
public:
    set<pair<int, int>> memo;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto itr = memo.lower_bound({start, end});
        if (itr != memo.end() && end > itr->first) return false;
        if (itr != memo.begin() && (--itr)->second > start) return false;
        
        memo.insert({start, end});
        return true;
    }
};