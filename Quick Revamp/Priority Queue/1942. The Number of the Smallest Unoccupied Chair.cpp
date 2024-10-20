#include <bits/stdc++.h>
using namespace std;

class IncomingFriend
{
public:
    int incomingTime;
    int leavingTime;
    int FriendNumber;

    IncomingFriend(int a, int b, int c)
    {
        this->incomingTime = a;
        this->leavingTime = b;
        this->FriendNumber = c;
    }
};

class Sitting
{
public:
    int leavingTime;
    int chairNumber;

    Sitting(int a, int b)
    {
        leavingTime = a;
        chairNumber = b;
    }
};

class Solution
{

public:
    struct comp1
    {
        bool operator()(IncomingFriend a, IncomingFriend b)
        {
            return a.incomingTime > b.incomingTime;
        }
    };

    struct comp2
    {
        bool operator()(Sitting a, Sitting b)
        {
            return a.leavingTime > b.leavingTime;
        }
    };
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        priority_queue<IncomingFriend, vector<IncomingFriend>, comp1> incoming_friends;
        priority_queue<Sitting, vector<Sitting>, comp2> friends_sitting;
        priority_queue<int, vector<int>, greater<int>> free_chairs;
        // vector<int> chairs(times.size(), -1);
        for (int i = 0; i < times.size(); i++)
        {
            free_chairs.push(i);
            incoming_friends.push(IncomingFriend(times[i][0], times[i][1], i));
        }

        while (incoming_friends.size() != 0)
        {
            IncomingFriend FriendArrived = incoming_friends.top();
            incoming_friends.pop();
            while (friends_sitting.size() > 0 && FriendArrived.incomingTime >= friends_sitting.top().leavingTime)
            {
                Sitting friend_sitting = friends_sitting.top();
                // chairs[friend_sitting.chairNumber] = -1;
                free_chairs.push(friend_sitting.chairNumber);
                friends_sitting.pop();
            }
            int free_chair = free_chairs.top();
            free_chairs.pop();
            // for (int i = 0; i < chairs.size(); i++)
            // {
            //     if (chairs[i] == -1)
            //     {
            //         free_chair = i;
            //         chairs[i] = 1;
            //         break;
            //     }
            // }
            if (targetFriend == FriendArrived.FriendNumber)
                return free_chair;
            friends_sitting.push({FriendArrived.leavingTime, free_chair});
        }
        return -1;
    }
};
