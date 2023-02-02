#!/bin/bash 



sort="1"
region=""
f_count=0
file=""

op=(-p1 -p2 -p3 -t1 -t2 -t3 -w -h -m)
reg=(-F -G -S -A -O -Q)
sort=(--abr --avl --tab)


reg_count=0
sort_count=0
count=0

f_finder=0

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
  
  
  elif [[ $x == "-f" ]]; then
    # Set the flag if -f option is encountered 
    ((f_count++))
    f_finder=1
    
  
    elif [[ $f_finder -eq 1 ]]; then
      # Check if the next argument after -f is a csv file
      if [[ $x == *.csv ]]; then
        file=$x
        # Reset the flag
        f_finder=0
      else
        echo "Error: Argument after -f is not a csv file"
        exit 1
      fi
    elif [[ $x == "--help" ]]; then
      cat help.txt
      exit 1
  
    else
      echo "Error: Wrong argument"
      exit 1
    
  fi
done


# Check if the -f option was not followed by a csv file
if [[ $f_finder -eq 1 ]]; then
  echo "Error: -f option must be followed by a csv file"
  exit 1
fi

if [[ $f_count -ne 1 ]]; then
  echo "Error: You need exactly one -f option"
  exit 1
fi




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
    -G) region="Guyanefrancaise";;
    -S) region="Spm";;
    -A) region="Antilles";;
    -O) region="Oceanindien";;
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


chmod 755 sender.sh
for x in "${op1_values[@]}"
do
  ./sender.sh $region $x $file
  op1_values=( "${op1_values[@]:1}" )
done





