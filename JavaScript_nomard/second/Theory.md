Theory
======

JS DOM Functions
----------------
HTML의 document는 JS가 됨\
document는 점을 가짐\
DOM = Document Object Module\
JS는 html에 있는 모든 요소를 가지고 오는데, 이를 객체로 바꿀 것임

Modifying the DOM with JS
--------------------------
document에 있는 것은 객체가 될 것임. 모든 htmld은 객체가 될것!\
    ex) .log .error .name...

JS로 HTML을 바꿀 수 있음
<pre>
<code>
title.style.color="red"; 
</code>
</pre>

css선택자와 비슷
<pre>
<code>
const title = document.querySelector("#title");
</code>
</pre>

id로 찾고 싶으면 "#title", class로 찾고 싶으면 ".title"

Events and event handlers
-------------------------
JS는 이벤트를 위해 만들어졌다\
이벤트 => 웹사이트에서 발생하는 것들\
    ex. click, resize, submit, input, change, load

이벤트를 받기 기다림\
window.addEventListener("resize"); 


event listener를 window에 추가하려고 하면, 우리가 이벤트에서 다룰 함수를 적어야 함
<pre><code>
window.addEventListener("resize", handleResize);
</code>
</pre>

handleResize 와 handleResize() 의 차이\
    =>handleResize는 함수를 즉시 호출하지 않음\
    =>handleResize()는 함수를 즉시 호출

function handleResize(event) => 어디서 온 event인가!
JS에서 온 event. JS는 이벤트를 다룰 함수를 만들 때 마다, JS는 자동적으로 함수를 객체에 붙인다.
window.addEventListener("resize", handleResize(event));로 event발생할 때 마다 이벤트 객체가 호출됨
따라서, resize 이벤트는 폼을 만들거나 링크 클릭시 유용

한번 클릭시, 색을 파란색으로 변경
<pre><code>
function handleClick()
</code>
</pre>
