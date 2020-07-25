<h1 align="center">
2. PROJECT SETUP
</h1> 
<p align="center">
  <strong>2.0 Setting Up the Project</strong><br>
</p>

create-react-app이용 (cmd이용)
+ yarn global add create-react-app ) 자주사용 아님
> create-react-app
+ npx ) npm처럼 모듈을 사용할 수 있게 하는 모듈
> yarn global add npx
> npm i npx -g
> npx create-react-app <폴더이름>
+ npx는 최신버전의 c-r-a을 다운 받아 실행하는데 끝나면 컴퓨터에서 삭제

삭제 파일
+ App.css
+ App.test.js
+ logo.svg
+ serviceWoker.js

추가 파일 
+ src폴더 밖 .env
+ NODE_PATH=src 추가
+ 이렇게 파일 셋업!

nomfil폴더에 prop-types설치
+ yarn add prop-types