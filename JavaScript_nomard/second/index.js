/*HTML의 <head>요소 보여줌*/
const title = document.getElementById("title");
title.innerHTML = "Hi! From JS";
console.log(title);

/*title로 할 수 있는 것*/
const title = document.getElementById("title");
//const title = document.querySelector("#title");
title.innerHTML = "Hi! From JS";
title.style.color="red";
//console.dir(title);
document.title='I own U now';

/*event handlers*/
//window.addEventListener("resize");

/*function handleResize(){
    console.log("I have been resized");
}
function handleResize(event){
    console.log(event);
}*/
function handleClick(){
    title.style.color="blue";
}
//window.addEventListener("resize", handleResize);
//window.addEventListener("resize", handleResize(event));
title.addEventListener("click", handleClick);