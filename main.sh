#!/bin/bash 

# Initialize op1 variable
op1=""
sort="1"
region=""


# Declare arrays for different types of arguments
op=(-p1 -p2 -p3 -t1 -t2 -t3 -w -h -m)
reg=(-F -G -S -A -O -Q)
sort=(--abr --avl --tab)

# Initialize counters for region and sort arguments
reg_count=0
sort_count=0

op_values=()
for x in "$@"
do
  if [[ " ${op[@]} " =~ " ${x} " ]]; then
    if [[ " ${op_values[@]} " =~ " ${x} " ]]; then
      echo "Error: Duplicate option argument"
      exit 1
    fi
    op_values+=("$x")
  elif [[ " ${reg[@]} " =~ " ${x} " ]]; then
    if (( reg_count >= 1 )); then
      echo "Error: Only one region argument allowed"
      exit 1
    fi
    ((reg_count++))
  elif [[ " ${sort[@]} " =~ " ${x} " ]]; then
    if (( sort_count >= 1 )); then
      echo "Error: Only one sort argument allowed"
      exit 1
    fi
    ((sort_count++))
  else
    echo "Error: Wrong argument"
    exit 1
  fi
done






op1_values=()
while [[ $# -gt 0 ]]
do
  case "$1" in
    # Set op1 variable based on command line argument
    -p1) op1_values+=("p1");;
    -p2) op1_values+=("p2");;
    -p3) op1_values+=("p3");;
    -t1) op1_values+=("t1");;
    -t2) op1_values+=("t2");;
    -t3) op1_values+=("t3");;
    -w) op1_values+=("wind");;
    -h) op1_values+=("height");;
    -m) op1_values+=("moisture");;
    # Set region variable based on command line argument
    -F) region="France";;
    -G) region="Guyane française";;
    -S) region="Saint-Pierre et Miquelon";;
    -A) region="Antilles";;
    -O) region="Océan indien";;
    -Q) region="Antarctique";;
    # Set sort variable based on command line argument
    --avl) sort="1";;
    --abr) sort="2";;    
    --tab) sort="3";;
  esac
  shift
done

# Print op1 variable
echo "op1 = $op1_values"
echo "sort = $sort"


# Set values of param1, param2, and param3 variables based on op1 value
if [ "$op1" == "wind" ]; then
  param1=4
  param2=5
  param3=10
  param4=11
fi

if [ "$op1" == "height" ]; then
  param1=15
  param2=10
  param3=11
  param4=20
fi

if [ "$op1" == "moisture" ]; then
  param1=6
  param2=10
  param3=11
  param4=20
fi

if [ "$op1" == "t1" ]; then
  param1=12
  param2=13
  param3=14
  param4=1
fi

if [ "$op1" == "t2" ]; then
  param1=12
  param2=13
  param3=14
  param4=1
fi

if [ "$op1" == "t3" ]; then
  param1=12
  param2=13
  param3=14
  param4=1
fi

if [ "$op1" == "p1" ]; then
  param1=12
  param2=13
  param3=14
  param4=1
fi

if [ "$op1" == "p2" ]; then
  param1=12
  param2=13
  param3=14
  param4=1
fi

if [ "$op1" == "p3" ]; then
  param1=12
  param2=13
  param3=14
  param4=1
fi






# Ocean indien  -22.344167 40.340667 / -15.887667 54.520667 / -17.054667 42.712 / -49.352333 70.243333 / -37.795167 77.569167
# saint pierre et miquelon  46.766333 -56.179167 / 
# antartique  -66.663167 140.001 / 

# Extract rows from meteodata.csv based on region and param values, and write to results.csv

if [ "$region" == "France" ]; then
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$16 < "96000" {print $2 "," $p1 "," $p2 "," $p3 "," $p4}' meteodata.csv > results.csv
fi


if [ "$region" == "Guyane française" ]; then
  # Extract rows from meteodata.csv for Guyane française
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$16 >= 97301 && $16 <= 97362 {print $2 "," $p1 "," $p2 "," $p3 "," $p4}' meteodata.csv > results.csv
fi

if [ "$region" == "Saint-Pierre et Miquelon" ]; then
  # Extract rows from meteodata.csv for Saint-Pierre et Miquelon
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$10 == 46.766333 && $11 == -56.179167 {print $2 "," $p1 "," $p2 "," $p3 "," $p4}' meteodata.csv > results.csv
fi

if [ "$region" == "Antilles" ]; then
  # Extract rows from meteodata.csv for Antilles
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$16 >= 97201 && $16 <= 97232 {print $2 "," $p1 "," $p2 "," $p3 "," $p4}' meteodata.csv > results.csv
fi

if [ "$region" == "Océan indien" ]; then
  # Extract rows from meteodata.csv for Océan indien
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3 -v p4=$param4 '$10 >= -49.352333 && $10 <= -15.887667 && $11 <= 77.569167 && $11 >= 40.340667 {print $2 "," $p1 "," $p2 "," $p3 "," $p4}' meteodata.csv > results.csv
fi

if [ "$region" == "Antartique" ]; then
  # Extract rows from meteodata.csv for Antartique
  awk -F, -v p1=$param1 -v p2=$param2 -v p3=$param3  -v p4=$param4 '$16 >= 97501 && $16 <= 97502 {print $2 "," $p1 "," $p2 "," $p3 "," $p4}' meteodata.csv > results.csv
fi


./gnup.sh



gcc -o mainc mainc.c
./mainc $sort


echo $region
