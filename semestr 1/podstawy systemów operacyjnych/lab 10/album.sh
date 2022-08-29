#!/bin/bash
#Filename: album.sh
echo "Tworzenie albumu.."
mkdir -p thumbs
cat <<EOF1 > index.html
<html>
<head>
<style>
img
{
margin:4px;
border: 1px solid red;
}
body
{
width:400px;
margin:auto;
border: 1px dashed grey;
padding:10px;
}
</style>
</head>
<body>
<center><h1> #Tytul Albumu </h1></center>
<p>
EOF1
for img in *.jpg;
do
convert "$img" -resize "100x" "thumbs/$img"
echo "<a href=\"$img\" >" >>index.html
echo "<img src=\"thumbs/$img\" title=\"$img\" /></a>" >> index.html
done
cat <<EOF2 >> index.html
</p>
</body>
</html>
EOF2
echo "Album stworzony do pliku index.html"