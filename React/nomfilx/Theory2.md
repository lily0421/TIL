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

시작
+ yarn start

<p align="center">
  <strong>2.1 React Router Part One </strong><br>
</p>

README.md 작성
+ 계획 작성
- [ ] Home 영화가 보여짐
- [ ] TV Shows
- [ ] Search TV쇼나 영화를 찾을 수 있음
- [ ] Detail 클릭하면 디테일 나옴

Components 폴더 생성 - App.js넣기
+ index.js 
> import App from 'Components/App';
+ 이때, env에서 기본적으로 src파일을 보게 만들어 줌
+ 즉, src폴더 - (env때문) - Components폴더 - App찾음

Route 폴더 생성 - 스크린 보여줌
+ Home.js, Tv.js, Search.js, Detail.js
+ export default () => "~";

React App에게 Home에서 시작하는 것 알려주기
> yarn add react-router-dom

