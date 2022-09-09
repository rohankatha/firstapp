function fu()
{
  document.getElementById("nav").style.position = "fixed";
}



function func() 
 {
   
     document.getElementById("2").style.color="blue"
 }
 function lunc()
 {
  document.getElementById("2").style.color="red"
 }
 function func1() 
 {
   
     document.getElementById("3").style.color="blue"
 }
 function lunc1()
 {
  document.getElementById("3").style.color="red"
 }function func2() 
 {
   
     document.getElementById("4").style.color="blue"
 }
 function lunc2()
 {
  document.getElementById("4").style.color="red"
 }function func3() 
 {
   
     document.getElementById("5").style.color="blue"
 }
 function lunc3()
 {
  document.getElementById("5").style.color="red"
 }
 var x = 0;
 var array = Array();
 var barray = Array();
 var carray = Array();
 
 function submit()
 {  
 array[x] = document.getElementById("text1").value;
 barray[x] = document.getElementById("text2").value;
 carray[x] = document.getElementById("text3").value;
 x++;
 
 document.getElementById("text1").value = "";
 document.getElementById("text2").value = "";
 document.getElementById("text3").value = "";
  var table = document.getElementById("myTable");
  y=array.length;
   var row = table.insertRow(y);
   var cell1 = row.insertCell(0);
   var cell2 = row.insertCell(1);
   var cell3 = row.insertCell(2);
  
   cell1.innerHTML = array[y-1];
   cell2.innerHTML = barray[y-1];
   cell3.innerHTML = carray[y-1];

    
}
