function enlarge() {
	var element1 = document.getElementById("homeimg");
	element1.style.height = "20%";
	element1.style.width = "20%";
	element1.style.marginLeft = "3%";
}

function smaller() {
	var element1 = document.getElementById("homeimg");
	element1.style.height = "15%";
	element1.style.width = "15%";
	element1.style.marginLeft = "3%";
}


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

function pop1() {
  	alert("スポーツ観戦：MBL、NBA、プレミアリーグが中心。\n映画鑑賞：filmarksでレビューしてます。\n音楽：一周回って邦楽に落ち着いています。\nWorkout：週3~4のペースで今はジム通い。");
}

function pop3() {
  	alert("2018年8月からカリフォルニアに一年間の留学中");
}

function pop2() {
  	alert("アメリカに来て本格的にプログラミング学習を開始。\n初めに習い始めた言語はC++。\n今現在、javascriptとC++を学習中。");
}

