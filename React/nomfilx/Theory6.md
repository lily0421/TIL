<h1 align="center">
6. PRESENTERS
</h1> 
<p align="center">
  <strong>6.0 Presenter Structure</strong><br>
</p>

```javascript
import React from "react";
import PropTypes from "prop-types";
import styled from "styled-components";
```
+ protp-types, styled들을 import하기) 모든 Presenter

<p align="center">
  <strong>6.1 HomePresenter and Section Components </strong><br>
</p>

<p align="center">
  <strong>6.2 TVPresenter and Loader Components </strong><br>
</p>

TVPresenter.js
+ const Container 추가
+ const TVPresenter 의 null값을 loading 확인
> loading ? null  
+ topRated가 존재하면, 이것이 0보다 클때
+ component Section 을 rendering하기 (이때, 대소문자 구분 하기)
> 에러뜨면 Section.js에서 export잘 되었는지 확인하기
+  <Container> 안에 추가
```javascript
{nowPlaying && nowPlaying.length > 0 && (
  <Section title="Now Playing">
    {nowPlaying.map(movie => (
    <span key={movie.id}>{movie.title}</span>
    ))}
  </Section>
)}
```
+ popluer, airingToday 추가

```javascript
const Container = styled.div`
  padding: 0px 10px;
`;
```
+ const Container에 패딩 추가

+ 문제가 있어요! => 카테고리 클릿기 비워졌다가 로딩되요
+ loader를 빌드해요!


Loader.js
+ 이모지는 span으로 감싸져야 하고, image role이 존재해야 하며, 접근하기 쉬워야 함.
+ WHY? 
+ 시각 장애인들에게 screen reader라는 것이 존재하는데, screen을 읽게 하기 위함

기타
+ grid가 flexbox보다 나음