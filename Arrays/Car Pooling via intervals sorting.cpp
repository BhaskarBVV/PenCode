// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
// trip[i] = [numPassengersi, fromi, toi]
// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false

// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true

// Input: trips = [[2,1,5],[3,5,7]], capacity = 3
// Output: true

// Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
// Output: true

class Solution {
public:
    bool carPooling(vector<vector<int>>& t, int c) 
    {
      // divided the trip array into two arrays:
      // 1. array with starting intervals and the number of passengers at that place.
      // 2. array with ending intervals and the number of passengers that will drop at that place,( which is bascially the same)
      // ex->trip=[[c1,x1,y1],[c2,x2,y2]];
      // starting points array->>[{x1,c1},{x2,c2}];
      // ending points array->>[{y1,c1},{y2,c2}];
      // sort both of them ^^.
      // now loop until both array ends, (with the same logic of merging two sorted ararys.)
      // at each starting point add passengers=ci if ci+tot<=capacity and at each ending point remove the passenegers assigned with that ending point.
        vector<pair<int,int>>beg,ed;
        for(auto it: t)
        {
            beg.push_back({it[1],it[0]});
            ed.push_back({it[2],it[0]});
        }
        sort(beg.begin(),beg.end());
        sort(ed.begin(),ed.end());
        int tot=0, i=0,j=0, n=t.size();
        while(i<n && j<n)
        {
            if(beg[i].first<ed[j].first)
            {
                if(c-tot<beg[i].second) // more passengers cannot be added due to lack of seats 
                    return false;
                else
                    tot+=beg[i].second;
                i++;
            }
            else if(beg[i].first>ed[j].first)
            {
                tot-=ed[j].second;
                j++;
            }
            else
            { 
              // if both ending and starting points are same, then remove the passengers associated with ending point and add the passengers associated with the starting point.
                tot-=ed[j].second;
                tot+=beg[i].second;
                i++;
                j++;
            }
        }
        return true;
    }
};
