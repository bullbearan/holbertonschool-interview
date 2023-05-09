#!/usr/bin/python3
"This is a line of text"
from requests import get


def count_words(subreddit, word_list, count={}, after=""):
    "This is a line of text"
    if len(count) < 1:
        for word in word_list:
            count[word] = 0

    if after is None:
        c = {}
        for key, value in count.items():
            if key.lower() in c: c[key.lower()] += value
            else: c[key.lower()] = value
        word_list = [[key, value] for key, value in c.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for word_count in word_list:
            if word_count[1]:
                print("{}: {}".format(word_count[0].lower(), word_count[1]))
        return None

    response = get(
        "https://api.reddit.com/r/{}/hot".format(subreddit),
        headers={"User-Agent": "random"},
        params={"after": after},
        allow_redirects=False,
    )

    if response.status_code != 200:
        return None

    after = response.json().get("data").get("after")
    children = response.json().get("data").get("children")
    for child in children:
        title = child.get("data").get("title")
        languages = [language.lower() for language in title.split(" ")]
        for word in word_list:
            count[word] += languages.count(word.lower())

    count_words(subreddit, word_list, count, after)
