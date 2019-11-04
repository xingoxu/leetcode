
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

struct Tweet
{
  int userId;
  int tweetId;
  Tweet(int uId, int tId) : userId(uId), tweetId(tId) {}
};

class Twitter
{
  list<Tweet> timeline;
  unordered_map<int, unordered_map<int, bool>> followTable;

public:
  /** Initialize your data structure here. */
  Twitter()
  {
  }

  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId)
  {
    followTable[userId][userId] = true;
    timeline.push_front(Tweet(userId, tweetId));
  }

  /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
  vector<int> getNewsFeed(int userId)
  {
    vector<int> ret(10);
    int count = 0;
    for (auto &tweet : timeline)
    {
      if (followTable.find(userId) != followTable.end() && followTable[userId][tweet.userId])
      {
        ret[count] = (tweet.tweetId);
        ++count;
      }
      if (count >= 10)
        break;
    }
    ret.resize(count);
    return ret;
  }

  /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
  void follow(int followerId, int followeeId)
  {
    followTable[followerId][followerId] = true;
    followTable[followerId][followeeId] = true;
  }

  /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
  void unfollow(int followerId, int followeeId)
  {
    if(followerId != followeeId)
      followTable[followerId][followeeId] = false;
  }
};

int main()
{
  Twitter *twitter = new Twitter();
  // User 1 posts a new tweet (id = 5).
  twitter->postTweet(1, 5);
  twitter->postTweet(1,3);
  twitter->postTweet(1,101);
  twitter->postTweet(1,13);
  twitter->postTweet(1,10);
  twitter->postTweet(1,2);
  twitter->postTweet(1,94);
  twitter->postTweet(1,505);
  twitter->postTweet(1,333);
  twitter->postTweet(1,22);
  twitter->postTweet(1,11);

  // User 1's news feed should return a list with 1 tweet id -> [5].

  auto result = twitter->getNewsFeed(1);
  for (auto &x : result)
    cout << x << ' ';
  cout << endl;
}
