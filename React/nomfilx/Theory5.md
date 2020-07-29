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

+ Routes에 있는 Home.js는 삭제 ) Home 폴더에 있으니!!
계획 ) 컨테이너 먼저 만들고 api메소드 추가 후 데이터 보여주는 작업 할것임