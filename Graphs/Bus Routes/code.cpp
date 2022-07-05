class pairr
{
public:
    int bus, csf;
    pairr() {}
    pairr(int a, int b)
    {
        bus = a;
        csf = b;
    }
};
class Solution
{
public:
    // i-th vector of routes represent the stops at which i-th bus goes.
    // i-th bus kon kon se stops pr jaa rhi hai(ye bhi ek tarah ki adjacency list given hai.)
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;

        map<int, set<int>> BuseOnIthStops;
        // BusOnIthStops will represent all the buses, that comes at i-th stop.
        for (int bus = 0; bus < routes.size(); bus++)
        {
            for (auto stops : routes[bus])
                BuseOnIthStops[stops].insert(bus);
        }



        queue<pairr> q;
        // ab source stop par Jo Jo buses aati hain, unko queue main daal do, with count so far = 1.
        for (auto buses : BuseOnIthStops[source])
            q.push(pairr(buses, 1));


        bool vis[routes.size()]; // to mark the visited buses, number of buses = size of routes vector
        memset(vis, false, sizeof(vis));



        while (!q.empty())
        {
            pairr cur_bus = q.front();
            q.pop();



            if (vis[cur_bus.bus] == false)
            {
                vis[cur_bus.bus] = true;
                // ab current wali bus kon kon se stops par jaati hai, agar wo stop, target hai, toh return the count so far, and it will be minmum.
                for (auto stops : routes[cur_bus.bus])
                {
                    if (stops == target)
                        return cur_bus.csf;
                }
                //jab koi bhi stop, target ke equal ni mila toh,
                
                for (auto Stops : routes[cur_bus.bus])//ab fir se, current wali bus kon kon se stops pr jaati hai
                {
                    for (auto bus : BuseOnIthStops[Stops])//and har wo k-th stop jispe current bus jaati hai, uspr kon kon si buses jaati hain
                    {
                        if (vis[bus] == false) //ab wo buses jo k-th stop pr jaati hain and used ni hain, toh usko push krdo, with count so far of current bus+1.
                        {
                            q.push(pairr(bus, cur_bus.csf + 1));
                        }
                    }
                }
            }
        }
        return -1;
    }
};
