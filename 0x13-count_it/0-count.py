#!/usr/bin/python3
""" recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript should count as
    javascript, but java should not) """
import json
import requests
from sys import argv


# * word causing problems
def count_words(subreddit, word_list, count=0):
    url = 'https://www.reddit.com/r/{}/hot.json?limit=100'.format(subreddit)
    header = {'User-Agent': 'test'}
    response = requests.get(url, headers=header, allow_redirects=False)
    if response.status_code != 200:
        return 0
    data = response.json()
    for post in data.get('data').get('children'):
        count += post.get('data').get('title').lower().split().count(word)
    if data.get('data').get('after'):
        count_words(subreddit, word_list, count)
    return count

# * Gives output but all count is 0
# def count_words(subreddit, word_list):
#     url = 'https://www.reddit.com/r/{}/hot.json?limit=100'.format(subreddit)
#     headers = {'User-Agent': 'test'}
#     r = requests.get(url, headers=headers)
#     if r.status_code != 200:
#         return None
#     data = r.json()
#     titles = []
#     for post in data.get('data').get('children'):
#         titles.append(post.get('data').get('title'))
#     for word in word_list:
#         count = titles.count(word)
#         print('{}: {}'.format(word, count))
