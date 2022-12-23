#!/bin/bash 




op1=""

while [[ $# -gt 0 ]]
do
  case "$1" in
    -p1) op1="p1";;
    -p2) op1="p2";;
    -p3) op1="p3";;
    -t1) op1="t1";;
    -t2) op1="t2";;
    -t3) op1="t3";;
    -w) op1="wind";;
    -h) op1="height";;
    -m) op1="moisture";;
    -F) region="France";;
    -G) region="Guyane française";;
    -S) region="Saint-Pierre et Miquelon";;
    -A) region="Antilles";;
    -O) region="Océan indien";;
    -Q) region="Antarctique";;
  esac
  shift
done

echo "op1 = $op1"


if [ "$op1" == "wind" ]; then
  param1=4
  param2=5
  param3=20
fi

if [ "$op1" == "height" ]; then
  param1=15
  param2=20
  param3=21
fi

if [ "$op1" == "moisture" ]; then
  param1=6
  param2=20
  param3=21
fi

if [ "$op1" == "p1" || "$op1" == "p2" || "$op1" == "p3" ]; then
  param1=3
  param2=7
  param3=8
fi

if [ "$op1" == "t1" || "$op1" == "t2" || "$op1" == "t3"]; then
  param1=12
  param2=13
  param3=14
fi

# Ocean indien  -22.344167 40.340667 / -15.887667 54.520667 / -17.054667 42.712 / -49.352333 70.243333 / -37.795167 77.569167
# saint pierre et miquelon  46.766333 -56.179167 / 
# antartique  -66.663167 140.001 / 




if [ "$region" == "France" ]; then
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 '$16 < "96000" {print $16 "," $p1 "," $p2 "," $p3}' meteodata.csv > resultat.csv
fi

if [ "$region" == "Guyane française" ]; then
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 '$16 >= 97301 && $16 <= 97362 {print $16 "," $p1 "," $p2 "," $p3}' meteodata.csv > resultat.csv
fi

if [ "$region" == "Saint-Pierre et Miquelon" ]; then
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 '$10 == 46.766333 && $11 == -56.179167 {print $16 "," $p1 "," $p2 "," $p3}' meteodata.csv > resultat.csv
fi

if [ "$region" == "Antilles" ]; then
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 '$16 >= 97201 && $16 <= 97232 {print $16 "," $p1 "," $p2 "," $p3}' meteodata.csv > resultat.csv
fi

if [ "$region" == "Océan indien" ]; then
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 '$10 >= -49.352333 && $10 <= -15.887667 && $11 <= 77.569167 && $11 >= 40.340667 {print $16 "," $p1 "," $p2 "," $p3}' meteodata.csv > resultat.csv
fi

if [ "$region" == "Antartique" ]; then
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 '$16 >= 97501 && $16 <= 97502 {print $16 "," $p1 "," $p2 "," $p3}' meteodata.csv > resultat.csv
fi






echo $region
