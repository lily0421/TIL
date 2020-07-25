<h1 align="center">
1. FUNDAMENTALS
</h1> 
<p align="center">
  <strong>1.1 Arrow Functions</strong><br>
</p>

다음 둘은 같다
```javascript
const sayHello = (name) => "hellO" + name;
```
```javascript
function sayHello(name){
    "hello" + name;
} 중괄호 사용하지 않는 함축적 return
```
+ Argument 하나일때는 괄호 X

<p align="center">
  <strong>1.2 Template Literals</strong><br>
</p>

띄어쓰기와 + 를 기억하기 싫어요.
```javascript
const sayHello = (name) => `Hello ${name}`;
```

<p align="center">
  <strong>1.3 Object Destructuring</strong><br>
</p>

```javascript
const human ={
  name = "HanSol",
  lastNmae = "Kim",
  nationality : "KO",
  favFood: {
    breakfast: "Sang",
    lunch: "Don",
    dinner: "Sang + Don",
  }
}
```
Destructuring 
+ 해당 Object에 기반해 variable을 만듦.

```javascript
효율적이지 않은 코드
const name = human.name;
const lastName = human.lastName;
```

```javascript
효율적인 코드
const { name, lastname} = human;
```
+ {  } => object안에 있는 Property들을 가져옴
+ 알고 싶은 object는 human

```javascript
//const difName = human.nationality;
const { name, lastname, nationality: difName} = human;
console.log(name, lastname,difName);
```
+ nationality: difName => human OBJ에서 nation~라는 variable값을 가져오고 이를 difName으로 넣어주어라

```javascript
favFood의 dinner, breakfast, lunch을 얻고 싶어요
//const dinner = human.favFood.dinner;
const { favFood: {dinner, breakfast, lunch} } = human;
console.log(dinner, breakfast, lunch);
```
+ : {  } 로 OBJ의 안으로 들어가는 것

<p align="center">
  <strong>1.4 Spread Operato</strong><br>
</p>

```javascript
const days = ["Mon", "Tue"];
const other = ["Thu", "Fri"];
const allDays = days + other;
console.log(allDays); 
```
+ console.log => string으로 바꿔줌

```javascript
let allDays = [days + other];
console.log(allDays);
```
+ 하나의 item을 가진 배열을 가지고 싶어요

```javascript
const allDays = [days, other];
```
+ [Array[2], Array[2]] 출력됨

```javascript
Spread Operator 등장
const allDays = [...days, other];
```
+ ["Mon", "Tue", Array[2]] 출력됨
+ [...days, ...other]로 두 배열을 한 배열에 있도록 할 수 있음

```javascript
OBJ에서도 작동!
const ob ={
  first: "hi",
  second: "hello"
};
const ab = {
  thrid: "bye bye"
};
const two = {...ob, ...ab};
```
+ Object {first: "hi", second: "hello", thrid: "bye bye"} 출력됨

```javascript
function 에서도 작동!
const fun = {something, args} => console.log(...args)
```
<p align="center">
  <strong>1.5 Classes</strong><br>
</p>

```javascript
class Human{
  constructor(name, lastName){
    this.name = name;
    this.lastName = lastName
  }
}
```
+ this => class를 참조 하겠다

```javascript
const Hansol = new Human("Han", "sol");
```

```javascript
class Baby extends Human {
  cry(){
    console.log("I'm crying")
  }
  sayName(){
    console.log('My name is ${this.name}');
  }
}
```
+ Human에 속하는  Baby.
+ Human의 모든 것을 가짐
+ 새로운 함수 cry, sayName
+ sayName의 this는 class Baby extends Human를 의미

<p align="center">
  <strong>1.6 Array map</strong><br>
</p>

vscode 이모지 단축키
+ (윈도우 로고키) + (마침표키)

```javascript
const days = ["😀Mon", "😁Tue", "😂Wed", "🤣Thu", "😎Fri"];
```
```javascript
const smilingDays = days.map(potato => console.log(potato));
```
+ days에 있는 모든 요일에 function을 실행하겠다
+ 그 function에서 나온 값을 저장해서 새로운 배열로 만들겠다
+ potato가 배열의 각각의 값을 가지게 됨. (월, 화, 수, 목, 금)

+ 즉, map은 함수의 return값을 리턴함

```javascript
console.log(smilingDays);  
```
+ 이 경우, 리턴하는 값이 없으므로, undefinded로 결과 나옴

```javascript
const smilingDays = days.map(potato => `🎈 ${potato}`);
console.log(smilingDays);  
```
+ 이 경우, 🎈를 포함해 값 출력.
+ `🎈 ${potato}` 이 부분이 리턴하는 값
+  => (arrow Function) 은  return으 함축적으로 가짐 

```javascript
const smilingDays = days.map(day, index) => `#${index} ${day}`;
// const addNumber = (day, index) => `#${index} ${day}`;
// const smilingDays = days.map(addNumber)
console.log(smilingDays);    
```
+ 출력 ) ["#0 Mon", "#1 Tue" ...]
+ map은 여러개 argument 전달 가능
+ day = day라는 각각의 값
+ index = 현재 있는 숫자

<p align="center">
  <strong>1.7 Array filter</strong><br>
</p>

```javascript
const number = [2, 45, 56, 456, 86, 14, 745, 423, 5, 7, 8, 9, 53];  
```

```javascript
const biggerThan15 = number.filter(number => number > 15)
// const test = (number) => number <15
// const biggerThan15 = number.filter(test);
```
+  15 보다 큰 숫자를 필터
+ filter 는 map과 비슷.
> 배열의 각각 아이템에 function을 실행
> return값이 true면 해당 아이템을 넣음

+ map vs filter \
map = 배열의 모든 Argu에 function을 실행 후, 그 결과 값들로 이루어진 배열을 만듦 \
filter = 배열의 모든 요소에 function을 실행해서 true를 return하는 요소로만 이루어진 배열 만듦


```javascript
응용 예시
let posts = ["HI", "Hello", "Bye"];
posts = posts.filter(post => post !== "Bye");
console.log (posts)
```
+ posts는 filter로 정리된 bye값을 갖지 않음
+ post는 각각의 아이템들.

+ let vs const
> let은 변수에 재할당이 가능하지만,
> const는 변수 재선언, 재할당 모두 불가능