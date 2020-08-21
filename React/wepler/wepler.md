- 개발환경 
yarn global add npx
npm i npx -g
npx create-react-app wepler_f ) 소문자 폴더이름

- git clone하고 할 것 
+  react-router-dom 생성
+ CSS 초기화
+ 폰트 어썸 

- react-router-dom 생성
npm install react-router-dom --save

-Router활용
src 폴더의 index.js 파일에 Routes.js파일을 생성 후
Routes컴포넌트를 만들어 연결

- 스타일 컴포넌트
yarn add styled-components

- CSS 초기화
styled-reset) css를 초기화 해서 0의 상태에서 시작하게 하는 것
yarn add styled-reset

- 폰트 어썸
아이콘 사용
yarn add react-icons
혹은
npm install react-icons --save
+ https://react-icons.netlify.com/#/
=>여기서 아이콘 찾기
추가)
npm install flat-color-icons

- 캘린더
yarn add react-big-calendar moment date-arithmetic
npm install --save @fullcalendar/react @fullcalendar/daygrid

- material사용
https://material-ui.com/
+ npm i @material-ui/core
+ yarn add @material-ui/core
+ 폰트 - 추가하기
<head>
  <link
    rel="stylesheet"
    href="https://fonts.googleapis.com/css?family=Roboto:300,400,500,700&display=swap"
  />
</head>



