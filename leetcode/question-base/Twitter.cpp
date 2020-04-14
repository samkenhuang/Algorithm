#include "../util/stl.h"

class Twitter {
private:
    unordered_map<int, set<int>> follows; // <1, {5, 6}> -> 1关注5,6
    vector<pair<int, int>> feeds;
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        feeds.push_back({userId, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        // 获得当前用户关注列表
        unordered_map<int, set<int>>::iterator find = follows.find(userId);
        set<int> followList;
        if (find != follows.end()) {
            followList = find->second; 
        }
        followList.insert(userId);
        // 根据关注表在推文序列中找出最近的10条推文
        int count = 10;
        vector<int> tweets;
        for (int i = feeds.size() - 1; i >= 0; i--) {
            set<int>::iterator followListIt = followList.find(feeds[i].first);
            if (followListIt != followList.end()) {
                tweets.push_back(feeds[i].second);
                if (tweets.size() >= 10) break;
            }
        }
        
        return tweets;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        unordered_map<int, set<int>>::iterator find = follows.find(followerId);
        set<int> followList;
        if (find != follows.end()) {
            followList = find->second;
            followList.insert(followeeId);   
        } else {
            followList.insert(followeeId);
        }
        follows[followerId] = followList;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        unordered_map<int, set<int>>::iterator find = follows.find(followerId);
        if (find != follows.end()) {
            set<int> followList = find->second;
            followList.erase(followeeId);
            follows[followerId] = followList;
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main() {
    Twitter* obj = new Twitter();

    // 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
    obj->postTweet(1, 5);
    // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    obj->getNewsFeed(1); // {5}
    // 用户1关注了用户2.
    obj->follow(1, 2); obj->follow(1, 3); obj->unfollow(1, 3);
    // 用户2发送了一个新推文 (推文id = 6).
    obj->postTweet(2, 6);
    // 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
    // 推文id6应当在推文id5之前，因为它是在5之后发送的.
    obj->getNewsFeed(1); // {6, 5}
    // 用户1取消关注了用户2.
    obj->unfollow(1, 2);
    // 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
    // 因为用户1已经不再关注用户2.
    obj->getNewsFeed(1); // {5}

}