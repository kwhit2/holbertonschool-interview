#!/usr/bin/python3
""" recursive function that queries the Reddit API, parses the title of all
    hot articles, and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces. Javascript should count as
    javascript, but java should not) """
import json
import requests
from sys import argv


# def count_words(subreddit, word_list={}, count=0, after=None):
#     headers = {'User-agent': 'i am a python program'}
#     url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
#     if after is not None:
#         url += '?after={}'.format(after)
#     response = requests.get(url, headers=headers, allow_redirects=False)
#     if response.status_code != 200:
#         return None
#     data = response.json()
#     for post in data.get('data').get('children'):
#         title = post.get('data').get('title')
#         for word in word_list:
#             if word.lower() in title.lower():
#                 count += 1
#     after = data.get('data').get('after')
#     if after is not None:
#         return count_words(subreddit, word_list, count, after)
#     print('{}: {}'.format(word, count))
#     return count

def count_words(subreddit, word_list=[], after=None, count=0):
    if count > 1 and after is None:
        return (word_list)
    elif after is None:
        sub_res = requests.get(
            'https://reddit.com/r/{}/hot.json'.format(subreddit),
            headers={'User-agent': 'test'})
        if sub_res.status_code == 200:
            hot = requests.get(
                'https://reddit.com/r/{}/hot.json'.format(subreddit),
                headers={'User-agent': 'test'})
            for word in hot.json().get('data').get('children'):
                word_list.append(word.get('data').get('title'))
            after = hot.json().get('data').get('after')
            count_words(subreddit, word_list, after, count + 1)
        else:
            return (None)
    else:
        hot = requests.get(
            'https://reddit.com/r/{}/hot.json?after={}'.format(
             subreddit, after), headers={'User-agent': 'test'})
        for word in hot.json().get('data').get('children'):
            word_list.append(word.get('data').get('title'))
        after = hot.json().get('data').get('after')
        count_words(subreddit, word_list, after, count + 1)
    print('{}: {}'.format(word, count))
    return (word_list)
