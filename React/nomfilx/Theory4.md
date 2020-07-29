<h1 align="center">
4. NETWORKING
</h1> 
<p align="center">
  <strong>4.0 Introduction to The Movie DB API</strong><br>
</p>

Q : 데이터가 어디에서 왔고, 어디에서 오는지 궁금해요 \
A : the Movie DB API에서 와요

<p align="center">
  <strong>4.1 Sexy Networking with Axios Instances</strong><br>
</p>

+ API에서 어떻게 필요한 것을 요청하는지, \
하고 있는 방식이 fetch 임

+ 중복이 많아요
+ 네트워킹, API만 다루는 파일

Api.js => 작업하기 위함
> $ yarn add axios
+ Axios는 request와 작업하기 좋음
+ Axios 장점 ) 인스턴스를 configure(설정)해 줄수 있다는 것
+ axios.create ) 인스턴스 위한 설정
+ 
  첫번째 파라미터 = api_key \
  두번째 파라미터 = language
+ api.get("tv/popular"); => 상대경로
+ api.get("/tv/popular"); => 절대경로

<p align="center">
  <strong>4.2 API Verbs part One</strong><br>
</p>

Api.js - 2개 오브젝트
+ 오브젝트
+ 모든 request + function넣을 것

> nowPlaying: () => api.get()
+ function이고 암시적 리턴 사용
+ "movei/now_playing" ) 사이트에서 찾아 가져오기

<p align="center">
  <strong>4.3 API Verbs part Two</strong><br>
</p>


movieDetail: id => api.get(`movie/${id}`)
+ id 가 필요
+ {movie_id}대신 ${id}사용함

append_to_response
+ 예고편, 관련 비디오 리스트 가져오고 싶어요

search mopvie
+ 파라미터를 쓰는지 확인
+ 빈칸(space)넣으면 작동 안됨.
+ String으로 되야 하기 때문.
> @을 입력하면 URL에서 인코딩 필요함.

+ JS에서 인코딩 URl ) 
> encodeURLComponenet(term)
+ term 값을 함수에 넘겨 값을 인코딩하고 그 물자열로 검색 함