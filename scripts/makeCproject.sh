./makeCproject -a "A. N. Author" testProject 2>&1 > /dev/null
cd testProject
make
if [ $? -eq 0 ]; then
    printf "Test(makeCproject, make)\tpass\n"
else
    printf "Test(makeCproject, make)\tfail\n"
fi

make doc 2>&1 > /dev/null
if [ $? -eq 0 ]; then
    printf "Test(makeCproject, make doc)\tpass\n"
else
    printf "Test(makeCproject, make doc)\tfail\n"
fi

make test 2>&1 > /dev/null
if [ $? -eq 0 ]; then
    printf "Test(makeCproject, make test)\tpass\n"
else
    printf "Test(makeCproject, make test)\tfail\n"
fi

cd ../
rm -rf testProject
