i=$(pwd)
g++ FangZeYa.c  test.cpp -lgtest -lgtest_main -lpthread -fsanitize=address -fno-omit-frame-pointer -fsanitize-address-use-after-scope -g -D __SA_TEST__ -o test && mv test .. && cd .. && ./test 
cd $i

