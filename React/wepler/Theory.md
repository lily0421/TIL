Router 폴더 = 
+ import Home from "Routes/Home";
+ home.js - home폴더 및 index.js
+ C~ 화면에 보이는거 제외한 것
+ P~ 화면에 보이는것

public 폴더 
+ index.html이 존재함
> <div id="root"></div>
+ react에서 컴포넌트들을 만듦 => div안에 들어가도록 약속함
+ src폴더 안에 있는 파일들이 div 사이에 들어감
+ 대부분의 파일 = src폴더 안에 파일 생성!

index.js
+ document.getElementById('root')
+ index.html의 root와 동일한 root임

+ <App />
+ 리액트를 통해 사용하는 정의 태그. 즉, 컴포넌트
+ 이 컴포넌트의 실제 구현은 import App을 통해서 from './App';
+ 즉, from뒤에 파일을 적는데 이 파일은 App.js를 의미

App.js
+ 실제 태그 구성
+ <div className="App"> ~ </div>
+ 따라서, 개발시 이부분을 수정하면 됨
> create-react-app이 우리한테 구축해 놓은 환경에 의해서 App.js파일을 수정할 때 마다, 자동으로 웹브라우저를 리로드 해줌

리액트는 반드시!
+ 하나의 태그 안쪽에 나머지 태그들이 있어야 함

