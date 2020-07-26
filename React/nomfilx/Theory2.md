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

프로젝트 시작 - Router.js
> import React, { HashRouter } from "react"; \
> import {HashRouter as Router} from "react-router-dom"; ) Router 중에 HashRouter사용 

```javascript
export default () => {
    <Router>
        
    </Router>
}
```
+ Router생성

```javascript
export default () => {
    <Router>
        <Route path="/" exact component={Home} /> 
    </Router>
}
```
+ path는 어느 URL에서 해당 Route를 render할지 알려줌
+ Component ) 누군가 이 Route에 왔을 때 어떤 컴포넌트가 보여질 건지에 대함
> import Home from "Routes/Home"; 필요


App.js
```javascript
class App extends Component {
  render(){
    return <><Router /></>;
  }  
}
```
+ React에서는 한개만 사용가능 => 그래서! Fragments 사용
> Fragments => 원하는 만큼 컴포넌트를 return할 수 있게 해줌 \
> import Router from "Components/Router"; 필요

Router.js
+ path 추가

