<h1 align="center">
5. CONTAINERS
</h1> 
<p align="center">
  <strong>5.0 Container Presenter Pattern part One</strong><br>
</p>

API verbs, functions들을 화면에 넣고 싶어요 
+ Home.js => pop~,up~,now~ 영화들 가져오고
+ TV.js => top~,pop~,airing 보여줌
+ 검색 => 영화, TV검색 넣어주기

+ 작은 어플리케이션 
클래스 컴포넌트와 스테이트사용
> 컴포넌트 만들고 마운트 되었을때 api에서 데이터를 불러오고, 그 요소들을 랜더링
+ 이번에는 다른 방법 사용
리엑트 컴포넌트 코딩 패턴 (컨테이너 프리젠터 패턴)
> 컨테이너는 data가지고, state가지고, api불러옴. \
> 모든 로직 처리 후 프리젠터는 데이터를 보여주는 역할. \  
> 프리젠터 = 스타일, 컨테이너 = 데이터

4개의 Router를 위해 컨테이너, 프리젠터들 생성
+ Routes - Detail, Home, TV 폴더 생성
+ index.js는 모든 곳에서 생성되야 함
> 컨테이너를 export하기 위함

Home 폴더 - 컨테이너 생성 ) HomeContianer.js
+ Home 폴더 - indes.js ) import HomeContianer
+ HomeContianer.js ) 상태값을 가진 모든 리엑트 컴포넌트가 될 것임
> import HomePresenter from "./HomePresenter"; 해주고 HomePresenter.js생성
+ 3가지 상태값 가질 것임 ) nowPlaying, upcoming, popular => 모두 null
+ 이때, error의 상태도 체크
+ 후에 render 하기

+ Routes에 있는 Home.js는 삭제 ) Home 폴더에 있으니!! \
계획 ) 컨테이너 먼저 만들고 api메소드 추가 후 데이터 보여주는 작업 할것임


<p align="center">
  <strong>5.1 Container Presenter Pattern part Two</strong><br>
</p>

Search폴더
+ 상호작용 필요
+ loading: false => 디폴트로 아무것도 로딩하지 않을 것임
+ searchTerm => 사용자가 단어글 가지고 검색하기를 기다림

Detail폴더
+ ID를 가지고 얻게 되는 모든 것들은 (movie, tv) 모두 result를 가질 것

<p align="center">
  <strong>5.2 Home Container </strong><br>
</p>

컨포넌트가 마운트 되었을때, state의 요소를 찾고, 끝나면 state값을 설정 \
에러 있으면 loading을 false로 변경

componentDidMount(){} => 두 가지 옵션
+ 전체 API요청 
+ 각각의 요청을 분리된 함수로 만들어서 따로 요청 가능 ) 요소가 크지 않아 여기서 사용
> getNowPlaying, getUpcoming(), getPopular()...

+ 메시지 작업 안하고 error상태값만 변경
+ async => wait를 원해요
+ await => 내가 작업을 끝낼 때 까지 다음것을 진행하지 마

<p align="center">
  <strong>5.3 TV Container </strong><br>
</p>

+ const popular = await tvApi.popular();
+ 확인 후
+ const {data: {results: popular}} = await tvApi.popular() 

<p align="center">
  <strong>5.4 Search Container </strong><br>
</p>

+ handleSubmit ) 폼에서 text를 입력하고, 엔터를 누르면 됨`
+ => searchTerm이 빈칸이 아닌걸 체크하고 그 다음에 search함수 실행
```javascript
searchByTerm = (term) => {
        const { searchTerm} = this.state;
        try{
            const movieResults = await moviesApi.search(searchTerm);
            this.showResults = await tvApi.search(searchTerm);
            consloe.log(moviesApi,this.showResults);
            this.setState({loading: true});
        }catch{
            this.setState({error: " Can't find results."});
        }finally{
            this.setState({loading: false});
        }
    }
```
+  searchTerm이 공백이 아닐때, searchTerm을 인자로 넣고 searchByTerm을 호출
+ 타이핑 후, 검색 => loading을 true로 바꾸고 싶어요
+ searchTerm: "code" \
=> compoentDidMount될때 handleSubmit을 호출 \
=> 이때, searchTerm은 비어있지 않고 code될 것 \
=> 그러면 searchByTerm호출되고, movieResults, showResults를 찾을 것임

```javascript
try{
            const movieResults = await moviesApi.search(searchTerm);
            const showResults = await tvApi.search(searchTerm);
            consloe.log(moviesApi,this.showResults);
            this.setState({loading: true});
        }
```
확인 후 바꾸기 => 최종
```javascript
 searchByTerm = (term) => {
        const { searchTerm} = this.state;
        this.setState({loading: true});
        try{
            const {data: {results: movieResults}}  = await moviesApi.search(searchTerm);
            const {data: {results: showResults}} = await tvApi.search(searchTerm);
            this.setState({movieResults, tvResult});            
        }catch{
            this.setState({error: " Can't find results."});
        }finally{
            this.setState({loading: false});
        }
    }
```

```javascript
searchTerm: "code"

componentDidMount(){
        this.handleSubmit();
    }
```
+ 시뮬레이션을 위한 함수였음 => 확인 후 삭제
+ 즉, input값으로 검색하고 리턴값 받았을 때 작도할 것

handleSubmit을 함수로 SearchPresenter에 보내야 함
+ render의 return 에 handleSubmit={this.handleSubmit} 추가


최종
+ searchPresenter에서 폼 만들고,
+ 폼 셋업하고 onSubmit호출하는데) 이는 handleSubmit을 호출하기 위함
+ handleSubmit은 searchByTerm을 호출 하고 
+ searchByTerm은 이 모든걸 작업들을 준비해 줄 것임


Detail위함! => Router.js
> movie/12로 가고 싶어요 \
> api.js => 12라는 것은 movieDetail: id라는 것에서 얻어옴 \
> 그래서 movieDetail로 갈 수 있음 
+ 이러한 방식은 movie, show둘 다 필요! => Detail폴더에서!!
```javascript
<Route path="/movie/:id" component={Detail} />
<Route path="/show/:id" component={Detail} />
```
+ Router에 추가
+ import Detail from "Routes/Detail";

<p align="center">
  <strong>5.5 Detail Container part One  </strong><br>
</p>

Header.js
+ 라우터의 위치 알고 있음
+ withRouter컴포넌트를 가지고 꾸며줬음

따라서, 해야 할 것
+ 1. /movie 인지 /show인지 알려줘야 함
> 같은 페이지, 같은 컴포넌트로 가고있음
+ 2. 어떤 숫자(id)가 있는지 알아야 함
> props는 match라는 것을 가지는데, 
이는 params와 id를 가지는 것임. \
> 리엑트 라우터가 파라미터를 각각 다른 장소들에게 줌


```javascript
async componentDidMount(){
  const { 
      match: { 
          params: { id } 
      } 
  } = this.props;
  console.log(parseInt(id));
}
```
+ match에서 history를 보고 싶어요
> history에는 goBack, go, push...할 수 있음.
+ 여기서 id를 알고싶은데, 이 id는 숫자!
> parselnt => srting을 숫자로 변환

```javascript
if(isNaN (parsedId) ){
   push("/");
}
```
+ 숫자가 아니면 /
+ 함수를 끝내고 싶어요 => return사용

<p align="center">
  <strong>5.6 Detail Container part Two</strong><br>
</p>

+ url을 가지고 옴. console.log(this.props) => path를 알기 위함
+ location: {pathname} 추가
콘솔창
```javascript
const path = "/movie/1121212"
undefined

path.includes("/movie/")
true

const something = "/show/121212";
undefined

something.includes("/movie/")
false
```

+ 생성자 사용
+ 클래스 생성 방식 알기
+ this.setState loading은 false이고 let result로 선언.
> result가 뭐가 되었든(TV,movie)덮어쓰게 될 것임.

+ result=null인 것을 만들었고
+ try => movie인지 확인해서 t면 movie를 받고, 그 다음에 요청된 데이터를 가지고 result를 덮어씀
+ TVshow로부터 요청되어진 데이터를 가지고 result를 덮어씀
+ error발생시, catch에서 처리하고 finally에서의 loading false, resultr=null일 수 도 있고, movie 아니면 tvshow일 수 도 있음
