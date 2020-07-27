<p align="center">
  <strong>2. Telegram bot</strong><br>
</p>

간단하게 구축 가능 + 선톡 기능 + 여러 사용자 이용 가능
> pip install python-telegram-bot

텔레그램 봇
+ Botfather
+ /start ) 봇 생성, 관리 메뉴 나옴
+ 봇을 만들것 임 ) /new bot
+ 봇 이름 ) Inf_bot
+ user 이름. bot으로 끝나면 됨) Inf_tes_bot 
> 토큰 부여됨

```python
for i in bot.getUpdates():
    print(i.message)
```
+ 텔레그램 id값 얻기
