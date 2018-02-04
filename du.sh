#!/bin/sh
#global variable which stores the size of the given directory/file as parameter

sizeOfFiles=0

calculateSizeInBytes(){
#check if $1 is director
if [ -d $1 ]
then
#store all files from dir
 files=`ls $1`
 for file in ${files}
 do
   if [ -d $1/$file ]
   then
   #if  $1/$file is dir do the same recursiv
     calculateSizeInBytes $1/$file $2 $3
   else
   #take bytes from file_size
     file_size=`ls $1/$file -l | cut -d ' ' -f 5`
	 #the file will be taken into consideration if its size is at least 1000
	 if [ $file_size -ge $2 ]
     then
	 #put size and name in fisier
      echo -e "\n $file_size: \n">> $3
	  filename="\n $1/$file \n"
      echo -e "$filename"$'\r'>>$3
     fi
	 #calculated size total for dir
	 sizeOfFiles=`expr ${sizeOfFiles} + ${file_size}`
   fi
 done
elif [ -f $1 ]
then
#if file is not a director just take the size
  sizeOfFiles=`ls $1 -l | cut -d ' ' -f 5`
else
 printf "Error: $1 not found\n"
fi
}

rm -f -- $3
#apel function
calculateSizeInBytes $1 $2 $3

echo "Total size of" $1 "is: "
printf $sizeOfFiles
