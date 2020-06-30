Theory
======

Hello World
------------
JS 파일은 마지막에 추가\
js에서 alert로 경고 메시지\
conslo.log로 콘솔에서 보이기\
즉, HTML, CSS에 JS => 모든 웹 브라우저에는 JS가 있음\
consol.log = print

Variable
------------
변수를 만들고싶어요\
방식)생성-초기화-사용
<pre>
<code>
let a = 221;
let b = a - 5;  //변수 초기화시 let사용
a = 4;  // a가 4로 업데이트
console.log(b, a);
=> 216 4
</code>
</pre>
let, const, var
---------------
const => 상수 = 안정적으로 변하지 않음\
따라서 a = 4는 에러

let은 변수가 바뀌는 것을 허락 \
var는 variable => let과 같은 역할이지만 많이 쓰지 않음.

Data Types
-----------
// => 한줄 주석
/**/ => 여러줄 주석

아직까지는 const를 기본적으로 사용하자!\
"565564" => 텍스트\
Boolean => True=1, False=0

Organizing Data
---------------
## array
camel case => 변수명을 소문자로 시작, 스페이스 대신 다음 문자의 첫 글자를 대문자 \
array => 0부터 셈 시작.

## object
각 value에 이름 줄 수 있음\
name은 변수므로 "name"으로 적지 않음\
gender만 출력하고 싶어요
<pre>
<code>
console.log(hanInfo.gender);
</code>
</pre>
const hanInfo 라고 했지만 hanInfo 자체는 바꿀 수 없고, 내용은 바꿀 수 있다.
ex) hanInfo = true\
object를 array에 넣을 수 있다.

##### DB에서 가져온 리스트 데이터 = Array
##### 기억할것 : 콤마, string에서는 앞뒤 따옴표
