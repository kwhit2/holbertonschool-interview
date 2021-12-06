#!/usr/bin/python3
""" recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript should count as
    javascript, but java should not) """
import json
import requests
from sys import argv


def count_words(subreddit, word_list):
    """ recursive function that queries the Reddit API, parses the title of
        all hot articles, and prints a sorted count of given keywords
        (case-insensitive, delimited by spaces. Javascript should count as
        javascript, but java should not) """
    url = 'https://www.reddit.com/r/{}/hot.json?limit=100'.format(subreddit)
    headers = {'User-Agent': 'Mozilla/5.0'}
    r = requests.get(url, headers=headers)
    if r.status_code != 200:
        return None
    data = r.json()
    titles = []
    for post in data.get('data').get('children'):
        titles.append(post.get('data').get('title'))
    for word in word_list:
        count = titles.count(word)
        print('{}: {}'.format(word, count))
