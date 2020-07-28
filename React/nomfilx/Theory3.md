<h1 align="center">
3. STYLES
</h1> 
<p align="center">
  <strong>3.0 CSS in React part One</strong><br>
</p>

<p align="center">
  원리<br>
</p>
Components - styles.css
+ .nav 
+ Header.js > header className=".nav"
+ index.js > import "styles.css";
+ js파일과 css파일은 분리!

Components - Header - Header.js, index.js
+ index.js ) import Header from "./Header";
+ App.js ) import Header from "Components/Header";

<p align="center">
  최종<br>
</p>

Components 
+ Header - Header.css, Header.js, index.js 
> Header.js ) import "./Header.css"; <header classNmae="nav">  \
> Header.css ) .nav ul
+ App.js, Router.js
Routes
+ index.js
+ setupTests.js
.env , package.json, yarn.lock

<p align="center">
  <strong>3.1 CSS in React part Two</strong><br>
</p>

css ) local
+ .navList 모듈 사용시,
> .nav-list는 오류!
+ Header.module.css
+ Header.js 
> import styles from './Header.css'; \
> <ul className={styles.navList}>
Elements 에서 확인
+ className + 임의 생성
+ 다른 파일에서도 반복해서 사용 가능
+ 즉, className 을 기억해야 함


<p align="center">
  <strong>3.2 CSS in React part Three</strong><br>
</p>

Components - App.js, Header.js, Router.js

style 컴포넌트 생성
> yarn add styled-components
Header.js
> import styled from 'styled-components'

JS와 CSS가 같이 있어요
```javascript
const List = styled.ul`
    display:flex;
    &:hover{
        background-color: blue;
    }
`;
<ul></ul> => <List></List>
```
링크를 다른 방식으로 하고 싶어요.
+ React Router에서 주어진 Link사용. 
> import {Link} from "react-router-dom"
+ Link는 해당 페이지가 어플리케이션에 있으면 그 곳으로 브라우져한 방식으로 안감. \ JS방식으로 가게 해줌

+ Link에 스타일 추가
> const SLink = styled(Link)``;
+ 이때 Link이름 중복 안됨
```javascript
<SLink to="/">Movies</SLink>
```
에러 발생! - Router 밖에서 사용불가
+ router.js ) import Header from "Components/Header";
```javascript  
<Router>
  <> 
    <Header />
    <Switch>
    </Switch>
  </>
</Router>
```
+ Router는 하나의 Child만 render하기 때문

<p align="center">
  <strong>3.3 GlobalStyles and Header</strong><br>
</p>

Global 스타일 선호
+ 해당 사이트의 폰트 설정, SC설치 등 하기 위함
> yarn add styled-reset
+ Components - GlobalStyles.js추가

GlobalStyles.js
```javascript
const globalStyles = createGlobalStyle`
    ${reset};
    a{ 모든 링크        
    }
    *{ 모든 element        
    }
    body{        
    }
`;
```

App.js
> import GlobalStyles from "Components/GlobalStyles"; \ 
> <Router />  <GlobalStyles />

+ body 태그가 적용한 CSS들을 가지고 있음

