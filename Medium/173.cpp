class UndergroundSystem {
public:
    
    map<int, pair<int, string>> mp1; // id, <time, station>
    map<string, pair<int, int>> mp2; // station1_station2, <total dis, freq>
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp1[id] = make_pair(t, stationName);
    }
    
    void checkOut(int id, string stationName, int t) {
        int prevTime = mp1[id].first;
        string prevStation = mp1[id].second;
        mp1.erase(id);
        
        mp2[prevStation + "_" + stationName].first += (t - prevTime);
        mp2[prevStation + "_" + stationName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double total = mp2[startStation + "_" + endStation].first;
        double freq = mp2[startStation + "_" + endStation].second;
        
        return total / freq;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */