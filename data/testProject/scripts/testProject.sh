./testProject > tmp.out
DIFF=$(diff tmp.out ../data/testProject.out)
if [ "$DIFF" == "" ] 
then
    printf "Test(testProject)\tpass\n"
else
    printf "Test(testProject)\tfail\n"
    echo ${DIFF}
fi

rm tmp.out
