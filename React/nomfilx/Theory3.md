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



