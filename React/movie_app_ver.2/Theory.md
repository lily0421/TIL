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

