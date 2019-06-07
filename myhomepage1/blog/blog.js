function change3(color, bColor, fontSize)
{
	document.getElementById("proflie").style.fontColor=color;
	document.getElementById("profile").style.backgroundColor=bColor;
	document.getElementById("profile").style.fontSize=fontSize;
}

function change(color, bColor, fontSize)
{
	document.getElementById("top").style.fontColor=color;
	document.getElementById("top").style.backgroundColor=bColor;		document.getElementById("top").style.fontSize=fontSize;
}

function change2(color, bColor, fontSize)
{
	document.getElementById("trip").style.fontColor=color;
	document.getElementById("trip").style.backgroundColor=bColor;		document.getElementById("trip").style.fontSize=fontSize;
}

var slide = new Array("picture/IMG_2984.jpeg", "picture/IMG_8170.jpeg", "picture/IMG_7691.jpeg", "picture/IMG_7497.jpeg", "picture/IMG_7604.jpeg");

var num = -1;
slideshow_timer();
function slideshow_timer(){
	if (num == slide.length-1){
     	num = 0;
  	 } 
 	 else {
	 num ++;
  	 }
	document.getElementById("slideShow").src=slide[num];	
	 setTimeout("slideshow_timer()",2000); 
   	 }