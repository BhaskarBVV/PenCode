// queue main bina mark krne daalne hai nodes, agar mark krke daaloge, toh maanlo agar koi aur node (y) isi (x) se connected hai toh, ye dobara (x) ni dal paayega na queue main, 
// aur jab multiple times queue main ni dal paayega, toh hume kaise pata chalega ki ye pehle visit hua hai ya ni, and multiple times toh tab add hoga na jab wo visit na hua ho
// jab uski processing ki baari ni aai ho,


//steps
// pehle queue main unvisted node ko daal do, bina mark kre
// ab jab tak queue empty na ho jaye tab tak:
    // front() se node ko nikalo.
    // usse check kro kya wo alreay marked tha
    // agar already marked tha wo, iska matlab ki cycle hai
    // agra ni tha visted, toh mark kro
    // and uske adjacent unvisted nodes ko bina mark kre daal do


bool isCycle(int V, vector<int> adj[]) 
    {
        vector<bool> vis(V, false);
        queue<int> q;
        int temp;
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                q.push(i);
                while (!q.empty())
                {
                    temp = q.front();
                    q.pop();
                    if (vis[temp] == true)
                        return true;
                    vis[temp] = true;
                    for (auto it : adj[temp])
                        if (vis[it] == false)
                            q.push(it);
                }
            }
        }
        return false;
    }
