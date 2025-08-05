//leetcode: 355. Design Twitter

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Twitter {
    struct Tweet {
        int TweetId;
        int time;
        Tweet(int id, int t) : TweetId(id), time(t) {}
    };

    //global time 
    int time;

    //map of userId to Tweets which user has posted
    unordered_map<int, vector<Tweet>> tweets;

    // map of userId to his following
    unordered_map<int, unordered_set<int>> following;

    struct Comp {
        bool operator()(const Tweet& a, const Tweet& b) {
            return a.time > b.time;
        }
    };

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, time++));
    }

    //returning the tweetId of 10 most recent tweets done by me or my followers
    vector<int> getNewsFeed(int userId) {
        //min heap banaunga taaki 10 most recent wale store kr saku constant space(10) mai
        priority_queue<Tweet, vector<Tweet>, Comp> minHeap;

        //add my tweets
        if (tweets.find(userId) != tweets.end()) {
            for (auto tweet : tweets[userId]) {
                minHeap.push(tweet);
                if (minHeap.size() > 10) {
                    //sabse old wala pop ho jayega
                    minHeap.pop();
                }
            }
        }

        //add tweets whom i'm following
        if (following.find(userId) != following.end()) {
            auto myfollowingId = following[userId];
            for (auto followeeId : myfollowingId) {
                //kya mere following mai jo hai unhone tweet kiye hai
                if (tweets.find(followeeId) != tweets.end()) {
                    for (auto tweet : tweets[followeeId]) {
                        minHeap.push(tweet);
                        if (minHeap.size() > 10) {
                            //sabse old wala pop ho jayega
                            minHeap.pop();
                        }
                    }
                }
            }
        }

        //now i will have tweets , top 10 most recent tweets from userId and from following of UserId
        vector<int> ans;
        while (!minHeap.empty()) {
            Tweet topTweet = minHeap.top();
            minHeap.pop();
            ans.push_back(topTweet.TweetId);
        }

        //ab reverse krna pdega kyuki minHeap use kiye h toh starting mai sbse chhota time wala aayega
        //hume bade time wala pehle chahiye
        //kyuki bada time mtlb most recent one
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        if (following.find(followerId) != following.end()) {
            following[followerId].erase(followeeId);
        }
    }
};

// Main function for testing
int main() {
    Twitter* obj = new Twitter();

    // User 1 posts a tweet
    obj->postTweet(1, 5);

    // User 1's news feed should return [5]
    vector<int> feed1 = obj->getNewsFeed(1);
    cout << "User 1 feed: ";
    for (int tweet : feed1) cout << tweet << " ";
    cout << endl;

    // User 1 follows user 2
    obj->follow(1, 2);

    // User 2 posts a tweet
    obj->postTweet(2, 6);

    // User 1's news feed should return [6, 5]
    vector<int> feed2 = obj->getNewsFeed(1);
    cout << "User 1 feed after following user 2 and user 2 posts: ";
    for (int tweet : feed2) cout << tweet << " ";
    cout << endl;

    // User 1 unfollows user 2
    obj->unfollow(1, 2);

    // User 1's news feed should return [5]
    vector<int> feed3 = obj->getNewsFeed(1);
    cout << "User 1 feed after unfollowing user 2: ";
    for (int tweet : feed3) cout << tweet << " ";
    cout << endl;

    delete obj;
    return 0;
}
