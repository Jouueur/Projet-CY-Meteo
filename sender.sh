#!/bin/bash


temp_option=$1
file=$2
sort=$3
region=$4


if [ "$sort" == 1 ]; then
  echo "The sort method: $sort isn't implemented yet :("
  exit 1
elif [ "$sort" == 3 ]; then
  echo "The sort method: $sort isn't implemented yet :("
  exit 1
fi


# Set values of choosed columns based on the option
if [ "$temp_option" == "wind" ]; then
  param1=4
  param2=5
  param3=10
  param4=11
  echo "The $temp_option argument isn't implemented yet :("
  exit 1
elif [ "$temp_option" == "height" ]; then
  param1=1
  param2=15
  param3=10
  param4=11
  echo "The $temp_option argument isn't implemented yet :("
  exit 1
elif [ "$temp_option" == "moisture" ]; then
  param1=1
  param2=6
  param3=10
  param4=11
  echo "The $temp_option argument isn't implemented yet :("
  exit 1
elif [ "$temp_option" == "t1" ]; then
  param1=1  
  param2=12
  param3=13
  param4=14
  temp_option=1
elif [ "$temp_option" == "t2" ]; then
  param1=2
  param2=12
  param3=20
  param4=21
  echo "The $temp_option argument isn't implemented yet :("
  exit 1
elif [ "$temp_option" == "t3" ]; then
  param1=12
  param2=13
  param3=14
  param4=1
  echo "The $temp_option argument isn't implemented yet :("
  exit 1
elif [ "$temp_option" == "p1" ]; then
  param1=1
  param2=7
  param3=3
  param4=8
  temp_option=4
elif [ "$temp_option" == "p2" ]; then
  param1=1
  param2=3
  param3=7
  param4=8
  echo "The $temp_option argument isn't implemented yet :("
  exit 1
elif [ "$temp_option" == "p3" ]; then
  param1=1
  param2=3
  param3=7
  param4=8
  echo "The $temp_option argument isn't implemented yet :("
  exit 1
fi

# Ocean indien  -22.344167 40.340667 / -15.887667 54.520667 / -17.054667 42.712 / -49.352333 70.243333 / -37.795167 77.569167
# saint pierre et miquelon  46.766333 -56.179167 / 
# antartique  -66.663167 140.001 / 

# Extract rows from meteodata.csv based on region and param values, and write to results.csv

if [ "$region" == "France" ]; then
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$16 < "96000" && $16 > "1000" {print $p1 "," $p2 "," $p3 "," $p4}' $file > filtred.csv

elif [ "$region" == "Guyanefrancaise" ]; then
  # Extract rows from meteodata.csv for Guyane française
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$16 >= 97301 && $16 <= 97362 {print $p1 "," $p2 "," $p3 "," $p4}' $file > filtred.csv

elif [ "$region" == "Spm" ]; then
  # Extract rows from meteodata.csv for Saint-Pierre et Miquelon
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$10 == 46.766333 && $11 == -56.179167 {print $p1 "," $p2 "," $p3 "," $p4}' $file > filtred.csv

elif [ "$region" == "Antilles" ]; then
  # Extract rows from meteodata.csv for Antilles
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$16 >= 97201 && $16 <= 97232 {print $p1 "," $p2 "," $p3 "," $p4}' $file > filtred.csv

elif [ "$region" == "Oceanindien" ]; then
  # Extract rows from meteodata.csv for Océan indien
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$10 >= -49.352333 && $10 <= -15.887667 && $11 <= 77.569167 && $11 >= 40.340667 {print $p1 "," $p2 "," $p3 "," $p4}' $file > filtred.csv

elif [ "$region" == "Antartique" ]; then
  # Extract rows from meteodata.csv for Antartique
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3  -v p4=$param4 '$10 == -66.663167 && $11 == 140.001 {print $p1 "," $p2 "," $p3 "," $p4}' $file > filtred.csv

elif [ "$region" == "ALL" ]; then
  # Extract rows from meteodata.csv for everywhere
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3  -v p4=$param4 '{print $p1 "," $p2 "," $p3 "," $p4}' $file > filtred.csv
fi


make
./main-project $sort filtred.csv $temp_option $output_file 









