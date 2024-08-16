import requests
from bs4 import BeautifulSoup
import json
import csv
import tweepy

# Function to fetch data from a website
def fetch_data(url):
    response = requests.get(url)
    if response.status_code == 200:
        return response.text
    else:
        return None

# Function to scrape news articles
def scrape_news_articles(url, article_selector, title_selector, summary_selector, date_selector):
    html_content = fetch_data(url)
    if html_content:
        soup = BeautifulSoup(html_content, 'html.parser')
        articles = soup.select(article_selector)
        news_data = []
        for article in articles:
            title = article.select_one(title_selector).get_text(strip=True)
            summary = article.select_one(summary_selector).get_text(strip=True)
            date = article.select_one(date_selector).get_text(strip=True)
            news_data.append({
                'title': title,
                'summary': summary,
                'date': date,
                'source': url
            })
        return news_data
    return []

# Function to fetch tweets
def fetch_tweets(api_key, api_secret_key, access_token, access_token_secret, query, count=10):
    auth = tweepy.OAuthHandler(api_key, api_secret_key)
    auth.set_access_token(access_token, access_token_secret)
    api = tweepy.API(auth)
    tweets = api.search_tweets(q=query, count=count)
    tweet_data = []
    for tweet in tweets:
        tweet_data.append({
            'text': tweet.text,
            'user': tweet.user.screen_name,
            'date': tweet.created_at
        })
    return tweet_data

# Example usage
news_urls = [
    {
        'url': 'https://www.thehindu.com/news/national/education/',
        'article_selector': '.story-card-news',
        'title_selector': '.story-card-news h2 a',
        'summary_selector': '.story-card-news p',
        'date_selector': '.story-card-news .dateline'
    }
    # Add more sources as needed
]

all_news_data = []
for source in news_urls:
    news_data = scrape_news_articles(
        source['url'],
        source['article_selector'],
        source['title_selector'],
        source['summary_selector'],
        source['date_selector']
    )
    all_news_data.extend(news_data)

# Save news data to JSON
with open('news_data.json', 'w') as f:
    json.dump(all_news_data, f, indent=4)

# Fetch tweets
api_key = 'Ii30f7L80jH72y9iMxwKyyLX7'
api_secret_key = 'bcaAneBnqtMkjIUWAFXENfvxWLlRLW1iIENVygdBycWQz552BF'
access_token = '1716510315263983617-Cv1qWyncXCDl9MJ9iZ3Ysqil3rlqgu'
access_token_secret = 'aNoxzjCsMwvOaRsB1kegjdUxWsAA7gtHRkHvcWu1b2oG1'
bearer = 'AAAAAAAAAAAAAAAAAAAAAGF4uAEAAAAAXT80EzoyBvhETkdanMT2ylldmOI%3DTo00FpfKEq654EQtX8Tm8K7UkzsvcqEPgSYeohBWzEANhyihOu'
# tweets = fetch_tweets(api_key, api_secret_key, access_token, access_token_secret, 'New Education Policy India', count=10)

# Save tweets to JSON
# with open('tweets.json', 'w') as f:
#     json.dump(tweets, f, indent=4)
def fetch_tweets_v2(bearer_token, query, max_results=10):
    url = f"https://api.twitter.com/2/tweets/search/recent?query={query}&max_results={max_results}"
    headers = {"Authorization": f"Bearer {bearer_token}"}
    response = requests.get(url, headers=headers)
    if response.status_code == 200:
        return response.json()["data"]
    else:
        print(f"Error: {response.status_code}")
        return None
# Example usage
tweets_v2 = fetch_tweets_v2("AAAAAAAAAAAAAAAAAAAAAGF4uAEAAAAALQWAQxwwcXiipFER0VMk3a00QyE%3DCebjAsY1uTZpfMZVpwXyRHqVQAK7tINTtyHp4VpnYYAOvGSWgv", "New Education Policy India", max_results=10)
print(tweets_v2)
