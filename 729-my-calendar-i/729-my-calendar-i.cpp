class MyCalendar {
public:
    set<pair<int,int>> calendar;
    
    MyCalendar() {
        //we have calendar
    }
    
    bool book(int start, int end) {
        for(auto it: calendar){
            if(start>=it.second or it.first>=end){
                continue;
            }
            return false;
        }
        calendar.insert({start,end});
        return true;
    }
};