console.log('開始');


function change3(color, bColor, fontSize)
{
	document.getElementById("blog").style.fontColor=color;
	document.getElementById("blog").style.backgroundColor=bColor;
	document.getElementById("blog").style.fontSize=fontSize;
}

function change2(color, bColor, fontSize)
{
	document.getElementById("trip").style.fontColor=color;	
	document.getElementById("trip").style.backgroundColor=bColor;	document.getElementById("trip").style.fontSize=fontSize;
}

function change(color, bColor, fontSize)
{
	document.getElementById("top").style.fontColor=color;
	document.getElementById("top").style.backgroundColor=bColor;		document.getElementById("top").style.fontSize=fontSize;
}



function set(sObj)
{
	str = sObj.options[sObj.selectedIndex].value;
	document.makingform.action = "mailto:" + str;
}

function action(color)
{
	var chang=document.getElementById("theme2");	
}

		

console.log('終了');
	