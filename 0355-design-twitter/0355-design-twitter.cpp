class Twitter {
    // N = total number of users
    // T = max tweets per user (10)
    // F = number of followees of a user

    // Tracks the global timestamp of tweets
    int timestamp = 0;

public:
    // key: userId | value: list of all tweets {time, tweetId}
    // Space: O(N * T) = O(N * 10) = O(N)
    unordered_map <int, vector<pair<int, int>>> tweets;

    // key: userId | value: set of all followee Ids
    // Space: O(N^2) worst, every user can follow all
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {}

    void postTweet(int userId, int tweetId) { 
        // Time: O(1) amortized, push tweet in the vector
        tweets[userId].push_back({timestamp, tweetId});
        timestamp++;

        // Time: O(T) = O(10) = O(1)
        // If more than 10 tweets, remove oldest tweet
        if (tweets[userId].size() > 10) {
            tweets[userId].erase(tweets[userId].begin());
        }

        // Overall Time: O(1) amortized
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<tuple<int, int, int>> pq; // <time, personId, tweetIndex>
        
        // Add the user's latest tweet
        // Time: O(1) because the heap is initially empty
        int tweetIdx = -1;
        if (!tweets[userId].empty()) {
            tweetIdx = tweets[userId].size() - 1;
        }
        if (tweetIdx >= 0) {
            auto [time, twId] = tweets[userId][tweetIdx];
            pq.push({time, userId, tweetIdx}); // O(1)
        }

        // Add the latest tweet of each followee
        // Time: O(F * log(F + 1)) = O(F * log(F))
        for (auto followeeId: follows[userId]) { // O(F)
            int twIdx = -1;
            if (!tweets[followeeId].empty()) {
                twIdx = tweets[followeeId].size() - 1;
            }
            if (twIdx >= 0) {
                auto [time, twId] = tweets[followeeId][twIdx];
                pq.push({time, followeeId, twIdx}); // O(log F + 1)
            }
        }

        if (pq.empty())
            return feed;

        // max F + 1 values in the heap
        // on each turn, one tweet is extracted and next one added
        // means, max 10 iterations
        // Time = O(10 * log(F + 1)) = O(log(F + 1))
        while (!pq.empty() && feed.size() < 10) { // O(10) = O(1)
            auto [time, personId, index] = pq.top();
            auto [t, tweetId] = tweets[personId][index];
            pq.pop();

            feed.push_back(tweetId);

            index--;
            if (index >= 0) {
                auto [newtime, newtweetId] = tweets[personId][index];
                pq.push({newtime, personId, index}); // O(log(F + 1))
            }
        }

        // Overall Time: 
        // = O(F * log(F + 1) + 10 * log(F + 1))
        // = O((F + 1) * log(F + 1))
        // = O(F * log(F+1))

        // Simplified: O(F * log(F)), for F > 0
        
        // Auxiliary Space: O(F + 1)
        // because priority queue is holding max F + 1 values

        return feed;
    }

    void follow(int followerId, int followeeId) {
        // Time: Average O(1)
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // Time: Average O(1)
        follows[followerId].erase(followeeId);
    }
};