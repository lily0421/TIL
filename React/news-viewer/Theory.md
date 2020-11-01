### 최상위 파일
- 코드 스타일 자동 정리) .prettierrc
```javascript
{
  "singleQuote": true,
  "semi": true,
  "useTabs": false,
  "tabWidth": 2,
  "trailingComma": "all",
  "printWidth": 80
}
```
- 파일 자동 불러오기 기능 활용하기 ) jsconfig.json
```javascript
{
  "compilerOtions": {
    "target": "es6"
  }
}
```

## 비동기 처리
- axios 설치
가장 많이 사용되는 JS의 HTTP클라이언트. 
특징) Promise 기반으로 특정 HTTP처리
```
yarn add axios
```
```javascript
const onClick = () => { 
  axios.get('https://jsonplaceholder.typicode.com/todos/1').then(response => {
    setData(response.data);
  })
};

const onClick = async () => {
  try {
    const response = await axios.get('https://jsonplaceholder.typicode.com/todos/1',
    );
    setData(response.data);
  }catch (e){
    console.log(e);
  }
};
```
### newsapi에서 API키 발급 받기

## 컴포넌트 설명

App ) 카테고리 상태를 useState로 관리

NewsItem ) 각 뉴스 정보 보여주는 컴포넌트
- JSON 객체의 데이터
> >내보낼 필드: title(제목), descripition(제목), url(링크), urlTolmage(뉴스 이미지)
- article이라는 객체를 props로 받아와서 사용

NewsList ) API 요청하고 뉴스 데이터가 들어 있는 배열을 컴포넌트 배열로 변환하여 렌더링 해주는 컴포넌트
- API를 요청하게 될 것
- 그 전) 가짜 데이터 => sampleArticle객체에 미리 예시 데이터 넣은 후 보이게 함
- loading 상태관리
요청이 대기 중 loading : true, 요청이 끝나면 loading: false

Categories ) 뉴스 카테고리 선택 기능 구현
> >business, science, entertainment, sports, health, technology

### 

APU 주소 형태
- 전체 뉴스 불러오기
- 특정 카테고리 뉴스 불러오기 
>  > business, entertainmnet, health, science, sports, technology...
생략시 모든 카테고리 뉴스 불러옴

UI
- styled-components사용
yarn add styled-components 

a 태그
```javascript
<a href={url} target="_black" rel="noopener noreferrer">{title}</a>
```
noopener : 하이퍼링크를 따라 연결되는 어떠한 브라우징 컨텍스트(browsing context)도 오프너(opener)여서는 안 됨을 나타냄.
noreferrer : 사용자가 하이퍼링크를 클릭할 때 브라우저가 HTTP 리퍼러 헤더(referer header)를 전송해서는 안 됨을 나타냄.

useEffect 사용시 주의점
- 컴포넌트 처음 렌더링 될 때 async붙이면 안됨
=> useEffect는 반환해야 하는 값은 뒷정리 함수기 때문!
- async사용하고 싶어요 => async키워드가 붙은 또다른 함수를 만들어서 사용해요.

NewsList.js
```javascript
const query = category === 'all' ? '' : `&category=${category}`;
const response = await axios.get(`https://newsapi.org/v2/top-headlines?country=kr${query}&apiKey=77cf3acc777344c79bb862bbc3bd5df6`,);
```
category의 값에 따라서 요청할 주소가 동적으로 바뀜
all => 공백, all아니라면 => `&category=카테고리` 형태의 문자열 
useEffect의 두번째 파라미터에 설정하는 배열에는 카테고리 값이 바뀔 때마다 뉴스를 새로 불러야 하기 때문에 category를 넣어줌
> 함수형 컴포넌트기 때문에, useEffect로 처음 렌더링 될때, category값이 바뀔 때 요청하도록 설정

IF 클래스형 컴포넌트 ?
componentDidMount 와 componentDidUpdate에서 요청 시작 하도록 설정.

라우터 설치 및 적용
₩₩₩
yarn add react-router-dom
₩₩₩
index.js에서 라우터 적용

```javascript
const App = () => {
  const[category, setCategory]=useState('all');
  const onSelect = useCallback(category => setCategory(category),[]);

  return (
  <>
    <Categories category={category} onSelect={onSelect}/>
    <NewsList category={category}/>
  </>
  );
};
```

```javascript
const App = () => {
  return  <Route path="/:category?" component={NewsPage} />;
};
```
path="/:category?" => category값이 선택적. 있을수도 있고 없을수도 있다.
category URL 파라미터가 없다면 전체 카테고리를 선택한 것으로 간주함

### NavLink
Category 컴포넌트
- to => "/카테고리이름"
- 전체보기 => 예외적으로 "/"
to값이 "/"를 바라본다면 exact값을 true로 설정. 설정하지 ㅇ낳으면 다른 카테고리가 선택됬을 때도 전체보기 링크에 active스타일이 적용되는 오류 발생


### usePromise 커스텀 Hook
코드 간결 But! API종류 많아지면 요청을 위한 상태관리 하는 것이 번거로워질 수 있음.
=> 이는, 리덕스와 리덕스 미들웨어로 요청 상태를 관리할 수 있음.