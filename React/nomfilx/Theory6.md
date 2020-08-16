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

<p align="center">
  <strong>6.4 Message Component  </strong><br>
</p>

+ error text, not fonund text

Components - Error.js
+ import
```javascript
import React from "react";
import PropTypes from "prop-types";
import styled from "styled-components";
```
+ const
```javascript
const Container = styled.div``;
const Text = styled.div``;
const Error = () =>
```
+ 마지막
```javascript
export default Error;
```
+ 빼먹지 말기
```javascript
Error.PropTypes = {
    text: PropTypes.string.isRequired
}
```

HomeContainer.js
+ try 에 throw Error(); 해주고 주변에 어떻게 보여지는지 보기위해
+ HomePresenter.js로 가서 </Container> 윗줄에 추가
```javascript
{error && <Error text={errer} />}
```
+ 이때 error는 null아니면 text를 줌

SearchPresenter.js
+ tvResults가, movieResults의 길이가 0과 같으면message를 제공


<p align="center">
  <strong>6.5 Poster Component part One </strong><br>
</p>

poster => 복잡함
+ 우리의 user가 어디있든 보내야 함

const Poster = () => ();
+ Poster은 일단 imageUrl, 이름, rating, year을 가지고 있음.
+ 여기에 star도 원하면 추가
+ ({id, imageUrl, title, rating, year })
+ (); 뒤에 콜론 반드시

Poster.propTypes = {}
+ id 필요 ) user에게 ID propTypes 혹은 /를 보내야 하기 때문
+ propTypes => 대문자 없음에 주의

const Container
+ poster를 위해 필요함

const Image
+ 백그라운드에 올라갈 것임

imageContainer를 만드는 이유?
+ 모든 poster는 image를 가지고 있고,
+ image container를 가짐
=>  image container를 만들어줘야 함

+ </span>{" "} => rating 숫자가 들어감 ex. 6.5
+ <imageContainer></imageContainer> => title과 yaer이 필요

우리가 필요한 것
+ movie 혹은 TVShow인데 => isMovie추가
+ isMovie의 default값은 false

+ import { Link } from "react-router-dom";하고
+ <Link to={isMovie ? `/movie/${id}` : `/show/${id}`}> </Link>안에 다 담기

HomePresenter.js
+ import Poster from "../../Components/Poster";
+ <span key={movie.id}>{movie.title}</span>을 <Poster />로 바꿔주기

<p align="center">
  <strong>6.6 Rendering Poster Component </strong><br>
</p>

HomePresenter.js
```javascript
<Poster
  key={movie.id}
  id={movie.id}
  imageUrl={movie.poster_path}
  title={movie.original_title}
  rating={movie.vote_average}
  year={movie.release_date.substring(0, 4)}
  isMovie={true}
/>
```
+ release_date => 2018-10-03형식인데 우리는 2018만 얻고 싶어요
+ substring(0,4)로 년도만 잘라요

TV에도 필요한것 보기
+ Network에 가서 찾아보니 동일함 + 변동된것 존재하니 movie와 다르게 해줌

SearchPresenter.js
+ import해주고
> import Poster from "../../Components/Poster";





