<h1 align="center">
Movie crawling
</h1> 
<p align="center">
  <strong>Python</strong><br>
</p>
<p align="center">
  <strong>1. web_crawling</strong><br>
</p>

+ url => 상영시간표

```python
soup.select_one('body > div > div.sect-showtimes > ul > li:nth-child(1) > div > div.info-movie > a > strong')
```
+ 하나의 요소만 가져옴

```python
soup.select('div.info-movie')
```
+ class로 묶여 있는 영화 제목 전부 select

```python
i.select_one('a > strong').text.strip()
```
+ a 태그 안에 strong에는 영화 제목이 있음
+ .text로 글자만
+ .strip()로 공백 제거

<p align="center">
  <strong>2. Telegram bot</strong><br>
</p>

간단하게 구축 가능 + 선톡 기능 + 여러 사용자 이용 가능
> pip install python-telegram-bot

<p align="center">
  <strong>3. 스케쥴러 만들기</strong><br>
</p>

> pip install apscheduler
