if [ -d "testProject" ]; then
    rm -rf testProject
fi
./makeCproject -a "A. N. Author" testProject 2>&1 > /dev/null
make -C testProject > /dev/null
if [ $? -eq 0 ]; then
    printf "Test(makeCproject, make)\tpass\n"
else
    printf "Test(makeCproject, make)\tfail\n"
fi

make -s -C testProject doc 2>&1 > /dev/null
if [ $? -eq 0 ]; then
    printf "Test(makeCproject, make doc)\tpass\n"
else
    printf "Test(makeCproject, make doc)\tfail\n"
fi

make -s -C testProject test 2>&1 > /dev/null
if [ $? -eq 0 ]; then
    printf "Test(makeCproject, make test)\tpass\n"
else
    printf "Test(makeCproject, make test)\tfail\n"
fi

rm -rf testProject
