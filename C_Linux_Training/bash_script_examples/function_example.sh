#!/bin/bash
function F1()
{
	echo "I like bash programming"
}

Rectangle_Area() {
	area=$(($1 * $2))
	echo "Area is: $area"
}

function greeting() {
	str="Hello, $name"
	echo $str
}

F1
Rectangle_Area 15 20
echo "Enter your name:"
read name
val=$(greeting)
echo "Return value of the function is $val"