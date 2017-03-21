ls | head -3
ls | tail -1
ls | wc
echo overwrite > testFile.txt
echo append >> testFile.txt
wc -l < testFile.txt
cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2

ls > testFile.txt
