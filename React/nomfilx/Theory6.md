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

<p align="center">
  <strong>6.3 SearchPresenter Component  </strong><br>
</p>

SearchPresenter.js
+ container스타일 만들어줌
+ form도 만들어줌 ) submit이벤트를 차단함
+ value를 가져야 함 => input을 제어할 수 있음
+ search movies 혹은 TV shows는 value를 입력에 연결하려 함
+ => value를 추적해야 할 필요가 있음
+ 엔터의 기본 값 = submit

updateTerm
> searchPresenter.js
+ const SearchPresenter에 updateTerm추가
+ updateTerm: PropTypes.func.isRequired
+ Input에 onChange={updateTerm} 추가
updateTerm 은 event로 가야함
> searchContiner.js
+  updateTerm = (event) => {}

updateTerm = (event) => {}
+ const {target} = event;
+ target은 value를 갖음

```javascript
updateTerm = (event) => {
  const {
    target: { value }
    } = event;
  this.setState({
    searchTerm: value
  });
}
```
+ search화면에서 입력 후 엔터 가능

loading
> searchPresenter.js
+ import Loader from "Components/Loader";
+ import Section from "Components/Section";
+ loader는 loading이 멈췄을때, movieResults로 가고
+ length의 길이가 0이면 sectinTitle로 감
> 똑같이 showReseult와 TVResult에 적용
