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

