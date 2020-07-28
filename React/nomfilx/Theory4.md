<h1 align="center">
4. NETWORKING
</h1> 
<p align="center">
  <strong>4.0 Introduction to The Movie DB API</strong><br>
</p>

Q : 데이터가 어디에서 왔고, 어디에서 오는지 궁금해요
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
  첫번째 파라미터 = api_key
  두번째 파라미터 = language
+ api.get("tv/popular"); => 상대경로
+ api.get("/tv/popular"); => 절대경로

