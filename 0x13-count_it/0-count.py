#!/usr/bin/python3
""" recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript should count as
    javascript, but java should not) """
import json
import requests
from sys import argv


def count_words(subreddit, word_list={}, count=0, after=None):
    """ recursive function that queries the Reddit API, parses the title of all
        hot articles, and prints a sorted count of given keywords
        (case-insensitive, delimited by spaces. Javascript should count as
        javascript, but java should not) """
    headers = {'User-agent': 'i am a python program'}
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    if after is not None:
        url += '?after={}'.format(after)
    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code != 200:
        return None
    data = response.json()
    for post in data.get('data').get('children'):
        title = post.get('data').get('title')
        for word in word_list:
            if word.lower() in title.lower():
                count += 1
    after = data.get('data').get('after')
    if after is not None:
        return count_words(subreddit, word_list, count, after)
    print('{}: {}'.format(word, count))
    return count
